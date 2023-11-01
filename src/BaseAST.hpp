#pragma once
#include <iostream>
#include <memory>
#include <sstream>
extern int cnt, rootnum; // rootnum是最原始的操作数
extern bool flag;

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
        if (flag)
            oss << "ret %" << cnt - 1;
        else
            oss << "ret " << rootnum;
    }
};

class ExpAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> uexp;
    void Dump(std::ostringstream &oss) const override
    {
#ifdef DEBUG
        oss << "exp ";
#endif
        uexp->Dump(oss);
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
            flag = 1;
            uexp->Dump(oss);
#ifdef DEBUG
            oss << "uop " << uop << " and uexp ";
#endif

            if (uop == '!')
            {
                oss << "%" << cnt << " = ";
                oss << "eq ";
                if (!cnt)
                    oss << rootnum << ", 0";
                else
                    oss << "%" << cnt - 1 << ", 0";
                oss << "\n";
            }
            if (uop == '-')
            {
                oss << "%" << cnt << " = ";
                oss << "sub 0, ";
                if (!cnt)
                    oss << rootnum;
                else
                    oss << "%" << cnt;
                oss << "\n";
            }

            cnt++;
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