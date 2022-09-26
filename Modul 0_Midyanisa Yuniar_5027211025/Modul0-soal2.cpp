#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
using namespace std;

typedef struct dynamicArr {
    int *arr;
    unsigned size, capacity;
} DynamicArr;

void dynamicarr_init (DynamicArr *arr) {
    arr->size = 0;
    arr->capacity = 1;
    arr->arr = (int *)malloc(arr->capacity * sizeof(int));
}

bool dynamicarr_empty(DynamicArr *arr) {
    return arr->size == 0;
}

int dynamicarr_getAt(DynamicArr *arr, unsigned index) {
    if (dynamicarr_empty(arr)) {
        if(index >= arr->size) {
            return arr->arr[arr->size - 1];
        } else {
            return arr->arr[index];
        }
    }
}

// beda
void dynamicarr_autoExpand (DynamicArr *arr) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->arr = (int *)realloc(arr->arr, arr->capacity * sizeof(int));
    }
}

void dynamicarr_pushBack(DynamicArr *arr, int value) {
    if(arr->size + 1 >= arr->capacity) {
        dynamicarr_autoExpand(arr);
    }
    arr->arr[arr->size++] = value;
}

// beda
void dynamicarr_insertAt(DynamicArr *arr, unsigned index, int value) {
    if(arr->size + 1 >= arr->capacity) {
        dynamicarr_autoExpand(arr);
    }
    for (int i = arr->size; i > index; i--) {
        arr->arr[i] = arr->arr[i - 1];
    }
    arr->arr[index] = value;
    arr->size++;
}

void dynamicarr_removeAt(DynamicArr* arr, unsigned index) {
    for (int i = index; i < arr->size - 1; i++) {
        arr->arr[i] = arr->arr[i + 1];
    }
    arr->size--;
}

void dynamicarr_print(DynamicArr *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->arr[i]);
    }
    printf("size: %d, capacity: %d  ", arr->size, arr->capacity);   
}

int main() {
    DynamicArr arr;
    dynamicarr_init(&arr);
    dynamicarr_pushBack(&arr, 10);
    dynamicarr_pushBack(&arr, 24);
    dynamicarr_pushBack(&arr, 39);
    dynamicarr_pushBack(&arr, 12);
    dynamicarr_pushBack(&arr, 15);
    dynamicarr_removeAt(&arr, 2);
    dynamicarr_insertAt(&arr, 2, 100);
    dynamicarr_print(&arr);
}