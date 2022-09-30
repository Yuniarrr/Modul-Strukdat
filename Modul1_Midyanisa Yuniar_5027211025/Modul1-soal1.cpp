#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct StackNode {
    int value;
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

    void push(int value) {
        StackNode *newNode = (StackNode *) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            newNode->value = value;

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

    int top() {
        if (!isEmpty())
            return _top->value;
        exit(-1);
    }

    int smallestElement() {
        StackNode *temp = _top;
        int min = temp->value;
        while (temp != NULL) {
            if (temp->value < min) {
                min = temp->value;
            }
            temp = temp->next;
        }
        printf("Smallest element is %d", min);
        return min;
    }
};

int main() {
    Stack stack;
    stack.init();
    stack.push(5);
    stack.push(11);
    stack.push(10);
    stack.push(9);
    stack.smallestElement();
    return 0;
}