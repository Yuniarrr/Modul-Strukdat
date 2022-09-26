#include <stdio.h>
#include <stdlib.h>

// Linked List

struct linked_list
{
    int value;
    struct linked_list *next;
};

bool isEmpty(linked_list *list)
{
    return (list->next == NULL);
}

void pushLinkedList(struct linked_list **list, int value)
{
    linked_list *newNode = (linked_list *)malloc(sizeof(linked_list));
    struct linked_list *head = *list;
    newNode->value = value;
    newNode->next = NULL;

    if (*list == NULL)
    {
        *list = newNode;
        return;
    }

    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode;
    return;
}

void dlist_init(struct linked_list **list)
{
    pushLinkedList(list, 24);
    pushLinkedList(list, 39);
    pushLinkedList(list, 12);
    pushLinkedList(list, 15);
    pushLinkedList(list, 10);
}

void printElement(int *elem)
{
    printf("%d ", *elem);
    return;
}

void multiply2(int *elem)
{
    *elem = *elem * 2;
}

void forEachElement(struct linked_list **list, void (*f)(int *elem))
{
    struct linked_list *tmp = NULL;

    while (*list != NULL)
    {
        (*f)(&(*list)->value);
        pushLinkedList(&tmp, (*list)->value);
        *list = (*list)->next;
    }

    *list = tmp;
    return;
}

void reverseEach(int *elem)
{
    int rev = 0;
    while (*elem != 0)
    {
        rev = rev * 10 + *elem % 10;
        *elem /= 10;
    }
    *elem = rev;
}

void sumDigit(int *elem)
{
    int sum = 0;
    while (*elem != 0)
    {
        sum += *elem % 10;
        *elem /= 10;
    }
    *elem = sum;
}

int main()
{
    struct linked_list *myList = NULL;

    dlist_init(&myList);

    printf("Original List: ");
    forEachElement(&myList, printElement);
    forEachElement(&myList, multiply2);

    printf("\nMultiply: ");
    forEachElement(&myList, printElement);

    printf("\nReverse: ");
    forEachElement(&myList, reverseEach);
    forEachElement(&myList, printElement);

    printf("\nSum: ");
    forEachElement(&myList, sumDigit);
    forEachElement(&myList, printElement);

    free(myList);

    return 0;
}