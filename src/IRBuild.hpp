#pragma once
#include <iostream>
#include <memory>
#include <cstring>
#include <assert.h>
#include "koopa.h"
using namespace std;

std::string reg_names[16] = {"t0", "t1", "t2", "t3", "t4", "t5", "t6",
                             "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "x0"};

int now_using_reg = 0;
bool cal_started = 0;

void Visit(const koopa_raw_program_t &program);
void Visit(const koopa_raw_slice_t &slice);
void Visit(const koopa_raw_function_t &func);
void Visit(const koopa_raw_basic_block_t &bb);
void Visit(const koopa_raw_value_t &value);
void Visit(const koopa_raw_return_t &ret);
void Visit(const koopa_raw_binary_t &bny);
void Visit(const koopa_raw_integer_t &intval);

void koopa_program_process(const char *str)
{
    koopa_program_t program;
    koopa_error_code_t ret = koopa_parse_from_string(str, &program);
    assert(ret == KOOPA_EC_SUCCESS);
    koopa_raw_program_builder_t builder = koopa_new_raw_program_builder();
    koopa_raw_program_t raw = koopa_build_raw_program(builder, program);
    koopa_delete_program(program);
    cout << "   .text"
         << "\n";
    Visit(raw);
}

void Visit(const koopa_raw_program_t &program)
{
    // lv2没有全局变量
    Visit(program.funcs);
}

void Visit(const koopa_raw_slice_t &slice)
{
    for (size_t i = 0; i < slice.len; i++)
    {
        auto ptr = slice.buffer[i];
        switch (slice.kind)
        {
        case KOOPA_RSIK_FUNCTION:
            Visit(reinterpret_cast<koopa_raw_function_t>(ptr));
            break;
        case KOOPA_RSIK_BASIC_BLOCK:
            Visit(reinterpret_cast<koopa_raw_basic_block_t>(ptr));
            break;
        case KOOPA_RSIK_VALUE:
            Visit(reinterpret_cast<koopa_raw_value_t>(ptr));
            break;
        default:
            assert(false);
        }
    }
}

void Visit(const koopa_raw_function_t &func)
{
    cout << "   .globl " << func->name + 1 << "\n";
    cout << func->name + 1 << ":"
         << "\n";
    Visit(func->bbs);
}

void Visit(const koopa_raw_basic_block_t &bb)
{
    Visit(bb->insts);
}

void Visit(const koopa_raw_value_t &value)
{
    const auto &kind = value->kind;
    switch (kind.tag)
    {
    case KOOPA_RVT_RETURN:
        Visit(kind.data.ret);
        break;
    case KOOPA_RVT_INTEGER:
        Visit(kind.data.integer);
        break;
    case KOOPA_RVT_BINARY:
        Visit(kind.data.binary);
        break;
    default:
        assert(false);
    }
}

void Visit(const koopa_raw_return_t &ret)
{
    // 不确定是否正确
    if (reg_names[now_using_reg] != "a0")
        cout << "\tmv\t"
             << "a0, " << reg_names[now_using_reg - 1] << "\n";
    cout << "\tret";
}

void Visit(const koopa_raw_binary_t &bny)
{

    int32_t L = bny.lhs->kind.data.integer.value, R = bny.rhs->kind.data.integer.value;
    switch (bny.op)
    {
    case 1:
        if (!cal_started)
        {
            cout << "\tli\t" << reg_names[now_using_reg] << ", " << L << "\n";
            cal_started = 1;
        }
        cout << "\txor\t" << reg_names[now_using_reg] << ", " << reg_names[now_using_reg] << ", "
             << "x0"
             << "\n";
        cout << "\tseqz\t" << reg_names[now_using_reg] << ", " << reg_names[now_using_reg] << "\n";
        break;
    case 7:
        if (!cal_started)
        {
            cout << "\tli\t" << reg_names[now_using_reg] << ", " << R << "\n";
            cal_started = 1;
        }
        cout << "\tsub\t" << reg_names[now_using_reg] << ", "
             << "x0, " << reg_names[now_using_reg - 1] << "\n";
        break;
    default:
        assert(false);
    }
    now_using_reg = (now_using_reg + 1) % 16;
}

void Visit(const koopa_raw_integer_t &intval)
{
    cout << "\tli\t" << reg_names[now_using_reg] << ", " << intval.value << "\n";
    now_using_reg++;
}
