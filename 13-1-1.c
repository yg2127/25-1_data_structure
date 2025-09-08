//
// Created by À¯°Ç on 25. 6. 10.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *left, *right;
    int data, id;
}Node;

Node *mknode(int data, int id, Node *left, Node *right) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> id = id;
    newnode -> data = data;
    newnode -> left = left;
    newnode -> right = right;

    return newnode;
}
void pre(Node *root) {
    if (root == NULL) return;
    printf(" %d", root -> data);
    pre(root -> left);
    pre(root -> right);
}
void in(Node *root) {
    if (root == NULL) return;
    in(root -> left);
    printf(" %d", root -> data);
    in(root -> right);
}
void post(Node *root) {
    if (root == NULL) return;
    post(root -> left);
    post(root -> right);
    printf(" %d", root -> data);
}

int f = 0;

void findid(Node *root, int id, int nt) {
    if (root == NULL) return;
    if (root -> id == id) {
        f = 1;
        if (nt == 1) pre(root);
        else if (nt == 2) in(root);
        else if (nt == 3) post(root);
    }
    else {
        findid(root -> left, id, nt);
        findid(root -> right , id, nt);
    }
}
int main() {
    Node *t8 = mknode(80, 8, NULL, NULL);
    Node *t7 = mknode(130, 7, NULL, NULL);
    Node *t6 = mknode(120, 6, t7, t8);
    Node *t5 = mknode(90, 5, NULL, NULL);
    Node *t4 = mknode(70, 4, NULL, NULL);
    Node *t3 = mknode(50, 3, NULL, t6);
    Node *t2 = mknode(30, 2, t4, t5);
    Node *t1 = mknode(20, 1, t2, t3);

    Node *root = t1;

    int id, nt;
    scanf("%d %d", &nt, &id);

    findid(root, id, nt);
    if (!f) printf("-1");
}
