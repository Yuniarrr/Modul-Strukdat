#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct PQueueNode {
    char data[100];
    PQueueNode *next;
};

struct PriorityQueue {
    PQueueNode *_front, *_rear;
    unsigned _size;

    void init() {
        _size  = 0;
        _front = NULL;
        _rear  = NULL;
    }

    bool isEmpty() {
        return (_front == NULL && _rear == NULL);
    }

    void push(char *value) {
        PQueueNode *newNode = (PQueueNode*) malloc(sizeof(PQueueNode));
        if (newNode) {
            _size++;
            strcpy(newNode->data, value);
            newNode->next = NULL;
            
            if (isEmpty())                 
                _front = _rear = newNode;
            else {
                PQueueNode *temp = _front;
                PQueueNode *prev = NULL;
                while (temp != NULL && strcmp(temp->data, value) < 0) {
                    prev = temp;
                    temp = temp->next;
                }
                if (prev == NULL) {
                    newNode->next = _front;
                    _front = newNode;
                } else {
                    newNode->next = temp;
                    prev->next = newNode;
                }
            }
        }
    }

    void pop() {
        if (!isEmpty()) {
            PQueueNode *temp = _front;
            _front = _front->next;
            free(temp);
            
            if (_front == NULL)
                _rear = NULL;
            _size--;
        }
    }

    char *front() {
        if (!isEmpty())
            return _front->data;
        exit(-1);
    }

    char *rear() {
        if (!isEmpty())
            return _rear->data;
        exit(-1);
    }
};

int main() {
    PriorityQueue pqueue;
    pqueue.init();
    pqueue.push("data");
    pqueue.push("struktur");
    pqueue.push("tugas");
    pqueue.push("ini");
    while (!pqueue.isEmpty()) {
        printf("%s ", pqueue.front());
        pqueue.pop();
    }
    return 0;
}