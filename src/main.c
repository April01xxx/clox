/*
 * @Description:
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-11 10:14:23
 * @LastEditTime: 2019-04-12 14:39:20
 */

#include "common.h"
#include "chunk.h"
#include "value.h"
#include "vm.h"
#include "debug.h"

int
main(int argc, const char *argv[])
{
    Chunk chunk;
    int constant;   /* 用来记录常量在ValueArray中的偏移量 */

    /* 初始化虚拟机 */
    initVM();

    initChunk(&chunk);
    constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_ADD, 123);

    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_DIVIDE, 123);

    writeChunk(&chunk, OP_NEGATE, 123);

    writeChunk(&chunk, OP_RETURN, 123);
    disassembleChunk(&chunk, "test chunk");

    /* 执行字节码 */
    interpret(&chunk);

    freeVM();
    freeChunk(&chunk);

    return 0;
}