/*
 * @Description: 执行字节码的虚拟机（virtual machine）。
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-12 10:59:18
 * @LastEditTime: 2019-04-12 11:58:35
 */
#ifndef CLOX_VM_H
#define CLOX_VM_H

#include "chunk.h"

#define STACK_MAX 256

typedef struct {
    Chunk* chunk;
    uint8_t* ip;    /* 指令计数器，指向将要被执行的字节码 */
    Value stack[STACK_MAX];
    Value *stacktop;
} VM;   /* 虚拟机状态机 */

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(Chunk* chunk);
void push(Value value);
Value pop();

#endif  /* CLOX_VM_H */