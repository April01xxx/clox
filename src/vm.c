/*
 * @Description: 虚拟机实现模块。
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-12 11:02:08
 * @LastEditTime: 2019-04-12 12:17:01
 */
#include <stdio.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm;      /* 全局只可能有一个虚拟机 */

static void
resetStack() {
    vm.stacktop = vm.stack;
}

void
initVM() {
    resetStack();
}

void
freeVM() {

}

static InterpretResult
run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define BINARY_OP(op) \
    do { \
        double b = pop(); \
        double a = pop(); \
        push(a op b); \
    } while (0)

    for ( ;; ) {
        uint8_t instruction;

#ifdef DEBUG_TRACE_EXECUTION
        printf("          ");
        for (Value* slot = vm.stack; slot < vm.stacktop; ++slot) {
            printf("[");
            printValue(*slot);
            printf("]");
        }
        printf("\n");
        disassembleInstruction(vm.chunk, (int) (vm.ip - vm.chunk->code));
#endif

        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT:
                {
                    Value constant = READ_CONSTANT();
                    push(constant);
                }
                break;
            case OP_ADD:
                BINARY_OP(+);
                break;
            case OP_SUBTRACT:
                BINARY_OP(-);
                break;
            case OP_MULTIPLY:
                BINARY_OP(*);
                break;
            case OP_DIVIDE:
                BINARY_OP(/);
                break;
            case OP_NEGATE:
                push(-pop());
            case OP_RETURN:
                printValue(pop());
                printf("\n");
                return INTERPRET_OK;
        }
    }

#undef READ_BYTE
#undef READ_CONSTANT
}

InterpretResult
interpret(Chunk* chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;

    return run();
}

void
push(Value value) {
    *vm.stacktop = value;
    vm.stacktop++;
}

Value
pop() {
    vm.stacktop--;

    return *vm.stacktop;
}