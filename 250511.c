//
// Created by 유건 on 25. 5. 11.
//
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
}Stack;

void init(Stack *s) {
    s -> top = -1; // stack에 push가 되어서 첫번째 원소가 생기면 인덱스 = 0, 원소값 n이 들어가니까!
}

