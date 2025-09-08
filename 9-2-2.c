//
// Created by À¯°Ç on 25. 6. 10.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    struct Node *next;
    char data;
}Node;

typedef struct Stack {
    Node *top;
    int size;
}Stack;
void init(Stack *s) {
    s -> top = NULL;
    s -> size = 0;
}

int isEmpty(Stack *s) {
    return (s -> size == 0);
}
Node *mknode(char data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = NULL;

    return newnode;
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
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
               (open == '[' && close == ']');
}
int check(char *rdata) {
    Stack s1, *s = &s1;
    init(s);

    for (int i = 0; i < strlen(rdata); i++) {
        if ((rdata[i] == '(') || (rdata[i] == '{') || (rdata[i] == '[')) push(s, rdata[i]);
        else if ((rdata[i] == ')') || (rdata[i] == '}') || (rdata[i] == ']')) {
            if (isEmpty(s)) return 0;
            if (ispair(peek(s),rdata[i])) pop(s);
            else return 0;
        }
    }
    if (isEmpty(s)) return 1;
    else return 0;
}
int cal(char *rdata) {
    int sum = 0;
    for (int i = 0; i < strlen(rdata); i++) {
        if ((rdata[i] == '(') || (rdata[i] == '{') || (rdata[i] == '[')
            || (rdata[i] == ')') || (rdata[i] == '}') || (rdata[i] == ']')) {
            sum++;
        }
    }
    return sum;
}
int main() {
    char arr[1000];
    gets(arr);
    if (check(arr)) printf("OK_%d", cal(arr));
    else printf("Wrong_%d", cal(arr));
}