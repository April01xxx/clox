/*
 * @Description: 字节码（bytecode）模块。
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-11 10:42:15
 * @LastEditTime: 2019-04-12 12:14:03
 */

#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"
#include "value.h"

/**
 * 定义字节码操作类型，目前每条字节码指令的长度是一个字节。
 */
typedef enum {
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,
} OpCode;

/**
 * 字节码是一系列指令的合集，既然有指令，那就有操作对象，我们将所有这些
 * 都放在一个结构体中。
 */
typedef struct {
    uint8_t* code;
    int *lines; /* 每个字节码对应源码的行数 */
    int count;  /* 字节码实际长度 */
    int capacity;   /* 最大允许字节码长度 */

    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif  /* CLOX_CHUNK_H */