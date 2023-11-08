#pragma once
#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <string>
extern int cnt, rootnum; // rootnum是最原始的操作数，cnt是计算次数
// 两个数字按位或之后的结果和零作比较，就能得到两个数逻辑或的结果，按位与同理

extern std::unordered_map<char, std::string> ops;
extern std::unordered_map<std::string, std::string> doubleops;

class BaseAST
{
public:
    virtual ~BaseAST() = default;
    virtual void Dump(std::ostringstream &oss) const = 0;
};

class CompUnitAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> func_def;
    void Dump(std::ostringstream &oss) const override
    {
        func_def->Dump(oss);
    }
};

class FuncDefAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> func_type;
    std::string ident;
    std::unique_ptr<BaseAST> block;
    void Dump(std::ostringstream &oss) const override
    {
        func_type->Dump(oss);
        oss << "@" << ident << "(): ";
        oss << "i32 { " << std::endl;
        block->Dump(oss);
        oss << "}";
    }
};

class FuncTypeAST : public BaseAST
{
public:
    std::string mytype;
    void Dump(std::ostringstream &oss) const override
    {
        oss << "fun ";
    }
};

class BlockAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> stmt;
    void Dump(std::ostringstream &oss) const override
    {
        oss << "%entry:" << std::endl;
        stmt->Dump(oss);
    }
};

class StmtAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> exp;
    void Dump(std::ostringstream &oss) const override
    {
        // oss << "ret " << number << std::endl;
        exp->Dump(oss);
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
};

class ExpAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> lorexp;
    void Dump(std::ostringstream &oss) const override
    {
        lorexp->Dump(oss);
    }
};

class LorExpAST : public BaseAST
{
public:
    void PrintOr(const std::string &a, const std::string &b, std::ostringstream &oss) const
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
        oss << "%" << cnt++ << " = " << "ne " << a << ", 0\n" ; //cnt -> cnt+1
        oss << "%" << cnt++ << " = " << "ne " << b << ", 0\n" ; // cnt+1 -> cnt+2
        oss << "%" << cnt++ << " = " << "or " << "%" << cnt - 3 << ", %" << cnt - 2 << "\n"; //cnt+2->cnt+3
    }
    std::unique_ptr<BaseAST> lorexp, landexp;
    void Dump(std::ostringstream &oss) const override
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
            landexp->Dump(oss);
        else
        {
            int old_and_cnt = cnt;
            landexp->Dump(oss);
            int root_and = rootnum;
            bool and_done = old_and_cnt != cnt;
            int and_cnt = cnt - 1;

            int old_or_cnt = cnt;
            lorexp->Dump(oss);
            int root_or = rootnum;
            bool or_done = old_or_cnt != cnt;
            int or_cnt = cnt - 1;
            std::string or_prd = or_done ? ("%" + std::to_string(or_cnt)) : std::to_string(root_or),
                        and_prd = and_done ? ("%" + std::to_string(and_cnt)) : std::to_string(root_and);
            PrintOr(or_prd, and_prd, oss);
        }
    }
};

class LandExpAST : public BaseAST
{
public:
    void PrintAnd(const std::string &a, const std::string &b, std::ostringstream &oss) const
    {
        /*oss << "%" << cnt++ << " = "
            << "and " << a << ", " << b << "\n";
        oss << "%" << cnt << " = "
            << "ne "
            << "%" << cnt - 1 << ", 0"
            << "\n";
        cnt++;*/
        oss << "%" << cnt++ << " = " << "ne " << a << ", 0\n" ; //cnt -> cnt+1
        oss << "%" << cnt++ << " = " << "ne " << b << ", 0\n" ; // cnt+1 -> cnt+2
        oss << "%" << cnt++ << " = " << "and " << "%" << cnt - 3 << ", %" << cnt - 2 << "\n"; //cnt+2->cnt+3
    }
    std::unique_ptr<BaseAST> eqexp, landexp;
    void Dump(std::ostringstream &oss) const override
    {
#ifdef DEBUG
        oss
            << "yes"
            << "\n";
#endif
        if (landexp == nullptr)
        {
            eqexp->Dump(oss);
        }
        else
        {
            int old_eq_cnt = cnt;
            eqexp->Dump(oss);
            int root_eq = rootnum;
            bool eq_done = old_eq_cnt != cnt;
            int eq_cnt = cnt - 1;

            int old_and_cnt = cnt;
            landexp->Dump(oss);
            int root_and = rootnum;
            bool and_done = old_and_cnt != cnt;
            int and_cnt = cnt - 1;

            std::string eq_prd = eq_done ? ("%" + std::to_string(eq_cnt)) : std::to_string(root_eq),
                        and_prd = and_done ? ("%" + std::to_string(and_cnt)) : std::to_string(root_and);
            PrintAnd(and_prd, eq_prd, oss);
        }
    }
};

class EqExpAST : public BaseAST
{
public:
    void PrintEq(const std::string &a, const std::string &b, const std::string &c, std::ostringstream &oss) const
    {
        oss << "%" << cnt++ << " = " << doubleops[c] << " " << a << ", " << b << "\n";
    }
    std::unique_ptr<BaseAST> relexp, eqexp;
    std::string eqop;
    void Dump(std::ostringstream &oss) const override
    {
#ifdef DEBUG
        oss
            << "yes"
            << "\n";
#endif
        if (eqexp == nullptr)
        {
            relexp->Dump(oss);
        }
        else
        {
            int old_rel_cnt = cnt;
            relexp->Dump(oss);
            int root_rel = rootnum;
            bool rel_done = old_rel_cnt != cnt;
            int rel_cnt = cnt - 1;

            int old_eq_cnt = cnt;
            eqexp->Dump(oss);
            int root_eq = rootnum;
            bool eq_done = old_eq_cnt != cnt;
            int eq_cnt = cnt - 1;

            std::string eq_prd = eq_done ? ("%" + std::to_string(eq_cnt)) : std::to_string(root_eq),
                        rel_prd = rel_done ? ("%" + std::to_string(rel_cnt)) : std::to_string(root_rel);
            PrintEq(eq_prd, rel_prd, eqop, oss);
        }
    }
};

class RelExpAST : public BaseAST
{
public:
    void PrintRel(const std::string &a, const std::string &b, const std::string &c, std::ostringstream &oss) const
    {
        oss << "%" << cnt++ << " = " << doubleops[c] << " " << a << ", " << b << "\n";
    }
    std::unique_ptr<BaseAST> addexp, relexp;
    std::string relop;
    void Dump(std::ostringstream &oss) const override
    {
#ifdef DEBUG
        oss
            << "yes"
            << "\n";
#endif
        if (relexp == nullptr)
        {
            addexp->Dump(oss);
        }
        else
        {
            int old_add_cnt = cnt;
            addexp->Dump(oss);
            int root_add = rootnum;
            bool add_done = old_add_cnt != cnt;
            int add_cnt = cnt - 1;

            int old_rel_cnt = cnt;
            relexp->Dump(oss);
            int root_rel = rootnum;
            bool rel_done = old_rel_cnt != cnt;
            int rel_cnt = cnt - 1;

            std::string add_prd = add_done ? ("%" + std::to_string(add_cnt)) : std::to_string(root_add),
                        rel_prd = rel_done ? ("%" + std::to_string(rel_cnt)) : std::to_string(root_rel);
            PrintRel(rel_prd, add_prd, relop, oss);
        }
    }
};

class AddExpAST : public BaseAST
{
public:
    mutable int new_mul_cnt, new_add_cnt;
    void PrintAdd(bool &mul_done, bool &add_done, int &root_mul, int &root_add, std::ostringstream &oss) const
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
    void Dump(std::ostringstream &oss) const override
    {
        if (aexp == nullptr)
        {
            mexp->Dump(oss);
        }
        else
        {
            int old_mul_cnt = cnt;
            mexp->Dump(oss);
            new_mul_cnt = cnt;
            int root_mul = rootnum;
            bool mul_done = old_mul_cnt != cnt;

            int old_add_cnt = cnt;
            aexp->Dump(oss);
            new_add_cnt = cnt;
            int root_add = rootnum;
            bool add_done = old_add_cnt != cnt;
            PrintAdd(mul_done, add_done, root_mul, root_add, oss);
        }
    }
};

class MulExpAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> uexp, mexp;
    char mop;
    void Dump(std::ostringstream &oss) const override
    {
        if (mexp == nullptr)
        {
            uexp->Dump(oss);
        }
        else
        {
            int old_unary_cnt = cnt;
            uexp->Dump(oss);
            int new_unary_cnt = cnt;
            int root_unary = rootnum;
            bool unary_done = old_unary_cnt != cnt;

            int old_mul_cnt = cnt;
            mexp->Dump(oss);
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
                oss << root_unary << ", "
                    << "%" << new_mul_cnt - 1 << "\n";
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
};

class UnaryExpAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> pexp;
    char uop;
    std::unique_ptr<BaseAST> uexp;
    void Dump(std::ostringstream &oss) const override
    {
        if (pexp == nullptr)
        {
            int old_unary_cnt = cnt;
            uexp->Dump(oss);
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
            pexp->Dump(oss);
    }
};

class PrimaryExpAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> exp;
    int num;
    void Dump(std::ostringstream &oss) const override
    {
        if (exp == nullptr)
        {
            rootnum = num;
        }
        else
        {
            exp->Dump(oss);
        }
    }
};