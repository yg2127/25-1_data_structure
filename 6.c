//
// Created by À¯°Ç on 25. 4. 10.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int a;
    int b;
    struct Node* next;
} Node;

Node* add(Node* head, int a, int b) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->a = a;
    new->b = b;
    new->next = NULL;

    if (!head) return new;

    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new;
    return head;
}

Node* input() {
    int n, a, b;
    scanf("%d", &n);
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        head = add(head, a, b);
    }
    return head;
}

Node* plus(Node* p, Node* q) {
    Node* res = NULL;

    while (p && q) {
        if (p->b == q->b) {
            int sum = p->a + q->a;
            if (sum != 0)
                res = add(res, sum, p->b);
            p = p->next;
            q = q->next;
        } else if (p->b > q->b) {
            res = add(res, p->a, p->b);
            p = p->next;
        } else {
            res = add(res, q->a, q->b);
            q = q->next;
        }
    }

    while (p) {
        res = add(res, p->a, p->b);
        p = p->next;
    }

    while (q) {
        res = add(res, q->a, q->b);
        q = q->next;
    }

    return res;
}

void out(Node* head) {
    while (head) {
        printf("%d %d ", head->a, head->b);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* p1 = input();
    Node* p2 = input();
    Node* sum = plus(p1, p2);
    out(sum);
    return 0;
}