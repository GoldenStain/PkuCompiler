#pragma once
#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cassert>

struct Mytype
{
    int32_t ItsType; // 0表示常量，1表示变量未定义的变量，2表示已经定义的变量
    int32_t ItsValue;
};

typedef std::unordered_map<std::string, Mytype> ident_map;
typedef ident_map *ident_map_t;
typedef valuechart *valuechart_t;

struct valuechart
{
    ident_map chart;
    valuechart_t father;
    int32_t depth = 1;
    valuechart() : father(nullptr) {}
    valuechart_t ident_search(valuechart_t, std::string &ident)
    {
        if(chart.count(ident)) return this;
        if(father == nullptr) return nullptr;
        return ident_search(father, ident);
    }
};

extern int cnt, rootnum; // rootnum是最原始的操作数，cnt是计算次数
extern bool is_const_exp;
extern valuechart_t rootchart, nowchart;

// 两个数字按位或之后的结果和零作比较，就能得到两个数逻辑或的结果，按位与同理

extern std::unordered_map<char, std::string> ops;
extern std::unordered_map<std::string, std::string> doubleops;
extern std::ostringstream oss;

class BaseAST
{
public:
    virtual ~BaseAST() = default;
    virtual void Dump() const {};
    virtual int32_t IntCal() const { return 0x3f3f3f3f; };
    virtual void VoidCal() const {};
};

class CompUnitAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> func_def;
    void Dump() const override
    {
        func_def->Dump();
    }
};

class FuncDefAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> func_type;
    std::string ident;
    std::unique_ptr<BaseAST> block;
    void Dump() const override
    {
        nowchart = rootchart;
        func_type->Dump();
        oss << "@" << ident << "(): ";
        oss << "i32 { " << std::endl;
        oss << "%entry:"
            << "\n";
        block->Dump();
        oss << "}";
    }
};

class FuncTypeAST : public BaseAST
{
public:
    std::string mytype;
    void Dump() const override
    {
        oss << "fun ";
    }
};

class BlockAST : public BaseAST
{
public:
    std::vector<std::unique_ptr<BaseAST>> blockitem;
    void Dump() const override
    {
        for (auto &i : blockitem)
            i->Dump();
    }
};

class BlockItemAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> decl, stmt;
    void Dump() const override
    {
        if (stmt != nullptr)
            stmt->Dump();
        else
            decl->VoidCal();
    }
};

class StmtAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> exp;
    std::unique_ptr<BaseAST> block;
    std::string lval = "null";
    void Dump() const override
    {
        if (block == nullptr)
        {
            if (lval == "null")
            {
                // oss << "ret " << number << std::endl;
                exp->Dump();
                /*if (flag)
                    oss << "ret %" << ();
                else
                    oss << "ret " << rootnum;*/
                if (!cnt)
                    oss << "ret " << rootnum;
                else
                    oss << "ret %" << cnt - 1;
                oss << "\n";
            }
            else
            {
                auto tmp_t = nowchart->ident_search(nowchart, lval);
                if (tmp_t == nullptr)
                {
                    std::cout << "target " << lval << "not found\n";
                    assert(false);
                }
                else
                {
                    auto &tmp = *tmp_t;
                    if (tmp.chart[lval].ItsType == 0)
                    {
                        std::cout << lval << "is not a variable\n";
                        assert(false);
                    }
                    tmp[lval].ItsType = 2; // 更新该常量的状态
                    int old_cnt = cnt;
                    exp->Dump();
                    tmp[lval].ItsValue = exp->IntCal();
                    if (old_cnt != cnt)
                        oss << "store %" << cnt - 1 << ", @" << lval << "_" << tmp.depth << "\n";
                    else
                        oss << "store " << rootnum << ", @" << lval << "_" << tmp.depth << "\n";
                }
            }
        }
        else
        {
            nowchart = new valuechart();
            nowchart->depth = rootchart->depth + 1;
            nowchart->father = rootchart;
            block->Dump();
            delete (nowchart);
            nowchart = rootchart;
        }
    }
};

class ExpAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> lorexp;
    void Dump() const override
    {
        lorexp->Dump();
    }
    int32_t IntCal() const override
    {
        return lorexp->IntCal();
    }
};

class LorExpAST : public BaseAST
{
public:
    void PrintOr(const std::string &a, const std::string &b) const
    {
#ifdef DEBUG
        oss << "YES"
            << "\n";
#endif
        /*oss << "%" << cnt++ << " = "
            << "or " << a << ", " << b << "\n";
        oss << "%" << cnt << " = "
            << "ne "
            << "%" << cnt - 1 << ", 0"
            << "\n";
        cnt++;*/
        oss << "%" << cnt++ << " = "
            << "ne " << a << ", 0\n"; // cnt -> cnt+1
        oss << "%" << cnt++ << " = "
            << "ne " << b << ", 0\n"; // cnt+1 -> cnt+2
        oss << "%" << cnt++ << " = "
            << "or "
            << "%" << cnt - 3 << ", %" << cnt - 2 << "\n"; // cnt+2->cnt+3
    }
    std::unique_ptr<BaseAST> lorexp, landexp;
    void Dump() const override
    {
#ifdef DEBUG
        if (lorexp == nullptr)
            oss << "no"
                << "\n";
        else
            oss << "yes"
                << "\n";
#endif
        if (lorexp == nullptr)
            landexp->Dump();
        else
        {
            int old_and_cnt = cnt;
            landexp->Dump();
            int root_and = rootnum;
            bool and_done = old_and_cnt != cnt;
            int and_cnt = cnt - 1;

            int old_or_cnt = cnt;
            lorexp->Dump();
            int root_or = rootnum;
            bool or_done = old_or_cnt != cnt;
            int or_cnt = cnt - 1;
            std::string or_prd = or_done ? ("%" + std::to_string(or_cnt)) : std::to_string(root_or),
                        and_prd = and_done ? ("%" + std::to_string(and_cnt)) : std::to_string(root_and);
            PrintOr(or_prd, and_prd);
        }
    }
    int32_t IntCal() const override
    {
        if (lorexp == nullptr)
            return landexp->IntCal();
        else
        {
            int32_t rightvalue = landexp->IntCal();
            int32_t leftvalue = lorexp->IntCal();
            return leftvalue || rightvalue;
        }
    }
};

class LandExpAST : public BaseAST
{
public:
    void PrintAnd(const std::string &a, const std::string &b) const
    {
        /*oss << "%" << cnt++ << " = "
            << "and " << a << ", " << b << "\n";
        oss << "%" << cnt << " = "
            << "ne "
            << "%" << cnt - 1 << ", 0"
            << "\n";
        cnt++;*/
        oss << "%" << cnt++ << " = "
            << "ne " << a << ", 0\n"; // cnt -> cnt+1
        oss << "%" << cnt++ << " = "
            << "ne " << b << ", 0\n"; // cnt+1 -> cnt+2
        oss << "%" << cnt++ << " = "
            << "and "
            << "%" << cnt - 3 << ", %" << cnt - 2 << "\n"; // cnt+2->cnt+3
    }
    std::unique_ptr<BaseAST> eqexp, landexp;
    void Dump() const override
    {
#ifdef DEBUG
        oss
            << "yes"
            << "\n";
#endif
        if (landexp == nullptr)
        {
            eqexp->Dump();
        }
        else
        {
            int old_eq_cnt = cnt;
            eqexp->Dump();
            int root_eq = rootnum;
            bool eq_done = old_eq_cnt != cnt;
            int eq_cnt = cnt - 1;

            int old_and_cnt = cnt;
            landexp->Dump();
            int root_and = rootnum;
            bool and_done = old_and_cnt != cnt;
            int and_cnt = cnt - 1;

            std::string eq_prd = eq_done ? ("%" + std::to_string(eq_cnt)) : std::to_string(root_eq),
                        and_prd = and_done ? ("%" + std::to_string(and_cnt)) : std::to_string(root_and);
            PrintAnd(and_prd, eq_prd);
        }
    }
    int32_t IntCal() const override
    {
        if (landexp == nullptr)
        {
            return eqexp->IntCal();
        }
        else
        {
            int32_t rightvalue = eqexp->IntCal();
            int32_t leftvalue = landexp->IntCal();
            return leftvalue && rightvalue;
        }
    }
};

class EqExpAST : public BaseAST
{
public:
    void PrintEq(const std::string &a, const std::string &b, const std::string &c) const
    {
        oss << "%" << cnt++ << " = " << doubleops[c] << " " << a << ", " << b << "\n";
    }
    std::unique_ptr<BaseAST> relexp, eqexp;
    std::string eqop;
    void Dump() const override
    {
#ifdef DEBUG
        oss
            << "yes"
            << "\n";
#endif
        if (eqexp == nullptr)
        {
            relexp->Dump();
        }
        else
        {
            int old_rel_cnt = cnt;
            relexp->Dump();
            int root_rel = rootnum;
            bool rel_done = old_rel_cnt != cnt;
            int rel_cnt = cnt - 1;

            int old_eq_cnt = cnt;
            eqexp->Dump();
            int root_eq = rootnum;
            bool eq_done = old_eq_cnt != cnt;
            int eq_cnt = cnt - 1;

            std::string eq_prd = eq_done ? ("%" + std::to_string(eq_cnt)) : std::to_string(root_eq),
                        rel_prd = rel_done ? ("%" + std::to_string(rel_cnt)) : std::to_string(root_rel);
            PrintEq(eq_prd, rel_prd, eqop);
        }
    }
    int32_t IntCal() const override
    {
        if (eqexp == nullptr)
            return relexp->IntCal();
        int32_t rightvalue = relexp->IntCal(),
                leftvalue = eqexp->IntCal();
        if (eqop == "==")
            return leftvalue == rightvalue;
        return leftvalue != rightvalue;
    }
};

class RelExpAST : public BaseAST
{
public:
    void PrintRel(const std::string &a, const std::string &b, const std::string &c) const
    {
        oss << "%" << cnt++ << " = " << doubleops[c] << " " << a << ", " << b << "\n";
    }
    std::unique_ptr<BaseAST> addexp, relexp;
    std::string relop;
    void Dump() const override
    {
#ifdef DEBUG
        oss
            << "yes"
            << "\n";
#endif
        if (relexp == nullptr)
        {
            addexp->Dump();
        }
        else
        {
            int old_add_cnt = cnt;
            addexp->Dump();
            int root_add = rootnum;
            bool add_done = old_add_cnt != cnt;
            int add_cnt = cnt - 1;

            int old_rel_cnt = cnt;
            relexp->Dump();
            int root_rel = rootnum;
            bool rel_done = old_rel_cnt != cnt;
            int rel_cnt = cnt - 1;

            std::string add_prd = add_done ? ("%" + std::to_string(add_cnt)) : std::to_string(root_add),
                        rel_prd = rel_done ? ("%" + std::to_string(rel_cnt)) : std::to_string(root_rel);
            PrintRel(rel_prd, add_prd, relop);
        }
    }
    int32_t IntCal() const override
    {
        if (relexp == nullptr)
            return addexp->IntCal();
        int32_t rightvalue = addexp->IntCal(),
                leftvalue = relexp->IntCal();
        if (relop == ">")
            return leftvalue > rightvalue;
        if (relop == "<")
            return leftvalue < rightvalue;
        if (relop == ">=")
            return leftvalue >= rightvalue;
        return leftvalue <= rightvalue;
    }
};

class AddExpAST : public BaseAST
{
public:
    mutable int new_mul_cnt, new_add_cnt;
    void PrintAdd(bool &mul_done, bool &add_done, int &root_mul, int &root_add) const
    {
        oss << "%" << cnt << " = " << ops[aop] << " ";
        if (!mul_done && !add_done)
        {
            oss << root_add << ", " << root_mul << "\n";
        }
        else if (mul_done && !add_done)
        {
            oss << root_add << ", "
                << "%" << new_mul_cnt - 1
                << "\n";
        }
        else if (add_done && !mul_done)
        {
            oss << "%" << new_add_cnt - 1 << ", "
                << root_mul << "\n";
        }
        else
            oss << "%" << new_add_cnt - 1 << ", "
                << "%" << new_mul_cnt - 1 << "\n";
        cnt++;
    }
    std::unique_ptr<BaseAST> mexp, aexp;
    char aop;
    void Dump() const override
    {
        if (aexp == nullptr)
        {
            mexp->Dump();
        }
        else
        {
            int old_mul_cnt = cnt;
            mexp->Dump();
            new_mul_cnt = cnt;
            int root_mul = rootnum;
            bool mul_done = old_mul_cnt != cnt;

            int old_add_cnt = cnt;
            aexp->Dump();
            new_add_cnt = cnt;
            int root_add = rootnum;
            bool add_done = old_add_cnt != cnt;
            PrintAdd(mul_done, add_done, root_mul, root_add);
        }
    }
    int32_t IntCal() const override
    {
        if (aexp == nullptr)
            return mexp->IntCal();
        int32_t rightvalue = mexp->IntCal(),
                leftvalue = aexp->IntCal();
        if (aop == '+')
            return leftvalue + rightvalue;
        return leftvalue - rightvalue;
    }
};

class MulExpAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> uexp, mexp;
    char mop;
    void Dump() const override
    {
        if (mexp == nullptr)
        {
            uexp->Dump();
        }
        else
        {
            int old_unary_cnt = cnt;
            uexp->Dump();
            int new_unary_cnt = cnt;
            int root_unary = rootnum;
            bool unary_done = old_unary_cnt != cnt;

            int old_mul_cnt = cnt;
            mexp->Dump();
            int new_mul_cnt = cnt;
            int root_mul = rootnum;
            bool mul_done = old_mul_cnt != cnt;

            oss << "%" << cnt << " = " << ops[mop] << " ";
            if (!mul_done && !unary_done)
            {
                oss << root_mul << ", " << root_unary << "\n";
            }
            else if (mul_done && !unary_done)
            {
                oss << "%" << new_mul_cnt - 1 << ", " << root_unary
                    << "\n";
            }
            else if (unary_done && !mul_done)
            {
                oss << root_mul << ", "
                    << "%" << new_unary_cnt - 1 << "\n";
            }
            else
                oss << "%" << new_mul_cnt - 1 << ", "
                    << "%" << new_unary_cnt - 1 << "\n";
            cnt++;
        }
    }
    int32_t IntCal() const override
    {
        if (mexp == nullptr)
            return uexp->IntCal();
        int32_t rightvalue = uexp->IntCal(),
                leftvalue = mexp->IntCal();
        if (mop == '*')
            return leftvalue * rightvalue;
        if (mop == '/')
            return leftvalue / rightvalue;
        return leftvalue % rightvalue;
    }
};

class UnaryExpAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> pexp;
    char uop;
    std::unique_ptr<BaseAST> uexp;
    void Dump() const override
    {
        if (pexp == nullptr)
        {
            int old_unary_cnt = cnt;
            uexp->Dump();
            bool unary_done = cnt != old_unary_cnt;
            if (uop == '!')
            {
                oss << "%" << cnt << " = ";
                oss << "eq ";
                if (!unary_done)
                    oss << rootnum << ", 0";
                else
                    oss << "%" << cnt - 1 << ", 0";
                oss << "\n";
                cnt++;
            }
            if (uop == '-')
            {
                oss << "%" << cnt << " = ";
                oss << "sub 0, ";
                if (!unary_done)
                    oss << rootnum;
                else
                    oss << "%" << cnt - 1;
                oss << "\n";
                cnt++;
            }
        }
        else
            pexp->Dump();
    }
    int32_t IntCal() const override
    {
        if (uexp == nullptr)
            return pexp->IntCal();
        int32_t rightvalue = uexp->IntCal();
        if (uop == '!')
            return !rightvalue;
        if (uop == '-')
            return -rightvalue;
        return rightvalue;
    }
};

class PrimaryExpAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> exp;
    int num;
    std::string lval = "null";
    void Dump() const override
    {
        if (exp == nullptr)
        {
            if (lval != "null")
            {
                auto tmp_t = nowchart->ident_search(nowchart, lval);
                // 检测该变量是否存在
                if (tmp_t == nullptr)
                {
                    std::cout << "target " << lval << " not found \n";
                    assert(false);
                }
                else
                {
                    auto k = tmp[lval];
                    if (k.ItsType == 1) // 是否已经定义
                    {
                        std::cout << "target " << lval << "not defined \n";
                        assert(false);
                    }
                    else if (is_const_exp && k.ItsType == 2)
                    {
                        std::cout << lval << "is a variavle\n";
                        assert(false);
                    }
                    /*else
                        rootnum = tmp.ItsValue;*/
                    else if (k.ItsType == 0)
                        rootnum = k.ItsValue;
                    else // 是一个变量
                    {
                        oss << "%" << cnt++ << " = "
                            << "load @" << lval << "\n";
                    }
                }
            }
            else
                rootnum = num;
        }
        else
        {
            exp->Dump();
        }
    }
    int32_t IntCal() const override
    {
        if (exp == nullptr)
        {
            if (lval != "null")
            {
                auto &tmp = nowchart->chart;
                // 检测该变量是否存在
                if (!tmp.count(lval))
                {
                    std::cout << "target " << lval << " not found \n";
                    assert(false);
                }
                else
                {
                    auto k = tmp[lval];
                    if (k.ItsType == 1)
                    {
                        std::cout << "target " << lval << "not defined \n";
                        assert(false);
                    }
                    /*else if(tmp.ItsType == 0)
                        return tmp.ItsValue;
                    else
                    {
                        oss << "%" << cnt++ << " = load @" << lval << "\n";
                        return tmp.ItsValue;
                    }*/
                    else
                        return k.ItsValue;
                }
            }
            else
                return num;
        }
        else
        {
            return exp->IntCal();
        }
    }
};

class DeclAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> constdecl;
    std::unique_ptr<BaseAST> vardecl;
    void VoidCal() const override
    {
        if (vardecl == nullptr)
            constdecl->VoidCal();
        else
            vardecl->VoidCal();
    }
};

class VarDclAST : public BaseAST
{
public:
    std::string btype;
    std::vector<std::unique_ptr<BaseAST>> vardef;
    void VoidCal() const override
    {
        for (auto &i : vardef)
            i->VoidCal();
    }
};

class VarDefAST : public BaseAST
{
public:
    std::string ident;
    std::unique_ptr<BaseAST> initval;
    void VoidCal() const override
    {
        auto &tmp = nowchart->chart;
        if (tmp.count(ident))
        {
            std::cout << ident << "mutiple defined\n";
            assert(false);
        }
        oss << "@" << ident << " = alloc i32\n";
        if (initval != nullptr)
        {
            tmp[ident].ItsType = 2;
            tmp[ident].ItsValue = initval->IntCal();
            oss << "store " << tmp[ident].ItsValue << ", @" << ident << "\n";
        }
        else
        {
            tmp[ident].ItsType = 1;
        }
    }
};

class InitValAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> exp;
    int32_t IntCal() const override
    {
        return exp->IntCal();
    }
};

class ConstDeclAST : public BaseAST
{
public:
    std::string btype;
    std::vector<std::unique_ptr<BaseAST>> constdef;
    void VoidCal() const override
    {
        for (auto &i : constdef)
        {
            i->VoidCal();
        }
    }
};

class ConstDefAST : public BaseAST
{
public:
    std::string ident;
    std::unique_ptr<BaseAST> constinitval;
    void VoidCal() const override
    {
        auto &tmp = nowchart->chart;
        if (tmp.count(ident))
        {
            std::cout << ident << "multiple defined\n";
            assert(false);
        }
        tmp[ident].ItsType = 0;
        tmp[ident].ItsValue = constinitval->IntCal();
    }
};

class ConstInitValAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> constexp;
    int32_t IntCal() const override
    {
        return constexp->IntCal();
    }
};

class ConstExpAST : public BaseAST
{
public:
    mutable int32_t tmp;
    std::unique_ptr<BaseAST> exp;
    int32_t IntCal() const override
    {
        is_const_exp = 1;
        tmp = exp->IntCal();
        is_const_exp = 0;
        return tmp;
    }
};