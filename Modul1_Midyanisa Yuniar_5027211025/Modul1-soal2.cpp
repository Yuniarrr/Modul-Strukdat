
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

struct PQueueNode
{
    int data;
    PQueueNode *next;
};

struct PriorityQueue
{
    PQueueNode *_top;
    unsigned _size;

    void init()
    {
        _top = NULL;
        _size = 0;
    }

    bool isEmpty()
    {
        return (_top == NULL);
    }

    void push(int value)
    {
        PQueueNode *temp = _top;
        PQueueNode *newNode =
            (PQueueNode *)malloc(sizeof(PQueueNode));
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty())
        {
            _top = newNode;
            return;
        }

        if (value < _top->data)
        {
            newNode->next = _top;
            _top = newNode;
        }
        else
        {
            while (temp->next != NULL &&
                   temp->next->data < value)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            PQueueNode *temp = _top;
            _top = _top->next;
            free(temp);
        }
    }

    int top()
    {
        if (!isEmpty())
            return _top->data;
        else
            exit(-1);
    }

    unsigned size()
    {
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    PriorityQueue pq;
    pq.init();
    string a;
    int n;
    int x = 0;
    int num[2];
    int b;
    int c;
    cin >> n;
    while (x < n)
    {
        cin >> a;
        if (a == "MASUK")
        {
            cin.ignore(1, ' ');
            cin >> b >> c;
            pq.push(c);
        }
        if (a == "LAYANI")
        {
            pq.pop();
            // cout << pq.top() << " ";
            // if (pq.top() == num[1]) {
            //     cout << num[0] << endl;
            // }
        }
        x++;
    }
    // cout << pq.top() << " ";

    while (!pq.isEmpty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
