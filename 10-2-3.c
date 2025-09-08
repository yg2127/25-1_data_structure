//
// Created by À¯°Ç on 25. 6. 10.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
    struct Node *next;
    int data;
}Node;
typedef struct Stack {
    Node *top;
    int size;
}Stack;
void init(Stack *s) {
    s -> top = NULL;
    s -> size = 0;
}
Node *mknode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = NULL;

    return newnode;
}

void push(Stack *s, int data) {
    Node *newnode = mknode(data);
    newnode -> next = s -> top;
    s -> top = newnode;
    s->size++;
}

int pop(Stack *s) {
    Node *tmp = s -> top;
    int a = tmp -> data;
    s -> top = s -> top -> next;
    free(tmp);
    s -> size--;
    return a;
}


int cal(char *rdata) {
    Stack s1, *s = &s1;
    init(s);
    for (int i = 0; i < strlen(rdata); i++) {
        if ('0' <= rdata[i] && rdata[i] <= '9') push(s, rdata[i] - '0');
        else if (rdata[i] == '+') {
            int d1 = pop(s);
            int d2 = pop(s);
            push(s, d1+d2);
        }
        else if (rdata[i] == '-') {
            int d1 = pop(s);
            int d2 = pop(s);
            push(s, d2-d1);
        }
        else if (rdata[i] == '*') {
            int d1 = pop(s);
            int d2 = pop(s);
            push(s, d1*d2);
        }
        else if (rdata[i] == '/') {
            int d1 = pop(s);
            int d2 = pop(s);
            push(s, d2/d1);
        }
    }
    return pop(s);
}

int main() {
    int n;
    char arr[100];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        printf("%d\n", cal(arr));
    }
}