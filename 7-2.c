//
// Created by 유건 on 25. 4. 17.
//
#include <stdio.h>
#include <stdlib.h>

// 연결리스트 노드 정의
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

void print_list(Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }

    int count = 0;
    Node* cur = head;

    cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// 메모리 해제 함수
void free_list(Node* head) {
    Node* temp;
    while (head) {
        temp = head->next;
        free(head);
        head = temp;
    }
}

// 교집합 함수 (수도코드 기반)
Node* intersect(Node* A, Node* B) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (1) {
        if (A == NULL || B == NULL) break;

        int a = A->data;
        int b = B->data;

        if (a < b) {
            A = A->next;
        } else if (a > b) {
            B = B->next;
        } else {
            tail->next = append(a);
            tail = tail->next;
            A = A->next;
            B = B->next;
        }
    }

    return dummy.next;
}

Node* union_(Node* A, Node* B) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (1) {
        if (A == NULL || B == NULL) break;

        int a = A->data;
        int b = B->data;

        if (a < b) {
            tail->next = append(a);
            tail = tail->next;
            A = A->next;
        } else if (a > b) {
            tail->next = append(b);
            tail = tail->next;
            B = B->next;
        } else {
            tail->next = append(a);
            tail = tail->next;
            A = A->next;
            B = B->next;
        }
    }

    while (A) {
        tail->next = append(A->data);
        tail = tail->next;
        A = A->next;
    }

    while (B) {
        tail->next = append(B->data);
        tail = tail->next;
        B = B->next;
    }

    return dummy.next;
}

int main() {
    int sizeA, sizeB;
    scanf("%d", &sizeA);
    Node* A = make_list(sizeA);

    scanf("%d", &sizeB);
    Node* B = make_list(sizeB);

    Node* U = union_(A, B);
    Node* I = intersect(A, B);

    print_list(U);
    print_list(I);

    free_list(A);
    free_list(B);
    free_list(U);
    free_list(I);

    return 0;
}