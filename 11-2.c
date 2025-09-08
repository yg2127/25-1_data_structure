//
// Created by À¯°Ç on 25. 5. 15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNode {
    int value;
    struct DNode *left, *right;
} DNode;

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    DNode *front = NULL, *rear = NULL;
    char cmd[3];

    for (int i = 0; i < n; i++) {
        scanf("%2s", cmd);

        if (strcmp(cmd, "AF") == 0) {
            int x;
            scanf("%d", &x);
            DNode *newN = malloc(sizeof(DNode));
            newN->value = x;
            newN->left = newN->right = NULL;

            if (!front) {
                front = rear = newN;
            } else {
                newN->right = front;
                front->left = newN;
                front = newN;
            }

        } else if (strcmp(cmd, "AR") == 0) {
            int x;
            scanf("%d", &x);
            DNode *newN = malloc(sizeof(DNode));
            newN->value = x;
            newN->left = newN->right = NULL;

            if (!rear) {
                front = rear = newN;
            } else {
                newN->left = rear;
                rear->right = newN;
                rear = newN;
            }

        } else if (strcmp(cmd, "DF") == 0) {
            if (!front) {
                printf("underflow");
                return 0;
            }
            DNode *tmp = front;
            front = front->right;
            if (front) front->left = NULL;
            else       rear = NULL;
            free(tmp);

        } else if (strcmp(cmd, "DR") == 0) {
            if (!rear) {
                printf("underflow");
                return 0;
            }
            DNode *tmp = rear;
            rear = rear->left;
            if (rear) rear->right = NULL;
            else      front = NULL;
            free(tmp);

        } else if (strcmp(cmd, "P") == 0) {
            DNode *cur = front;
            while (cur) {
                printf("%d", cur->value);
                if (cur->right) putchar(' ');
                cur = cur->right;
            }
            putchar('\n');
        }
    }

    return 0;
}