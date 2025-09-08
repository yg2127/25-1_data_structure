//
// Created by 유건 on 25. 6. 9.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    struct Node *next;
    int data;
}Node;
typedef struct Queue {
    Node *front, *rear;
    int size, max;
}Queue;
void init(Queue *q, int max) {
    q -> front = NULL;
    q -> rear = NULL;
    q -> size = 0, q -> max = max;
}

int isFull(Queue *q) {
    return(q->size == q->max);
}
int isEmpty(Queue *q) {
    return(q ->size == 0);
}

void print(Queue *q) {
    Node *current = q -> front;
    while (current != NULL) {
        printf("%d ", current -> data);
        current = current -> next;
    }
    printf("\n");
}

void insert(Queue *q, int data) {
    if (isFull(q)) {
        printf("overflow ");
        print(q);
        exit(0);
    }
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;

    if (isEmpty(q)) { // 큐가 비어있다면 새 노드를 front, rear로 지정
        q -> front = newnode;
        q -> rear = newnode;
    }
    else { // 큐에 노드가 있다면 rear만 조정
        q -> rear -> next = newnode;
        q -> rear = newnode;
    }
    q -> size++;
}
void delete(Queue *q){
    if (isEmpty(q)) {
        printf("underflow ");
        print(q);
        exit(0);
    }
    Node *tmp = q -> front;
    q -> front = q -> front -> next;
    free(tmp);
    q -> size--;
    if (isEmpty(q)) {
        q -> rear = NULL;
    }
}

