//
// Created by 유건 on 25. 6. 1.
//
//
// Created by 유건 on 25. 5. 30.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
    int data, id;
    struct Tree *left, *right;
}Tree;

Tree *makeTree(int d, int id, Tree *L, Tree *R) {
    Tree *n = (Tree*)malloc(sizeof(Tree));
    if (!n) exit(1);
    n -> data = d;
    n -> id = id;
    n -> left = L;
    n -> right = R;
    return n;
}
int sumSubtree(Tree *node) {
    if (node == NULL) return 0;
    int leftSum  = sumSubtree(node->left);
    int rightSum = sumSubtree(node->right);
    return leftSum + rightSum + node->data;
}
Tree* findid(Tree *node, int id1) {
    if (node == NULL) return NULL;
    if (node -> id == id1) {
        return node;
    }
    Tree *found = findid(node -> left, id1);
    if (found != NULL) return found;
    return findid(node -> right, id1);
}
int main() {
    Tree *n8 = makeTree(80, 8, NULL, NULL);
    Tree *n7 = makeTree(130, 7, NULL, NULL);
    Tree *n6 = makeTree(120, 6, n7, n8);
    Tree *n3 = makeTree(50, 3, NULL, n6);
    Tree *n4 = makeTree(70, 4, NULL, NULL);
    Tree *n5 = makeTree(90, 5, NULL, NULL);
    Tree *n2 = makeTree(30, 2, n4, n5);
    Tree *n1 = makeTree(20, 1, n2, n3);

    int nA;

    scanf("%d", &nA);

    Tree* target = findid(n1, nA);
    if (target == NULL) printf("-1");
    else {
        printf("%d", sumSubtree(target));
    }
}