//
// Created by À¯°Ç on 25. 4. 17.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* append(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    return n;
}

Node* make_list(int size) {
    if (size == 0) return NULL;

    int num;
    scanf("%d", &num);
    Node* head = append(num);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        scanf("%d", &num);
        tail->next = append(num);
        tail = tail->next;
    }
    return head;
}

int is_in(Node* list, int val) {
    while (list != NULL) {
        if (list->data == val)
            return 1;
        if (list->data > val)
            break;
        list = list->next;
    }
    return 0;
}

int subset(Node* A, Node* B) {
    if (A == NULL) return 0;

    Node* cur = A;
    while (cur != NULL) {
        if (!is_in(B, cur->data)) {
            return cur->data;
        }
        cur = cur->next;
    }
    return 0;
}

void free_list(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
}

int main() {
    int sizeA, sizeB;
    scanf("%d", &sizeA);
    Node* A = make_list(sizeA);

    scanf("%d", &sizeB);
    Node* B = make_list(sizeB);

    int result = subset(A, B);
    if (result == 0) {
        printf("0");
    } else {
        printf("%d", result);
    }

    free_list(A);
    free_list(B);

    return 0;
}