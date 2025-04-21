//
// Created by 유건 on 25. 4. 21.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *prev, *next;
    char data;
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

    (*Head) -> next = (*Tail);
    (*Tail) -> prev = (*Head);
}
//============================================================================================
Node* search(Node* Head, Node* Tail, int l_n) { // 더미노드만 있을 때 1 입력시 Tail 반환
    Node* curr = Head;
    for (int i = 0; i < l_n; i++) {
        curr = curr -> next;
    }
    if (curr == NULL || curr == Head) {
        return NULL;
    }
    return curr; // Head 앞 노드 ~ Tail 노드까지 반환가능
}
Node* add(Node* Head, Node* Tail, int l_n, char data) { // l_n 위치의 노드를 뒤로 밀어내고 삽입
    Node* curr = search(Head, Tail, l_n); // 해당 노드 앞에 삽입해야함
    Node* newnode = getnode();
    if (curr == NULL) {
        printf("invalid position\n");
        return Head;
    }

    newnode -> data = data;

    newnode -> next = curr;
    newnode -> prev = curr -> prev;
    curr -> prev -> next = newnode;
    curr -> prev = newnode;

    return Head;
}
Node* delete(Node* Head, Node* Tail, int l_n){
    Node* curr = search(Head, Tail, l_n);
    if (curr == Tail || curr == NULL) {
        printf("invalid position\n");
        return Head;
    }
    curr -> prev -> next = curr -> next;
    curr -> next -> prev = curr -> prev;
    free(curr);
    return Head;
}
void get(Node* Head, Node* Tail, int l_n) {
    Node* curr = search(Head, Tail, l_n);
    if (curr == NULL||curr == Tail) {
        printf("invalid position\n");
        return;
    }

    printf("%c\n", curr -> data);
}
void print(Node* Head, Node* Tail) {
    Node* curr = Head -> next;
    while (curr != Tail) {
        printf("%c", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}
//=============================================================================================
int main() {
    Node* Head, *Tail;
    init(&Head, &Tail);

    int n, l_n;
    char data, Adt;

    scanf("%d", &n);
    for (int i =0; i < n; i++) {

        scanf(" %c", &Adt);
        if (Adt == 'A') {
            scanf("%d", &l_n);
            scanf(" %c", &data);
            Head = add(Head, Tail, l_n, data);
        }
        else if (Adt == 'D') {
            scanf("%d", &l_n);
            Head = delete(Head, Tail, l_n);
        }
        else if (Adt == 'G') {
            scanf("%d", &l_n);
            get(Head, Tail, l_n);
        }
        else {
            print(Head, Tail);
        }
    }
}