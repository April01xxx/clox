/*
 * @Description: 内存管理模块实现。
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-11 11:19:52
 * @LastEditTime: 2019-04-11 11:27:18
 */
#include <stdlib.h>

#include "common.h"
#include "memory.h"

/**
 * @description: chunk内存管理。
 * @param size_t oldSize 旧内存大小
 * @param size_t newSize 新的内存大小
 * @return:
 *
 * 该函数的行为取决于oldSize和newSize两个参数的具体值：
 * 1. oldSize == 0 && newSize > 0: 分配内存；
 * 2. oldSize > 0 && newSize == 0: 释放内存；
 * 3. oldSize > 0 && oldSize < newSize: 重新分配更大的内存；
 * 4. newSize > 0 && newSize < oldSize: 缩小内存；
 */
void*
reallocate(void* previous, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free(previous);
        return NULL;
    }

    return realloc(previous, newSize);
}