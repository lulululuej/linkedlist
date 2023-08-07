#include <stdlib.h>
#include <stdio.h>

typedef struct Linkedlist
{
    int val;
    struct Linkedlist* next;
} Linkedlist;

void pushFront(Linkedlist** head_ref, int new_val) {
    Linkedlist* header = malloc(sizeof(Linkedlist));
    header->val = new_val;
    header->next = (*head_ref);
    (*head_ref) = header;
}

void pushBack(Linkedlist* ptr, int new_val) {
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    Linkedlist* last = malloc(sizeof(Linkedlist));
    last->val = new_val;
    last->next = NULL;
    ptr->next = last;
}

void display(Linkedlist* ptr) {
    printf("The linkedlist contain :\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

int popTop(Linkedlist** head) {
    Linkedlist* nextNode = (*head)->next;
    int popval = (*head)->val;
    free (*head); 
    *head = nextNode;
    return popval;
}

int popBack(Linkedlist* ptr) {
    int popval = 0;
    if(ptr->next == NULL) {
        popval = ptr->val;
        free(ptr);
        return popval;
    }
    while(ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    popval = ptr->next->val;
    free(ptr->next);
    ptr->next = NULL;
    return popval;
}

int rmByIdx(Linkedlist* ptr, int Idx) {
    if(Idx == 0) {
        popTop(&ptr);
    }

    for(unsigned int i = 1; i < Idx; i++) {
        ptr = ptr->next;
    }

    Linkedlist* tempNode = ptr->next;
    int rmVal = tempNode->val;
    ptr->next = tempNode->next;
    free(tempNode);

    return rmVal;
}

void itByIdx(Linkedlist* ptr, int Idx, int newVal) {
    if(Idx == 0) {
        pushFront(&ptr, newVal);
    }

    for(unsigned int i = 1; i < Idx; i++) {
        ptr = ptr->next;
    }

    Linkedlist* newNode = malloc(sizeof(Linkedlist));
    newNode->val = newVal;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

int main() {
    Linkedlist* first = malloc(sizeof(Linkedlist));
    first->val = 10;
    first->next = NULL;
    pushBack(first, 20);
    pushBack(first, 30);
    pushBack(first, 40);
    pushBack(first, 50);
    pushFront(&first, 0);
    display(first);
    popTop(&first);
    display(first);
    popBack(first);
    display(first);
    rmByIdx(first, 2);
    display(first);
    itByIdx(first, 2, 99);
    display(first);
}