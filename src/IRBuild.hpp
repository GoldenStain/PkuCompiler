#pragma once
#include <iostream>
#include <memory>
#include <cstring>
#include <assert.h>
#include "koopa.h"
using namespace std;

void Visit(const koopa_raw_program_t &program);
void Visit(const koopa_raw_slice_t &slice);
void Visit(const koopa_raw_function_t &func);
void Visit(const koopa_raw_basic_block_t &bb);
void Visit(const koopa_raw_value_t &value);
void Visit(const koopa_raw_return_t &ret);

void koopa_program_process(const char *str)
{
    koopa_program_t program;
    koopa_error_code_t ret = koopa_parse_from_string(str, &program);
    assert(ret == KOOPA_EC_SUCCESS);
    koopa_raw_program_builder_t builder = koopa_new_raw_program_builder();
    koopa_raw_program_t raw = koopa_build_raw_program(builder, program);
    koopa_delete_program(program);
    cout << "   .text" << endl;
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
    cout << "   .globl " << func->name + 1 << endl;
    cout << func->name + 1 << ":" << endl;
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
    //lv2暂时没有
        //Visit(kind.data.integer);
        break;
    default:
        assert(false);
    }
}

void Visit(const koopa_raw_return_t &ret)
{
    koopa_raw_value_t val = ret.value;
    assert(val->kind.tag == KOOPA_RVT_INTEGER);
    cout << "   li a0, " << val->kind.data.integer.value << endl;
    cout << "   ret" << endl;
}
