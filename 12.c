//
// Created by À¯°Ç on 25. 5. 22.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    struct tree* left;
    struct tree* right;
    int data;
}tree;
tree* gettree(int x, tree* left, tree* right) {
    tree* gettree = (tree*)malloc(sizeof(tree));
    gettree -> data = x;
    gettree -> left = left;
    gettree -> right = right;

    return gettree;
}

int main() {
    tree *f1, *f2, *f3, *f4, *f5, *f6, *f7, *f8;

    f4 = gettree(70, NULL, NULL);
    f5 = gettree(90, NULL, NULL);
    f7 = gettree(130, NULL, NULL);
    f8 = gettree(80, NULL, NULL);

    f2 = gettree(30, f4, f5);
    f6 = gettree(120, f7, f8);
    f3 = gettree(50, NULL, f6);
    f1 = gettree(20, f2, f3);

    tree* arr[] = {f1, f2, f3, f4, f5, f6, f7, f8};

    int id;
    scanf("%d", &id);
    if (id > 8 || id < 1) {
        printf("-1");
        return 0;
    }

    tree* curr = arr[id-1];

    if (curr -> right != NULL && curr -> left != NULL) {
        printf("%d %d %d", curr -> data, curr -> left -> data, curr -> right -> data);
    }
    else if (curr -> right != NULL && curr -> left == NULL) {
        printf("%d %d", curr -> data, curr -> right -> data);
    }
    else if (curr -> right == NULL && curr -> left != NULL) {
        printf("%d %d", curr -> data, curr -> left -> data);
    }
    else {
        printf("%d", curr -> data);
    }
    return 0;
}