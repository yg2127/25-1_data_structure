//
// Created by 유건 on 25. 5. 26.
//
#include <stdio.h>
#include <stdlib.h>

// ======================= 구조체 정의 =========================
typedef struct {
    char* data;   // 문자형 스택
    int top;      // top 위치
    int size;     // 최대 크기
} Stack;

// ======================= 함수 정의 =========================

// 스택 초기화
void initStack(Stack* s, int size) {
    s->data = (char*)malloc(sizeof(char) * size);
    s->top = -1;
    s->size = size;
}

// 스택 비었는지 확인
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 스택 가득 찼는지 확인
int isFull(Stack* s) {
    return s->top == s->size - 1;
}

// PUSH
void push(Stack* s, char value) {
    if (isFull(s)) {
        printf("Stack FULL\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

// POP
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return '\0';  // 널 문자 반환
    }
    char value = s->data[s->top];
    s->top--;
    return value;
}

// PEEK
char peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return '\0';
    }
    return s->data[s->top];
}

// 스택 전체 출력 (Top → Bottom 순으로)
void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Empty\n");
        return;
    }
    printf("Stack (top→bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%c ", s->data[i]);
    }
    printf("\n");
}

// 스택 해제
void freeStack(Stack* s) {
    free(s->data);
}