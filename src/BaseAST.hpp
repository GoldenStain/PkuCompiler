#pragma once
#include <iostream>
#include <memory>

class BaseAST
{
public:
    virtual ~BaseAST() = default;
    virtual void Dump() const = 0;
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
       func_type->Dump();
       std::cout << "@" << ident << "(): ";
       std::cout << "i32 { " << std::endl;
       block->Dump();
       std::cout << "}";
    }
};

class FuncTypeAST : public BaseAST
{
public:
    std:: string mytype;
    void Dump() const override
    {
        std::cout << "fun ";
    }
};

class BlockAST : public BaseAST
{
public:
    std:: unique_ptr<BaseAST> stmt;
    void Dump() const override 
    {
        std::cout << "%entry:" << std::endl;
        stmt->Dump(); 
    }
};

class StmtAST : public BaseAST
{
public:
    int number;
    void Dump() const override 
    {
        std::cout << "ret " << number << std::endl;
    }
};

