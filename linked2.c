#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int num;
    struct Node* next;
}Node;

Node* Head = NULL; // 첫번째 노드를 의미
Node* Tail = NULL; // 맨 마지막 노드를 의미

int main() {
    int pre;
    while (1) {
        scanf("%d", &pre);
        if (pre < 0) break;

        Node *Newnode = (Node*)malloc(sizeof(Node));

        Newnode -> num = pre;
        Newnode -> next = NULL;


    }
}