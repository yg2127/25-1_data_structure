//
// Created by 유건 on 25. 6. 9.
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
    int size, max;
}Stack;
void init(Stack *s, int max) {
    s -> top = NULL;
    s -> max = max;
    s -> size = 0;
}
Node *mknode(int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

void push(Stack *s, int data) { // top 위치에 data를 입력받음
    Node *newnode = mknode(data);
    newnode -> next = s -> top;
    s -> top = newnode;
}
int pop(Stack *s) { // top 위치의 데이터를 반환하고 동적할당 해제
    Node *tmp = s -> top;
    int data = tmp -> data;
    s -> top = s -> top -> next;
    free(tmp);
    return data;
}

int cal(char *rda) { // pop 두번한 값을 연산 후 push, 마지막에 pop한 값을 반환
    Stack s1, *s = &s1;
    init(s, 100);

    for (int i = 0; i < strlen(rda); i++) {
        if ('0' <= rda[i] && rda[i] <= '9') {
            push(s, rda[i] - '0');
        }
        else if (rda[i] == '+') {
            int d1 = pop(s), d2 = pop(s);
            push(s, d1+d2);
        }
        else if (rda[i] == '-') {
            int d1 = pop(s), d2 = pop(s);
            push(s, d2-d1);
        }
        else if (rda[i] == '*') {
            int d1 = pop(s), d2 = pop(s);
            push(s, d2*d1);
        }
        else if (rda[i] == '/') {
            int d1 = pop(s), d2 = pop(s);
            push(s, d2/d1);
        }
    }

    return pop(s);
}

int main() {
    int n;
    char rda[100];
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        gets(rda);
        printf("%d\n", cal(rda));
    }
}