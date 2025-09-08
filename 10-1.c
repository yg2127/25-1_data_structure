//
// Created by 유건 on 25. 5. 8.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

void push(StackNode** top, char data) {
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

char pop(StackNode** top) {
    if (*top == NULL) return '\0';
    StackNode* temp = *top;
    char value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

char peek(StackNode* top) {
    return (top != NULL) ? top->data : '\0';
}

int is_empty(StackNode* top) {
    return top == NULL;
}

int get_priority(char op) {
    if (op == '!') return 6;
    if (op == '*' || op == '/') return 5;
    if (op == '+' || op == '-') return 4;
    if (op == '>' || op == '<') return 3;
    if (op == '&') return 2;
    if (op == '|') return 1;
    return 0;
}

int is_left_associative(char op) {
    return op != '!';
}

int is_operator(char c) {
    return strchr("!*/+-<>&|", c) != NULL;
}

void to_postfix(const char* expr, char* output) {
    StackNode* stack = NULL;
    int idx = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char token = expr[i];

        if (isalpha(token)) {
            output[idx++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!is_empty(stack) && peek(stack) != '(') {
                output[idx++] = pop(&stack);
            }
            if (!is_empty(stack)) pop(&stack);  // '(' 제거
        } else if (is_operator(token)) {
            while (!is_empty(stack) && peek(stack) != '(') {
                char top_op = peek(stack);
                int curr_p = get_priority(token);
                int top_p = get_priority(top_op);

                if (top_p > curr_p || (top_p == curr_p && is_left_associative(token))) {
                    output[idx++] = pop(&stack);
                } else {
                    break;
                }
            }
            push(&stack, token);
        }
    }

    while (!is_empty(stack)) {
        output[idx++] = pop(&stack);
    }

    output[idx] = '\0';
}

int main() {
    int n;
    char expr[MAX];
    char result[MAX];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", expr);
        to_postfix(expr, result);
        printf("%s\n", result);
    }

    return 0;
}