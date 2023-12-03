%code requires {
  #include <memory>
  #include <string>
  #include "BaseAST.hpp"
}

%{

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "BaseAST.hpp"


// ���� lexer �����ʹ�������
int yylex();
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s);

using namespace std;

%}

// ���� parser �����ʹ��������ĸ��Ӳ���
// ������Ҫ����һ���ַ�����Ϊ AST, �������ǰѸ��Ӳ���������ַ���������ָ��
// ������ɺ�, ����Ҫ�ֶ��޸��������, �������óɽ����õ����ַ���
%parse-param { std::unique_ptr<BaseAST> &ast }

// yylval �Ķ���, ���ǰ����������һ�������� (union)
// ��Ϊ token ��ֵ�е����ַ���ָ��, �е�������
// ֮ǰ������ lexer ���õ��� str_val �� int_val ���������ﱻ�����
// ����ΪʲôҪ���ַ���ָ�����ֱ���� string ���� unique_ptr<string>?
// ������ STFW �� union ��дһ��������������������ʲô���
%union {
  std::string *str_val;
  int int_val;
  BaseAST *ast_val;
  std::vector<std::unique_ptr<BaseAST>> *vec_val;
}

// lexer ���ص����� token ���������
// ע�� IDENT �� INT_CONST �᷵�� token ��ֵ, �ֱ��Ӧ str_val �� int_val
%token RETURN CONST
%token <str_val> IDENT BTYPE
%token <int_val> INT_CONST

// ���ս�������Ͷ���
%type <ast_val> FuncDef FuncType Block Stmt Exp AddExp PrimaryExp UnaryExp MulExp LorExp LandExp EqExp RelExp 
%type <ast_val> Decl ConstDecl ConstDef ConstInitVal ConstExp BlockItem VarDecl VarDef InitVal
%type <int_val> Number
%type <vec_val> ConstDefList BlockItemList VarDefList 

%%

// ��ʼ��, CompUnit ::= FuncDef, �����ź������˽�����ɺ� parser Ҫ��������
// ֮ǰ���Ƕ����� FuncDef �᷵��һ�� str_val, Ҳ�����ַ���ָ��
// �� parser һ�������� CompUnit, ��˵�����е� token ����������, ������������
// ��ʱ����Ӧ�ð� FuncDef ���صĽ���ռ�����, ��Ϊ AST �������� parser �ĺ���
// $1 ָ���������һ�����ŵķ���ֵ, Ҳ���� FuncDef �ķ���ֵ
CompUnit
  : FuncDef {
    auto comp_unit = make_unique<CompUnitAST>();
    comp_unit->func_def = unique_ptr<BaseAST>($1);
    ast = move(comp_unit);
  }
  ;

// FuncDef ::= FuncType IDENT '(' ')' Block;
// �����������ֱ��д '(' �� ')', ��Ϊ֮ǰ�� lexer ���Ѿ������˵����ַ������
// ������ɺ�, ����Щ���ŵĽ���ռ�����, Ȼ��ƴ��һ���µ��ַ���, ��Ϊ�������
// $$ ��ʾ���ս���ķ���ֵ, ���ǿ���ͨ����������Ÿ�ֵ�ķ��������ؽ��
// ����ܻ���, FuncType, IDENT ֮��Ľ���Ѿ����ַ���ָ����
// Ϊʲô��Ҫ�� unique_ptr ��ס����, Ȼ���ٽ�����, ������ƴ����һ���ַ���ָ����
// ��Ϊ���е��ַ���ָ�붼������ new ������, new �������ڴ�һ��Ҫ delete
// ����ᷢ���ڴ�й©, �� unique_ptr ��������ָ������Զ������� delete
// ��Ȼ�˴��㿴������ unique_ptr ���ֶ� delete ������, �������Ƕ����� AST ֮��
// ����д����ʡ�ºܶ��ڴ����ĸ���
FuncDef
  : FuncType IDENT '(' ')' Block {
    auto ast = new FuncDefAST();
    ast->func_type = unique_ptr<BaseAST>($1);
    ast->ident = *unique_ptr<string>($2);
    ast->block = unique_ptr<BaseAST>($5);
    $$ = ast;
  }
  ;

// ͬ��, ���ٽ���
FuncType
  : BTYPE {
    auto ast = new FuncTypeAST();
    ast->mytype = "int";
    $$ = ast;
  }
  ;

Block
  : '{' BlockItemList '}' {
    auto ast = new BlockAST();
    ast->blockitem = move(*($2));
    $$ = ast;
  }
  ;

BlockItemList
 : BlockItem {
  auto v = new vector<unique_ptr<BaseAST>>();
  v->push_back(unique_ptr<BaseAST>($1));
  $$ = move(v);
 } | BlockItemList BlockItem {
  auto v = ($1);
  v->push_back(unique_ptr<BaseAST>($2));
  $$ = move(v);
 } | {
  auto v = new vector<unique_ptr<BaseAST>>();
  $$ = move(v);
 }
 ;

BlockItem
 : Decl {
  auto ast = new BlockItemAST();
  ast->decl = unique_ptr<BaseAST>($1);
  $$ = ast;
 } | Stmt {
  auto ast = new BlockItemAST();
  ast->stmt = unique_ptr<BaseAST>($1);
  $$ = ast;
 } 
 ;

Stmt
  : RETURN Exp ';' {
   auto ast = new StmtAST();
   ast->exp = unique_ptr<BaseAST>($2);
   ast->is_return = 1;
   $$ = ast;
  } | IDENT '=' Exp ';' {
    auto ast = new StmtAST();
    ast->lval = *unique_ptr<string>($1);
    ast->exp = unique_ptr<BaseAST>($3);
    $$ = ast;
  } | Block {
    auto ast = new StmtAST();
    ast->block = unique_ptr<BaseAST>($1);
    $$ = ast;
  } | ';'{
    auto ast = new StmtAST();
    ast->is_empty = 1;
    $$ = ast;
  } | RETURN ';' {
    auto ast = new StmtAST();
    ast->is_return = 1;
    $$ = ast;
  } | Exp ';' {
    auto ast = new StmtAST();
    ast->exp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  ;

UnaryExp
  : PrimaryExp {
    auto ast = new UnaryExpAST();
    ast->pexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  | '+' UnaryExp {
    auto ast = new UnaryExpAST();
    ast->uop = '+';
    ast->uexp = unique_ptr<BaseAST>($2);
    $$ = ast; 
  }
  | '-' UnaryExp {
    auto ast = new UnaryExpAST();
    ast->uop = '-';
    ast->uexp = unique_ptr<BaseAST>($2);
    $$ = ast; 
  }
  | '!' UnaryExp {
    auto ast = new UnaryExpAST();
    ast->uop = '!';
    ast->uexp = unique_ptr<BaseAST>($2);
    $$ = ast; 
  }
  ;

PrimaryExp
  : '(' Exp ')' {
    auto ast = new PrimaryExpAST();
    ast->exp = unique_ptr<BaseAST>($2);
    $$ = ast;
  }
  | Number {
    auto ast = new PrimaryExpAST();
    ast->num = ($1);
    $$ = ast;
  } | IDENT {
    auto ast = new PrimaryExpAST();
    ast->lval = *unique_ptr<string>($1);
    $$ = ast;
  }
  ;


Exp
  : LorExp {
    auto ast = new ExpAST();
    ast->lorexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  ;

MulExp
  : UnaryExp {
    auto ast = new MulExpAST();
    ast->uexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  } | MulExp '*' UnaryExp {
    auto ast = new MulExpAST();
    ast->mexp = unique_ptr<BaseAST>($1);
    ast->mop = '*';
    ast->uexp = unique_ptr<BaseAST>($3);
    $$ = ast;
  } | MulExp '/' UnaryExp {
    auto ast = new MulExpAST();
    ast->mexp = unique_ptr<BaseAST>($1);
    ast->mop = '/';
    ast->uexp = unique_ptr<BaseAST>($3);
    $$ = ast;
  } | MulExp '%' UnaryExp {
    auto ast = new MulExpAST();
    ast->mexp = unique_ptr<BaseAST>($1);
    ast->mop = '%';
    ast->uexp = unique_ptr<BaseAST>($3);
    $$ = ast;
  }
  ;

AddExp
  : MulExp {
    auto ast = new AddExpAST();
    ast->mexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  } | AddExp '+' MulExp {
    auto ast = new AddExpAST();
    ast->aop = '+';
    ast->mexp = unique_ptr<BaseAST>($3);
    ast->aexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  } | AddExp '-' MulExp {
    auto ast = new AddExpAST();
    ast->aop = '-';
    ast->mexp = unique_ptr<BaseAST>($3);
    ast->aexp = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  ;


LorExp
 : LandExp {
  auto ast = new LorExpAST();
  ast->landexp = unique_ptr<BaseAST>($1);
  $$ = ast;
 } | LorExp '|''|' LandExp {
  auto ast = new LorExpAST();
  ast->landexp = unique_ptr<BaseAST>($4);
  ast->lorexp = unique_ptr<BaseAST>($1);
  $$ = ast;
 }
 ;

LandExp
 : EqExp {
  auto ast = new LandExpAST();
  ast->eqexp = unique_ptr<BaseAST>($1);
  $$ = ast;
 } | LandExp '&''&' EqExp {
  auto ast = new LandExpAST();
  ast->eqexp = unique_ptr<BaseAST>($4);
  ast->landexp = unique_ptr<BaseAST>($1);
  $$ = ast;
 }
 ;

 EqExp
 : RelExp {
  auto ast = new EqExpAST();
  ast->relexp = unique_ptr<BaseAST>($1);
  $$ = ast;
 } | EqExp '=''=' RelExp {
  auto ast = new EqExpAST();
  ast->eqop = string("==");
  ast->relexp = unique_ptr<BaseAST>($4);
  ast->eqexp = unique_ptr<BaseAST>($1);
  $$ = ast;
 } | EqExp '!''=' RelExp {
  auto ast = new EqExpAST();
  ast->eqop = string("!=");
  ast->relexp = unique_ptr<BaseAST>($4);
  ast->eqexp = unique_ptr<BaseAST>($1);
  $$ = ast;
 }
 ;


RelExp 
 : AddExp {
  auto ast = new RelExpAST();
  ast->addexp = unique_ptr<BaseAST>($1);
  $$ = ast;
 } | RelExp '>' AddExp {
  auto ast = new RelExpAST();
  ast->addexp = unique_ptr<BaseAST>($3);
  ast->relexp = unique_ptr<BaseAST>($1);
  ast->relop = string(">");
  $$ = ast;
 } | RelExp '<' AddExp {
  auto ast = new RelExpAST();
  ast->addexp = unique_ptr<BaseAST>($3);
  ast->relexp = unique_ptr<BaseAST>($1);
  ast->relop = string("<");
  $$ = ast;
 } | RelExp '>''=' AddExp {
  auto ast = new RelExpAST();
  ast->addexp = unique_ptr<BaseAST>($4);
  ast->relexp = unique_ptr<BaseAST>($1);
  ast->relop = string(">=");
  $$ = ast;
 } | RelExp '<''=' AddExp {
  auto ast = new RelExpAST();
  ast->addexp = unique_ptr<BaseAST>($4);
  ast->relexp = unique_ptr<BaseAST>($1);
  ast->relop = string("<=");
  $$ = ast;
 }
 ;

Number
  : INT_CONST {
   int num;
   num = ($1);
   $$ = num;
  }
  ;

Decl 
  : ConstDecl {
    auto ast = new DeclAST();
    ast->constdecl = unique_ptr<BaseAST>($1);
    $$ = ast;
  } | VarDecl {
    auto ast = new DeclAST();
    ast->vardecl = unique_ptr<BaseAST>($1);
    $$ = ast;
  }
  ;
 VarDecl 
  : BTYPE VarDefList ';' {
    auto ast = new VarDclAST();
    ast->btype = "int";
    auto v_ptr = ($2);
    ast->vardef = move(*v_ptr);
    $$ = ast;
  }
  ;

VarDefList
  : VarDef {
    auto v = new vector<unique_ptr<BaseAST>>();
    v->push_back(unique_ptr<BaseAST>($1));
    $$ = move(v);
  } | VarDefList ',' VarDef {
    auto v = ($1);
    v->push_back(unique_ptr<BaseAST>($3));
    $$ = move(v);
  }
  ;

VarDef 
  : IDENT {
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>($1);
    $$ = ast;
  } | IDENT '=' InitVal {
    auto ast = new VarDefAST();
    ast->ident = *unique_ptr<string>($1);
    ast->initval = unique_ptr<BaseAST>($3);
    $$ = ast;
  }
  ;

InitVal 
 : Exp {
  auto ast = new InitValAST();
  ast->exp = unique_ptr<BaseAST>($1);
  $$ = ast;
 }
 ;

ConstDecl
  : CONST BTYPE ConstDefList ';' {
    auto ast = new ConstDeclAST();
    ast->btype = "int";
    auto v_ptr = ($3);
    ast->constdef = move(*v_ptr);
    $$ = ast;
  }
  ;

  ConstDefList
   : ConstDef {
    auto v = new vector<unique_ptr<BaseAST>>();
    v->push_back(unique_ptr<BaseAST>($1));
    $$ = move(v);
   } | ConstDefList ',' ConstDef {
    auto v = ($1);
    v->push_back(unique_ptr<BaseAST>($3));
    $$ = move(v);
   }
   ;

   ConstDef 
    : IDENT '=' ConstInitVal {
      auto ast = new ConstDefAST();
      ast->ident = *unique_ptr<string>($1);
      ast->constinitval = unique_ptr<BaseAST>($3);
      $$ = ast;
    }
    ;

   ConstInitVal
    : ConstExp {
      auto ast = new ConstInitValAST();
      ast->constexp = unique_ptr<BaseAST>($1);
      $$ = ast;
    }
    ;

  ConstExp 
   : Exp {
    auto ast = new ConstExpAST();
    ast->exp = unique_ptr<BaseAST>($1);
    $$ = ast;
   }
   ;
  
%%

// �����������, ���еڶ��������Ǵ�����Ϣ
// parser ����������� (��������ĳ���������﷨����), �ͻ�����������
void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  cerr << "error: " << s << endl;
}