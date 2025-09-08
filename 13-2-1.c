//
// Created by 유건 on 25. 6. 10.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
    struct Tree *left, *right;
    int data, id;
}Tree;
Tree *mkTree(int data, int id, Tree *left, Tree *right) {
    Tree *newtree = (Tree*)malloc(sizeof(Tree));
    newtree -> data = data;
    newtree -> id = id;
    newtree -> left = left;
    newtree -> right = right;

    return newtree;
}

int traversal_sum(Tree *t) { // preorder방식으로 순회
    if (t == NULL) return 0;

    return t -> data + traversal_sum(t -> left) + traversal_sum(t -> right);
}



int findid(Tree *root, int id) {
    if (root == NULL) return 0;
    if (root -> id == id) return traversal_sum(root);
    if (findid(root -> left, id) != 0) return findid(root -> left, id);
    return findid(root -> right, id);
}
int main() {
    Tree *t8 = mkTree(80, 8, NULL, NULL);
    Tree *t7 = mkTree(130, 7, NULL, NULL);
    Tree *t6 = mkTree(120, 6, t7, t8);
    Tree *t5 = mkTree(90, 5, NULL, NULL);
    Tree *t4 = mkTree(70, 4, NULL, NULL);
    Tree *t3 = mkTree(50, 3, NULL, t6);
    Tree *t2 = mkTree(30, 2, t4, t5);
    Tree *t1 = mkTree(20, 1, t2, t3);

    Tree *root = t1;

    int n;
    scanf("%d", &n);
    int ans = findid(root, n);
    if (!ans) printf("-1");
    else printf("%d", ans);
}