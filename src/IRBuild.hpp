#pragma once
#include <iostream>
#include <memory>
#include <cstring>
#include <assert.h>
#include <unordered_map>
#include "koopa.h"
using namespace std;
typedef unsigned long long ull;

std::string reg_names[15] = {"t0", "t1", "t2", "t3", "t4", "t5", "t6",
                             "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7"};

std::unordered_map<ull, int> registers;

int now_using_reg = 0;
bool is_single_num = 1;

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
    if (is_single_num)
    {
        Visit(ret.value);
        cout << "\tret";
    }
    else
    {
        if (reg_names[now_using_reg - 1] != "a0")
            cout << "\tmv\t"
                 << "a0, " << reg_names[now_using_reg - 1] << "\n";
        cout << "\tret";
    }
}

void get_both(const koopa_raw_value_t &L, const koopa_raw_value_t &R, int &l_reg_idx, int &r_reg_idx)
{
    const koopa_raw_binary_t *ptr = &L->kind.data.binary;
    if (L->kind.tag == 0) // 是整数
    {
        if (L->kind.data.integer.value == 0)
            l_reg_idx = -1;
        else
        {
            cout << "\tli\t" << reg_names[now_using_reg++] << ", " << L->kind.data.integer.value << "\n";
            l_reg_idx = now_using_reg - 1;
        }
    }
    else
        l_reg_idx = registers[(ull)ptr];
    ptr = &R->kind.data.binary;
    if (R->kind.tag == 0)
    {
        if (R->kind.data.integer.value == 0)
            r_reg_idx = -1;
        else
        {
            cout << "\tli\t" << reg_names[now_using_reg++] << ", " << R->kind.data.integer.value << "\n";
            r_reg_idx = now_using_reg - 1;
        }
    }

    else
        r_reg_idx = registers[(ull)ptr];
}

void CalPrint(const int &l, const int &r)
{
    string lr = (l == -1) ? "x0" : reg_names[l];
    string rr = (r == -1) ? "x0" : reg_names[r];
    cout << lr << ", " << rr << "\n";
}

void Visit(const koopa_raw_binary_t &bny)
{
    is_single_num = 0;
    koopa_raw_value_t L = bny.lhs, R = bny.rhs;
    int l_reg_idx, r_reg_idx;
    switch (bny.op)
    {
    case KOOPA_RBO_EQ:
        get_both(L, R, l_reg_idx, r_reg_idx);
        cout << "\txor\t" << reg_names[now_using_reg - 1] << ", ";
        CalPrint(l_reg_idx, r_reg_idx);
        cout << "\tseqz\t" << reg_names[now_using_reg - 1] << ", " << reg_names[now_using_reg - 1] << "\n";
        // 运算完之后不用++，这里是直接覆盖，而不是再开一个新寄存器
        break;
    case KOOPA_RBO_SUB:
        get_both(L, R, l_reg_idx, r_reg_idx);
        cout << "\tsub\t" << reg_names[now_using_reg - 1] << ", ";
        CalPrint(l_reg_idx, r_reg_idx);
        break;
    case KOOPA_RBO_ADD:
        get_both(L, R, l_reg_idx, r_reg_idx);
        cout << "\tadd\t" << reg_names[now_using_reg - 1] << ", ";
        CalPrint(l_reg_idx, r_reg_idx);
        break;
    case KOOPA_RBO_MUL:
        get_both(L, R, l_reg_idx, r_reg_idx);
        cout << "\tmul\t" << reg_names[now_using_reg - 1] << ", ";
        CalPrint(l_reg_idx, r_reg_idx);
        break;
    case KOOPA_RBO_DIV:
        get_both(L, R, l_reg_idx, r_reg_idx);
        cout << "\tdiv\t" << reg_names[now_using_reg - 1] << ", ";
        CalPrint(l_reg_idx, r_reg_idx);
        break;
    case KOOPA_RBO_MOD:
        get_both(L, R, l_reg_idx, r_reg_idx);
        cout << "\tmod\t" << reg_names[now_using_reg - 1] << ", ";
        CalPrint(l_reg_idx, r_reg_idx);
        break;
    default:
        assert(false);
    }
    const koopa_raw_binary_t *ptr = &bny;
    registers[(ull)ptr] = now_using_reg - 1;
}

void Visit(const koopa_raw_integer_t &intval)
{
    cout << "\tli\t" << reg_names[now_using_reg] << ", " << intval.value << "\n";
    now_using_reg++;
}
