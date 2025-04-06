//
// Created by ���� on 25. 4. 6.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // ����ü ��� ����
    int data;
    struct Node* next;
} Node;

void free_list(Node* head) { // �����Ҵ� ����
    Node* curr = head;
    Node* next_node;

    while (curr != NULL) {
        next_node = curr->next;  // ���� ��带 ����صΰ�
        free(curr);              // ���� ��带 ����
        curr = next_node;        // ���� ���� �̵�
    }
}
int main() {

    Node* head = NULL;
    Node* tail = NULL;
    int val;

    while (1) { // ���Ḯ��Ʈ�� �Է¹޴� �ڵ�
        scanf("%d", &val);
        if (val == -1) break;

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = val;
        new_node->next = NULL;

        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // ���Ḯ��Ʈ ����ڵ�
    Node* curr = head;
    while (curr != NULL) {
        printf("%d �� ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");

    free_list(head);

    return 0;
}