/*
 * @Description: 保存指令中的操作数或者常量。
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-11 12:23:31
 * @LastEditTime: 2019-04-12 09:49:54
 */
#ifndef CLOX_VALUE_H
#define CLOX_VALUE_H

#include "common.h"

typedef double Value;

/**
 * 我们需要保存指令操作中的常量值，与chunk类似，我们也采用变长数组。
 */
typedef struct {
    Value* values;
    int count;
    int capacity;
} ValueArray;

void initValueArray(ValueArray* array);
void freeValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void printValue(Value value);

#endif  /* CLOX_VALUE_H */
