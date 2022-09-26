#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct dynamicarr_string {
    char **arr;
    unsigned size;
    unsigned capacity;
} dynamicarr_string;

void dynamicarr_string_init(dynamicarr_string *arr) {
    arr->size = 0;
    arr->capacity = 1;
    arr->arr = (char **)malloc(arr->capacity * sizeof(char *));
}

bool dynamicarr_string_empty(dynamicarr_string *arr) {
    return arr->size == 0;
}

char *dynamicarr_string_getAt(dynamicarr_string *arr, unsigned index) {
    if (dynamicarr_string_empty(arr)) {
        if(index >= arr->size) {
            return arr->arr[arr->size - 1];
        } else {
            return arr->arr[index];
        }
    }
}

void dynamicarr_string_autoExpand(dynamicarr_string *arr) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->arr = (char **)realloc(arr->arr, arr->capacity * sizeof(char *));
    }
}

void dynamicarr_string_pushBack(dynamicarr_string *arr, char *value) {
    if(arr->size + 1 >= arr->capacity) {
        dynamicarr_string_autoExpand(arr);
    }
    arr->arr[arr->size++] = value;
}

void dynamicarr_string_insertAt(dynamicarr_string *arr, unsigned index, char *value) {
    if(arr->size + 1 >= arr->capacity) {
        dynamicarr_string_autoExpand(arr);
    }
    for (int i = arr->size; i > index; i--) {
        arr->arr[i] = arr->arr[i - 1];
    }
    arr->arr[index] = value;
    arr->size++;
}

void dynamicarr_string_removeAt(dynamicarr_string *arr, unsigned index) {
    for (int i = index; i < arr->size - 1; i++) {
        arr->arr[i] = arr->arr[i + 1];
    }
    arr->size--;
}

void dynamicarr_string_print(dynamicarr_string *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%s ", arr->arr[i]);
    }
    printf("\n");
}

int main() {
    dynamicarr_string arr;
    dynamicarr_string_init(&arr);
    dynamicarr_string_pushBack(&arr, "alfa");
    dynamicarr_string_pushBack(&arr, "beta");
    dynamicarr_string_pushBack(&arr, "charly");

    dynamicarr_string_print(&arr);
    dynamicarr_string_insertAt(&arr, 0, "delta");
    dynamicarr_string_print(&arr);
    dynamicarr_string_insertAt(&arr, 1, "echo");
    dynamicarr_string_print(&arr);

    return 0;
}