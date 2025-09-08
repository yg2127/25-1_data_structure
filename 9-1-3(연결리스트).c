//
// Created by 유건 on 25. 6. 7.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    struct Node *next;
    char data;
}Node;
typedef struct Stack {
    Node *top;
    int size; // 현재 스택의 사이즈
}Stack;
void initS(Stack *s) {
    s -> top = NULL;
    s -> size = 0;
}
int isEmpty(Stack *s) {
    return (s -> top == NULL);
}
int isFull(Stack *s, int max) {
    return (s->size == max);
}

void push(Stack *s, char data, int max) {
    if (isFull(s, max)) {
        printf("stack full\n");
        return;
    }
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = s -> top;
    s -> top = newnode;
    s -> size++;
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack empty\n");
        return;
    }
    Node* tmp = s -> top;
    s -> top = s -> top -> next;
    free(tmp);
    s -> size--;
}
void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack empty\n");
    }
    else printf("%c\n", s -> top -> data);
}
void dup(Stack *s) {
    if (isFull(s, max-1)) {
        printf("stack full\n");
        return;
    }

    Node *newnode = (node*)malloc(sizeof(Node));
    newnode -> data = s -> top -> data;
    newnode -> next = s -> top;
    s -> top = newnode;
    s -> size++;
}
