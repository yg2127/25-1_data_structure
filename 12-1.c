//
// Created by À¯°Ç on 25. 5. 22.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int  val;
    struct Tree *l, *r;
} Tree;

Tree* mkTree(int x, Tree* left, Tree* right) {
    Tree* n = malloc(sizeof(Tree));
    if (!n) exit(1);
    n->val = x;
    n->l   = left;
    n->r   = right;
    return n;
}

int main(void) {
    Tree *n4 = mkTree(70, NULL, NULL);
    Tree *n5 = mkTree(90, NULL, NULL);
    Tree *n7 = mkTree(130, NULL, NULL);
    Tree *n8 = mkTree(80, NULL, NULL);

    Tree *n2 = mkTree(30, n4, n5);
    Tree *n6 = mkTree(120, n7, n8);
    Tree *n3 = mkTree(50, NULL, n6);
    Tree *n1 = mkTree(20, n2, n3);

    Tree* arr[9] = { NULL, n1, n2, n3, n4, n5, n6, n7, n8 };

    int id;
    if (scanf("%d", &id)!=1) return 0;

    Tree* cur = (id>=1 && id<=8) ? arr[id] : NULL;
    if (!cur) {
        puts("-1");
    }
    else if (cur->l && cur->r) {
        printf("%d %d %d\n", cur->val, cur->l->val, cur->r->val);
    }
    else if (cur->l || cur->r) {
        Tree* child = cur->l ? cur->l : cur->r;
        printf("%d %d\n", cur->val, child->val);
    }
    else {
        printf("%d\n", cur->val);
    }

    return 0;
}