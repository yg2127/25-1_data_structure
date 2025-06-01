//
// Created by 유건 on 25. 5. 26.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// ====================== 구조체 정의 ===========================
typedef struct{
    char *data;
    int Max_size;
    int top;
}Stack;

// ====================== 함수 정의 =============================

// 스택 초기화
void initStack(Stack *s, int size) {
    s -> data = (char*)malloc(size*sizeof(char));
    s -> Max_size = size;
    s -> top = -1;
}

int isEmpty(Stack *s) {
    return s -> top == -1;
}
int isFull(Stack *s) {
    return s -> top +1 == s -> Max_size;
}
// PUSH
void PUSH(Stack *s, char data) {
    if (isFull(s)) {
        printf("Stack Full\n");
        return;
    }
    s -> top++;
    s -> data[s->top] = data;
}
// POP
void POP(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return;
    }
    s -> top--;
}
// PEEK
void PEEK(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return;
    }
    printf("%c\n", s -> data[s->top]);
}
void DUP(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return;
    }
    if (isFull(s)) {
        printf("Stack Full\n");
        return;
    }
    char tmp = s -> data[s -> top];
    s -> top++;
    s -> data[s -> top] = tmp;
}
void UpR(Stack *s, int n) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return;
    }
    
}
void DownR(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return;
    }

}
void PRINT(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return;
    }
    for (int p = s -> top; p >= 0; p--) {
        printf("%c", s -> data[p]);
    }
    printf("\n");
}
int main() {

}