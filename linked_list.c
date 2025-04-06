//
// Created by ���� on 25. 4. 6.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // ����ü ��� ����
    int data;
    struct Node* next;
} Node;

// Ư�� �� �ڿ� �� ��带 �����ϴ� �Լ�
void insert_after(Node* head, int target, int new_data) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == target) {
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->data = new_data;
            new_node->next = curr->next;
            curr->next = new_node;
            return;
        }
        curr = curr->next;
    }
    printf("���� ����: %d�� ã�� �� �����ϴ�.\n", target);
}

// Ư�� ���� ���� ��带 �����ϴ� �Լ�
void delete_value(Node** head_ref, int target) {
    Node* curr = *head_ref;
    Node* prev = NULL;

    while (curr != NULL) {
        if (curr->data == target) {
            if (prev == NULL) {
                *head_ref = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("���� ����: %d�� ã�� �� �����ϴ�.\n", target);
}

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