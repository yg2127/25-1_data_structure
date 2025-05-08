//
// Created by À¯°Ç on 25. 5. 8.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *top = NULL;

void pushLL(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    n->data = v;
    n->next = top;
    top = n;
}

int popLL() {
    if (!top) exit(EXIT_FAILURE);
    Node *n = top;
    int v = n->data;
    top = n->next;
    free(n);
    return v;
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    char expr[101];
    while (T--) {
        scanf("%100s", expr);
        top = NULL;
        for (int i = 0; expr[i]; i++) {
            char c = expr[i];
            if (c >= '0' && c <= '9') {
                pushLL(c - '0');
            } else {
                int b = popLL();
                int a = popLL();
                int r;
                switch (c) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;
                case '/':
                    if (b == 0) exit(EXIT_FAILURE);
                    r = a / b;
                    break;
                default: exit(EXIT_FAILURE);
                }
                pushLL(r);
            }
        }
        printf("%d\n", popLL());
    }
    return 0;
}