#pragma once
#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
extern int cnt, rootnum; // rootnum是最原始的操作数，cnt是计算次数

extern std::unordered_map<char, std::string> addops, mulops;

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
    std::unique_ptr<BaseAST> mexp, exp;
    char aop;
    void Dump(std::ostringstream &oss) const override
    {
        if (exp == nullptr)
        {
            mexp->Dump(oss);
        }
        else
        {
            int old_mul_cnt = cnt;
            mexp->Dump(oss);
            int new_mul_cnt = cnt;
            int root_mul = rootnum;
            bool mul_done = old_mul_cnt != cnt;

            int old_add_cnt = cnt;
            exp->Dump(oss);
            int new_add_cnt = cnt;
            int root_add = rootnum;
            bool add_done = old_add_cnt != cnt;
            oss << "%" << cnt << " = " << addops[aop] << " ";
            if (!mul_done && !add_done)
            {
                oss << root_mul << ", " << root_add << "\n";
            }
            else if (mul_done && !add_done)
            {
                oss << root_add << ", "
                    << "%" << new_mul_cnt - 1 << "\n";
            }
            else if (add_done && !mul_done)
            {
                oss << root_mul << ", "
                    << "%" << new_add_cnt - 1 << "\n";
            }
            else
                oss << "%" << new_add_cnt - 1 << ", "
                    << "%" << new_mul_cnt - 1 << "\n";
            cnt++;
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

            oss << "%" << cnt << " = " << mulops[mop] << " ";
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
#ifdef DEBUG
        oss << "unaryexp ";
#endif
        if (pexp == nullptr)
        {
            int old_unary_cnt = cnt;
            uexp->Dump(oss);
            bool unary_done = cnt != old_unary_cnt;
#ifdef DEBUG
            oss << "uop " << uop << " and uexp ";
#endif
            oss << "%" << cnt << " = ";
            if (uop == '!')
            {
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
#ifdef DEBUG
        oss << "primaryexp ";
#endif
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