/*
 * @Description: 调试模块实现。
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-11 11:41:20
 * @LastEditTime: 2019-04-12 14:35:49
 */
#include <stdio.h>

#include "debug.h"
#include "value.h"

void
disassembleChunk(Chunk* chunk, const char* name) {
    int offset = 0;

    printf("== %s ==\n", name);
    while (offset < chunk->count)
        offset = disassembleInstruction(chunk, offset);
}

static int
simpleInstruction(const char* name, int offset) {
    printf("%s\n", name);

    return offset + 1;
}

static int
constantInstruction(const char* name, Chunk* chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];

    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");

    return offset + 2;
}

/**
 * @description: 解释当前偏移量offset指向的指令并返回下一个指令的偏移量。
 * @param chunk 保存所有字节码的指令集
 * @param offset 偏移量
 * @return:
 */
int
disassembleInstruction(Chunk* chunk, int offset) {
    uint8_t instruction = chunk->code[offset];

    printf("%04d ", offset);
    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1])
        printf("   | ");
    else
        printf("%4d ", chunk->lines[offset]);

    switch (instruction) {
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        case OP_ADD:
            return simpleInstruction("OP_ADD", offset);
        case OP_SUBTRACT:
            return simpleInstruction("OP_SUBTRACT", offset);
        case OP_MULTIPLY:
            return simpleInstruction("OP_MULTIPLY", offset);
        case OP_DIVIDE:
            return simpleInstruction("OP_DIVIDE", offset);
        case OP_NEGATE:
            return simpleInstruction("OP_NEGATE", offset);
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}