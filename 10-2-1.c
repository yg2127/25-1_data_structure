//
// Created by 유건 on 25. 6. 7.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int top, size, *data;
}Stack;

void init(Stack* s) {
    s -> data = (int*)malloc(100 * sizeof(int));
    s -> top = -1;
    s -> size = 100;
}

void push(Stack* s, int data) {
    s -> top++;
    s -> data[s -> top] = data;
}

int pop(Stack* s) {
    s -> top--;
    return s -> data[s -> top + 1];
}

int ctoi(char value) {
    return value - '0';
}

int main() {
    char rdata[100];
    int nf, d1, d2;
    Stack s1;
    Stack *s = &s1;
    init(s);

    scanf("%d", &nf);
    getchar();
    for (int i = 0; i < nf; i++) { // 입력받는 후위수식의 개수에 따른 반복
        scanf("%s", &rdata); // 후위수식을 문자열로 입력받음
        getchar(); // 개행문자 제거

        for (int j = 0; j < strlen(rdata); j++) { // 후위수식의 길이만큼 반복 -> 숫자면 push, 연산자면 pop 두번 후 연산하고 push
            if ('0' <= rdata[j] && rdata[j] <= '9') { // 숫자면?
                push(s, ctoi(rdata[j]));
            }
            else if (rdata[j] == '+') {
                d1 = pop(s);
                d2 = pop(s);
                push(s,d1+d2);
            }
            else if (rdata[j] == '-') {
                d1 = pop(s);
                d2 = pop(s);
                push(s,d1-d2);
            }
            else if (rdata[j] == '*') {
                d1 = pop(s);
                d2 = pop(s);
                push(s,d1*d2);
            }
            else if (rdata[j] == '/') {
                d1 = pop(s);
                d2 = pop(s);
                push(s,d1/d2);
            }
        }
        printf("%d\n", pop(s));
    }
}