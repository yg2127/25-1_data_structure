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
    Node *newnode =(Node*)malloc(sizeof(Node));
    newnode -> data = data, newnode -> id = id;
    newnode -> left = left, newnode -> right = right;

    return newnode;
}

int t_sum(Node *root) {
    if (root == NULL) return 0;

    return root -> data + t_sum(root -> left) + t_sum(root->right);
}

Node *findid(Node *root , int id) {
    if (root == NULL) return NULL;
    if (root -> id == id) return root;

    else if (findid(root -> left, id) != NULL) return findid(root -> left, id);
    else return findid(root -> right, id);
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

    int id;
    scanf("%d", &id);
    if (findid(root, id) == NULL) printf("-1");
    else printf("%d", t_sum(findid(root, id)));
}