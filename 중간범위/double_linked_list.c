//
// Created by 유건 on 25. 4. 14.
//
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    struct Node* next;
    char data;
    struct Node* prev;
}Node;
Node* getnode() { // 동적할당 함수
    Node* newnode = (Node*)malloc(sizeof(Node)); // 동적할당
    newnode -> prev = NULL; // 이전 노드 NULL 처리
    newnode -> next = NULL; // 다음 노드 NULL 처리
    return newnode; // 노드 반환
}
Node* init(Node** Head, Node** Tail) {
    *Head = getnode();
    *Tail = getnode();
    (*Head)->next = *Tail;
    (*Tail)->prev = *Head;
    return *Head;
}
//===================================================================================
Node* search(Node* Head, int n) {
    Node* curr = Head -> next;
    for (int i = 1; i < n; i++) { // 포인터를 n번째 노드로 지정 (1이면 해드노드 그대로)
        curr = curr -> next;

        if (curr == NULL) {
            printf("invalid position\n");
            return NULL;
        }
    }

    return curr;
}
void insert(Node* Head, int n, char x) { // 삽입함수

    Node* curr = search(Head, n);
    if (curr == NULL) return;
    Node* newnode = getnode(); // 동적할당 받은 새 노드
    newnode -> next = curr;
    newnode -> prev = curr->prev;
    if (newnode->prev != NULL)
        newnode->prev->next = newnode;
    else
        Head = newnode;
    (newnode -> next) -> prev = newnode;
    newnode -> data = x;
}
void delete(Node* Head, int n){
    Node* curr = search(Head, n);
    if (curr == NULL) return;

    (curr -> prev) -> next = curr -> next;
    (curr -> next) -> prev = curr -> prev;
    free(curr);
}
void get(Node* Head, int n) {
    Node* curr = search(Head, n);
    if (curr == NULL) return;

    printf("%c", curr->data);
}
void print(Node* Head) {
    Node* curr = Head;
    if (curr == NULL) return;

    while (curr != NULL) {
        printf("%c", curr -> data);
        curr = curr -> next;
    }
}
//=====================================================================================
int main() {
    Node* Head = NULL;
    Node* Tail = NULL;
    Head = init(&Head, &Tail);
    int n, n1;
    char c, c1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%c", &c);
        if (c == 'A') {
            scanf("%d", &n1);
            getchar();
            scanf("%c", &c1);
            insert(Head, n1, c1);
        }
        else if (c == 'D') {
            scanf("%d", &n1);
            delete(Head, n1);
        }
        else if (c == 'G') {
            scanf("%d", &n1);
            get(Head, n1);
        }
        else {
            print(Head);
        }
    }

}