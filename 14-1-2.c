//
// Created by À¯°Ç on 25. 6. 10.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    struct Node *left, *right;
    int data;
}Node;
Node *mknode(int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;

    return newnode;
}

int data[100][3];
int curr = 0;

Node *mktree() {
    int rootd = data[curr][0];
    int leftd = data[curr][1];
    int rightd = data[curr][2];

    curr++;

    Node *newnode = mknode(rootd);
    if (leftd != 0) newnode -> left = mktree();
    if (rightd != 0) newnode -> right = mktree();

    return newnode;
}

void pass(Node *root, char *arr) {
    Node *curr = root;
    for (int i = 0; i < strlen(arr); i++) {
        if (arr[i] == 'R') {
            printf(" %d", curr -> data);
            curr = curr -> right;
        }
        else {
            printf(" %d", curr -> data);
            curr = curr -> left;
        }
    }
    printf(" %d\n", curr -> data);
}

int main() {
    int n1, n2;
    char arr[100];
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d %d %d", &data[i][0], &data[i][1], &data[i][2]);
    }
    Node *root = mktree();
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%s", arr);
        pass(root, arr);
    }
}