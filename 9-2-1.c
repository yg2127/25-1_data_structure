//
// Created by 유건 on 25. 6. 9.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    struct Node* next;
    char data;
}Node;

typedef struct Stack {
    Node* top;
    int size, max;
}Stack;

void init(Stack *s, int max) {
    s -> top = NULL;
    s -> size = 0;
    s -> max = max;
}
Node* mknode(char data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> next = NULL;
    newnode -> data = data;
    return newnode;
}
int isFull(Stack *s) {
    return (s -> size == s -> max);
}
int isEmpty(Stack *s) {
    return (s -> size == 0);
}
void push(Stack *s, char data) {
    Node *newnode = mknode(data);

    newnode -> next = s -> top;
    s -> top = newnode;
    s -> size++;
}
void pop(Stack *s) {
    Node *tmp = s -> top;
    s -> top = s -> top -> next;
    free(tmp);
    s -> size--;
}
char peek(Stack *s) {
    return s -> top -> data;
}
int ispair(char open, char close) {
    return  (open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']');
}
int val(char *rda) { // 괄효의 유효성 검사
    Stack s1, *s = &s1;
    init(s, 1000);
    for (int i = 0; i < strlen(rda); i++) {
        if (rda[i] == '(' || rda[i] == '{' || rda[i] == '[') {
            push(s, rda[i]);
        }
        else if (rda[i] == ')' || rda[i] == '}' || rda[i] == ']') {
            if (isEmpty(s)) return 0; // 스택이 비었을 때 닫는괄호 나올 수 있음!
            if (!ispair(peek(s), rda[i])) return 0;
            else pop(s);
        }
    }
    if (isEmpty(s)) return 1;
    else return 0;
}

int cal(char *rda) { // 괄호 전체 개수검사
    int n = 0;
    for (int i = 0; i < strlen(rda); i++) {
        if (rda[i] == '(' || rda[i] == ')' || rda[i] == '{' || rda[i] == '}' || rda[i] == '[' || rda[i] == ']') n++;
    }
    return n;
}
int main() {
    char rda[1000];
    gets(rda);

    if (val(rda)) printf("OK_%d", cal(rda));
    else printf("Wrong_%d", cal(rda));
}