/*
 * @Description: 字节码（bytecode）模块实现。
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-11 10:55:58
 * @LastEditTime: 2019-04-12 10:05:21
 */
#include <stdlib.h>

#include "chunk.h"
#include "memory.h"
#include "value.h"

void
initChunk(Chunk* chunk) {
    chunk->code = NULL;
    chunk->lines = NULL;
    chunk->count = 0;
    chunk->capacity = 0;
    initValueArray(&chunk->constants);
}

void
freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

/**
 * 在将指令保存在chunk中时要考虑空间可能不够的情况，此时需要采取一定的策
 * 略重新分配足够大小的空间。
 */
void
writeChunk(Chunk* chunk, uint8_t byte, int line) {
    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;

        chunk->capacity = GROW_CAPACITY(oldCapacity);

        /**
         * 因为有可能重新分配内存失败，所以正确的做法是先保存旧的指针，
         * 这里直接对原指针赋值是不可取的。
         */
        chunk->code = GROW_ARRAY(chunk->code, uint8_t,
            oldCapacity, chunk->capacity);
        chunk->lines = GROW_ARRAY(chunk->lines, int,
            oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
}

/**
 * 向chunk中写入一个常量，返回写入前constants中的偏移量，这样调用者就知
 * 道被写入的字节从何处开始。
 */
int
addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);

    return chunk->constants.count - 1;
}