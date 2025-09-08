//
// Created by 유건 on 25. 5. 26.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    struct Node* next, *prev;
    int data;
}Node;
typedef struct Queue {
    Node *front, *rear;
    int size;
}Queue;
void init(Queue *q) {
    q -> front = NULL, q -> rear = NULL;
    q -> size = 0;
}
Node* mknode(int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}

int isEmpty(Queue *q) {
    return (q -> size == 0);
}

void af(Queue *q, int data) { // front 에 추가!
    Node* newnode = mknode(data);

    if (isEmpty(q)) {
        q -> front = newnode;
        q -> rear = newnode;
    }
    else {
        newnode -> next = q -> front;
        q -> front -> prev = newnode;
        q -> front = newnode;
    }
    q -> size++;
}

void ar(Queue *q, int data) { // front 에 추가!
    Node* newnode = mknode(data);

    if (isEmpty(q)) {
        q -> front = newnode;
        q -> rear = newnode;
    }
    else {
        q -> rear -> next = newnode;
        newnode -> prev = q -> rear;
        q -> rear = newnode;
    }
    q -> size++;
}

void df(Queue *q) {
    if (isEmpty(q)) {
        printf("underflow\n");
        exit(0);
    }
    Node *tmp = q -> front;
    q -> front = q -> front -> next;
    free(tmp);
    q -> size--;
    if (isEmpty(q)) q -> rear = NULL;
    else q -> front -> prev = NULL;
}
void dr(Queue *q) {
    if (isEmpty(q)) {
        printf("underflow\n");
        exit(0);
    }
    Node *tmp = q -> rear;
    q -> rear = q -> rear -> prev;
    free(tmp);
    q -> size--;
    if (isEmpty(q)) q -> front = NULL;
    else q -> rear -> next = NULL;
}

void print(Queue *q) {
    Node *curr = q -> front;
    while (curr != NULL) {
        printf(" %d", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}

int main() {
    Queue q1, *q = &q1;
    init(q);
    char arr[10];
    int n, data;
    scanf("%d", &n);
    for (int i = 0;  i < n; i++) {
        scanf("%s", arr);
        if (strcmp(arr, "AF") == 0) {
            scanf("%d", &data);
            getchar();
            af(q,data);
        }
        else if (strcmp(arr, "AR")==0) {
            scanf("%d", &data);
            getchar();
            ar(q, data);
        }
        else if (strcmp(arr, "DF")==0) {
            df(q);
        }
        else if (strcmp(arr, "DR")==0) {
            dr(q);
        }
        else if (strcmp(arr, "P") == 0) {
            print(q);
        }
    }
}