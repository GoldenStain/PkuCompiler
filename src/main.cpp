#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include "BaseAST.hpp"
#include "IRBuild.hpp"
using namespace std;

// ���� lexer ������, �Լ� parser ����
// Ϊʲô������ sysy.tab.hpp ��? ��Ϊ��������û�� yyin �Ķ���
// ���, ��Ϊ����ļ����������Լ�д��, ���Ǳ� Bison ���ɳ�����
// ��Ĵ���༭��/IDE �ܿ����Ҳ�������ļ�, Ȼ�����㱨�� (��Ȼ���벻�����)
// ��������ܷ���, ���Ǹɴ�������ֿ����� dirty ��ʵ�ʺ���Ч���ֶ�
extern FILE *yyin;
extern int yyparse(unique_ptr<BaseAST> &ast);
int cnt, rootnum;
int function_memory, moffset;
bool is_const_exp;

unordered_map<char, string> ops;
unordered_map<string, string> doubleops;
unordered_map<koopa_raw_value_t, int> memories;
valuechart_t rootchart, nowchart;

ostringstream oss;

int main(int argc, const char *argv[])
{
  ops['+'] = "add";
  ops['-'] = "sub";
  ops['*'] = "mul";
  ops['/'] = "div";
  ops['%'] = "mod";
  doubleops["=="] = "eq";
  doubleops["!="] = "ne";
  doubleops[">"] = "gt";
  doubleops["<"] = "lt";
  doubleops[">="] = "ge";
  doubleops["<="] = "le";
  //  ���������в���. ���Խű�/����ƽ̨Ҫ����ı������ܽ������²���:
  //  compiler ģʽ �����ļ� -o ����ļ�
  assert(argc == 5);
  auto mode = argv[1];
  auto input = argv[2];
  auto output = argv[4];

  // �������ļ�, ����ָ�� lexer �ڽ�����ʱ���ȡ����ļ�
  yyin = fopen(input, "r");
  assert(yyin);

  // ���� parser ����, parser �������һ������ lexer ���������ļ���
  unique_ptr<BaseAST> ast;
  auto ret = yyparse(ast);
  assert(!ret);
  ast->Dump();
  string Mystr = oss.str();
  if (!strcmp(mode, "-riscv"))
  {
    freopen(output, "w", stdout);
    const char *myStr = Mystr.c_str();
    koopa_program_process(myStr);
  }
  else if (!strcmp(mode, "-koopa"))
  {
    freopen(output, "w", stdout);
    cout << Mystr;
  }
  else
  {
    cout << "unspecified type" << endl;
    assert(false);
  }
  // ��������õ��� AST, ��ʵ���Ǹ��ַ���
  return 0;
}