#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linked_list {
    char value[100];
    struct linked_list *next;
};

void pushLinkedList(struct linked_list **list, char *value) {
    struct linked_list *newNode = (struct linked_list *)malloc(sizeof(struct linked_list));
    struct linked_list *head = *list;
    strcpy(newNode->value, value);
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
        return;
    }

    while (head->next != NULL) {
        head = head->next;
    }
    head->next = newNode;
    return;
}

void dlist_init(struct linked_list **list) {
    pushLinkedList(list, "ini");
    pushLinkedList(list, "tugas");
    pushLinkedList(list, "struktur");
    pushLinkedList(list, "data");
}

void printElement(char *elem) {
    printf("%s ", elem);
    return;
}

void forEachElement(struct linked_list **list, void (*f)(char *elem)) {
    struct linked_list *head = *list;
    while (head != NULL) {
        f(head->value);
        head = head->next;
    }
}

int main() {
    struct linked_list *list = NULL;
    dlist_init(&list);
    forEachElement(&list, printElement);
    return 0;
}