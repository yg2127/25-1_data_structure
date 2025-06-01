//
// Created by À¯°Ç on 25. 5. 22.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    struct Node *next, *prev;
    int data;
}Node;

Node* getnode() {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}
Node* init(Node** front, Node** rear) {
    *front = getnode();
    *rear = getnode();
    (*front) -> next = *rear;
    (*rear)->prev = *front;
    return *front;
}
int main() {
    Node* front = NULL;
    Node* rear = NULL;
    front = init(&front, &rear);

    int n;
    scanf("%d", &n);
    int data;
    char c[2];
    for (int i = 0; i < n; i++) {
        scanf("%s", c);
        if (strcmp(c, "AF")==0) {
            scanf("%d", &data);
            Node* newnode = getnode();
            newnode -> data = data;
            newnode -> prev = NULL;
            newnode -> next = front;

        }
        else if (strcmp(c, "AR")==0) {
            scanf("%d", &data);
            Node* newnode = getnode();
            newnode -> data = data;
        }
        else if (strcmp(c, "DF")==0) {

        }
        else if (strcmp(c, "DR")==0) {

        }
        else {

        }
    }
}