#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct StackNode {
    char data[100];
    StackNode *next;
};

struct Stack {
    StackNode *_top;
    unsigned _size;

    void init() {
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(char *value) {
        StackNode *newNode = (StackNode *) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            strcpy(newNode->data, value);

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
        }
    }

    void pop() {
        if (!isEmpty()) {
            StackNode *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }

    char *top() {
        if (!isEmpty())
            return _top->data;
        exit(-1);
    }
};

int main() {
    Stack stack;
    stack.init();
    stack.push("data");
    stack.push("struktur");
    stack.push("tugas");
    stack.push("ini");
    while (!stack.isEmpty()) {
        printf("%s ", stack.top());
        stack.pop();
    }
    return 0;
}