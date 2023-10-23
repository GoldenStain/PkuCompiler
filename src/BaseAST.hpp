#pragma once
#include <iostream>
#include <memory>
#include <sstream>

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
    std:: string mytype;
    void Dump(std::ostringstream &oss) const override
    {
        oss << "fun ";
    }
};

class BlockAST : public BaseAST
{
public:
    std:: unique_ptr<BaseAST> stmt;
    void Dump(std::ostringstream &oss) const override 
    {
        oss << "%entry:" << std::endl;
        stmt->Dump(oss); 
    }
};

class StmtAST : public BaseAST
{
public:
    int number;
    void Dump(std::ostringstream &oss) const override 
    {
        oss << "ret " << number << std::endl;
    }
};