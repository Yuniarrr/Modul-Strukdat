#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct QueueNode {
    char data[100];
    QueueNode *next;
};

struct Queue {
    QueueNode *_front, *_rear;
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
        QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
        if (newNode) {
            _size++;
            strcpy(newNode->data, value);
            newNode->next = NULL;
            
            if (isEmpty())                 
                _front = _rear = newNode;
            else {
                _rear->next = newNode;
                _rear = newNode;
            }
        }
    }

    void pop() {
        if (!isEmpty()) {
            QueueNode *temp = _front;
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
    Queue queue;
    queue.init();
    queue.push("data");
    queue.push("struktur");
    queue.push("tugas");
    queue.push("ini");
    while (!queue.isEmpty()) {
        printf("%s ", queue.front());
        queue.pop();
    }
    return 0;
}