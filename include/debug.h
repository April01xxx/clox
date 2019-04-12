/*
 * @Description: debug模块
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-11 11:38:26
 * @LastEditTime: 2019-04-11 11:40:13
 */
#ifndef CLOX_DEBUG_H
#define CLOX_DEBUG_H

#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif  /* CLOX_DEBUG_H */