/*
 * @Description: 操作数或常量保存实现。
 * @Version:
 * @Author: lancer wong
 * @LastEditors: lancer wong
 * @Date: 2019-04-11 12:30:45
 * @LastEditTime: 2019-04-12 09:56:06
 */
#include <stdio.h>

#include "memory.h"
#include "value.h"

void
initValueArray(ValueArray* array) {
    array->values = NULL;
    array->count = 0;
    array->capacity = 0;
}

void
freeValueArray(ValueArray* array) {
    FREE_ARRAY(Value, array->values, array->capacity);
    initValueArray(array);
}

void
writeValueArray(ValueArray* array, Value value) {
    if (array->capacity < array->count + 1) {
        int oldCapacity = array->capacity;

        array->capacity = GROW_CAPACITY(oldCapacity);
        array->values = GROW_ARRAY(array->values, Value,
            oldCapacity, array->capacity);
    }

    array->values[array->count++] = value;
}

void printValue(Value value) {
    printf("%g", value);
}