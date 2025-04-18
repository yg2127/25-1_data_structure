//
// Created by 유건 on 25. 4. 17.
//
#include<stdio.h>
#include<stdlib.h>
//================기본세팅===============
typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* getnode() {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> prev = NULL;
    newnode -> next = NULL;
    return newnode;
}

void init(Node** Head, Node** Tail) {
    *Head = getnode();
    *Tail = getnode();
    (*Head) -> next = *Tail;
    (*Tail) -> prev = *Head;
}
//==========탐색======================
Node* search(Node* Head, int num) {
    Node* curr = Head;
    for (int i = 1; i < num; i++) {
        curr = curr -> next;
    }
    if (curr -> next == NULL) {
        printf("invalid position\n");
        return NULL;
    }
    return curr;
}
//===============노드추가=====================
void addnode(Node* curr, char data) {
    Node* newnode = getnode();
    newnode -> data = data;
    newnode -> prev = curr -> prev;
    newnode -> next = curr;
    curr -> prev -> next = newnode;
    curr -> prev = newnode;
}
void append(Node* Head, int num, char data) {
    Node* curr = search(Head, num);
    if (curr == NULL) {
        return;
    }
    addnode(&curr, data);
}

//============노드제거===========================
char removeNode(Node* curr) {
    char e = curr -> data;
    (curr -> prev)->next = curr -> next;
    (curr -> next) -> prev = curr -> prev;
    free(curr);
    return e;
}
char remove(Node* Head, int num) {
    Node* curr = search(Head, num);
    if (curr == NULL) {
        return '\0';
    }
    return removeNode(curr);
}
//================메인함수======================
int main() {
    int n, num;
    Node *Head, *Tail, *curr;
    init(&Head, &Tail);
    scanf("%d", &n);
    char c, data;
    int number;
    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);
        if (c == 'A') {
            scanf("%d", &num);
            scanf(" %c", &data);
            append(Head, num, data);
        }
        else if (c == 'D') {
            scanf("%d", &num);
            remove(Head, num);
        }
        else if (c == 'G') {
            scanf("%d", &num);
            curr = search(Head, num);
            if (curr != NULL) printf("%c\n", curr -> data);
        }
        else {
            curr = Head;
            while (curr -> next != NULL) {
                printf("%c", curr -> data);
                curr = curr -> next;
            }
            printf("\n");
        }
    }
}