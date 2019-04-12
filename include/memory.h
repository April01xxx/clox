/*
 * @Description: 内存管理模块。
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-11 11:08:51
 * @LastEditTime: 2019-04-12 09:59:09
 */
#ifndef CLOX_MEMORY_H
#define CLOX_MEMORY_H

/* 重新计算保存字节码的空间大小 */
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(previous, type, oldCount, count) \
    (type *) reallocate(previous, sizeof(type) * (oldCount), \
        sizeof(type) * (count))

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * sizeof(oldCount), 0)

/**
 * 字节码模块的内存管理都将通过此函数实现，物理是分配还是释放。这样做的好
 * 处是便于垃圾回收（需要跟踪内存的使用情况）。
 */
void* reallocate(void* previous, size_t oldSize, size_t newSize);

#endif  /* CLOX_MEMORY_H */