//
// Created by À¯°Ç on 25. 6. 8.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *data, front, rear, size;
}Queue;

void init(Queue *q, int max) {
    q -> data = (int*)malloc(max*sizeof(int));

    q -> front = 0;
    q -> rear = 0;
    q -> size = max;
}

int isEmpty(Queue *q) {
    return (q -> front == q -> rear);
}
int isFull(Queue *q) {
    return (q -> front == (q -> rear + 1)% q -> size);
}
void print(Queue *q) {
    for (int i = 0; i < q -> size; i++) {
        printf("%d ", q -> data[i]);
    }
}
void insert(Queue *q, int value) {
    if (isFull(q)) {
        printf("overflow");
        print(q);
        exit(0);
    }
    q -> data[q -> rear] = value;
    q -> rear = (q -> rear + 1) % q -> size;
}

void delete (Queue *q){
    if (isEmpty(q)) {
        printf("underflow");
        exit(0);
    }
    q -> data[q -> front] = 0;
    q -> front = (q -> front + 1) % q -> size;
}

int main() {

}