//
// Created by 유건 on 25. 6. 8.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int top;
    int size;
    char *data;
}Stack;
void init(Stack *s, int size) {
    s -> data = (char*)malloc(size*sizeof(char));
    s -> top = -1;
    s -> size = size;
}
void push(Stack *s, char value) {
    s -> top++;
    s -> data[s -> top] = value;
}
char pop(Stack *s) {
    return s -> data[(s -> top)--];
}
char peek(Stack *s) {
    return s -> data[s -> top];
}

int priority(char value) {
    if (value == '!') return 6;
    else if (value == '*' || value == '/') return 5;
    else if (value == '+' || value == '-') return 4;
    else if (value == '>' || value == '<') return 3;
    else if (value == '&') return 2;
    else if (value == '|') return 1;
    else if (value == '(') return 0;
    else return -1;
}
void rtop(char* raw, char* pri) {
    Stack s1, *s = &s1;
    int len = strlen(raw);
    init(s, len);
    int nr=0, np=0;

    for (nr = 0; nr < len; nr++) {
        char token = raw[nr];

        if ('A' <= token && token <= 'Z') {
            pri[np++] = token;
            continue;
        }

        else if (token == '(') { // 괄호열기 나오면 일단 넣기
            push(s, token);
            continue;
        }
        else if (token == ')') {
            while (peek(s) != '(') { // '(' 나올때까지 모든 연산자 출력
                char op = pop(s); // 일단 스택에서 꺼내서 변수에 저장

                if (op == '&' || op == '|') { // 만약 '&'나 '|' 라면
                    pri[np++] = op; // 첫 번째 글자 추가
                    pri[np++] = op; // 두 번째 글자 한번 더 추가!
                } else { // 그 외 다른 연산자라면
                    pri[np++] = op; // 원래대로 한 글자만 추가
                }
            }

            pop(s); // '(' 버리기
            continue;
        }
        else if (token == '&' || token == '|') nr++;

        while (s->top != -1 && peek(s) != '(' &&
       (priority(peek(s)) > priority(token) || (priority(peek(s)) == priority(token) && token != '!'))) {

            char op = pop(s); // 일단 스택에서 꺼내서 변수에 저장

            if (op == '&' || op == '|') { // 만약 '&'나 '|' 라면
                pri[np++] = op; // 첫 번째 글자 추가
                pri[np++] = op; // 두 번째 글자 한번 더 추가!
            } else { // 그 외 다른 연산자라면
                pri[np++] = op; // 원래대로 한 글자만 추가
            }
        }
        push(s, token);
    }

    while (s -> top != -1) {
        char op = pop(s); // 일단 스택에서 꺼내서 변수에 저장

        if (op == '&' || op == '|') { // 만약 '&'나 '|' 라면
            pri[np++] = op; // 첫 번째 글자 추가
            pri[np++] = op; // 두 번째 글자 한번 더 추가!
        } else { // 그 외 다른 연산자라면
            pri[np++] = op; // 원래대로 한 글자만 추가
        }
    }
}
int main() {
    char raw[100], pri[100];
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%s", raw);
        rtop(raw, pri);
        printf("%s\n", pri);
    }

    return 0;
}