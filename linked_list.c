//
// Created by 유건 on 25. 4. 6.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // 구조체 노드 선언
    int data;
    struct Node* next;
} Node;

// 특정 값 뒤에 새 노드를 삽입하는 함수
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
    printf("삽입 실패: %d를 찾을 수 없습니다.\n", target);
}

// 특정 값을 가진 노드를 삭제하는 함수
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
    printf("삭제 실패: %d를 찾을 수 없습니다.\n", target);
}

void free_list(Node* head) { // 동적할당 해제
    Node* curr = head;
    Node* next_node;

    while (curr != NULL) {
        next_node = curr->next;  // 다음 노드를 기억해두고
        free(curr);              // 현재 노드를 해제
        curr = next_node;        // 다음 노드로 이동
    }
}
int main() {

    Node* head = NULL;
    Node* tail = NULL;
    int val;

    while (1) { // 연결리스트를 입력받는 코드
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

    // 연결리스트 출력코드
    Node* curr = head;
    while (curr != NULL) {
        printf("%d → ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");

    free_list(head);

    return 0;
}