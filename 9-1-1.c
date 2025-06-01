//
// Created by 유건 on 25. 5. 26.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    int n, m, top = -1, r_num;
    char l[10], data;
    scanf("%d", &n);
    char *arr = malloc(n*sizeof(char));
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++) {
        scanf("%s", l);
        if (strcmp(l, "PUSH")==0) {
            scanf(" %c", &data);
            if (top + 1 >= n) {
                printf("Stack FULL\n");
            }
            else {
                top++; // 내 top 인덱스는 항상 최상단원소를 가리키고 있음!
                arr[top] = data;
            }
        }
        else if (strcmp(l, "POP")==0) {
            if (top == -1) {
                printf("Stack Empty\n");
            }
            else {
                top--;
            }
        }
        else if (strcmp(l, "PEEK")==0) {
            if (top == -1) {
                printf("Stack Empty\n");
            }
            else {
                printf("%c\n", arr[top]);
            }
        }
        else if (strcmp(l, "DUP")==0) {
            if (top + 1 >= n) {
                printf("Stack FULL\n");
            }
            else if (top == -1) {
                printf("Stack Empty\n");
            }
            else {
                arr[top+1] = arr[top];
                top++;
            }
        }
        else if (strcmp(l, "UpR")==0) { // 아래 0 쪽에서 위로 올리는 것 맨 위의 원소는 밑으로 내려감
            if (top == -1) {
                printf("Stack Empty\n");
            }
            else {
                scanf("%d", &r_num);
                char tmp = arr[top];
                for (int p = top-1; p >= top - r_num + 1; p--) {
                    arr[p+1] = arr[p];
                }
                arr[top - r_num+1] = tmp;
            }
        }
        else if (strcmp(l, "DownR")==0) {
            if (top == -1) {
                printf("Stack_Empty\n");
            }
            else {
                scanf("%d", &r_num);
                char tmp = arr[top - r_num + 1];
                for (int p = top - r_num+1; p < top; p++) {
                    arr[p] = arr[p+1];
                }
                arr[top] = tmp;
            }
        }
        else { //print 입력되면?
            for (int i = top; i >= 0; i--) {
                printf("%c", arr[i]);
            }
            printf("\n");
        }
    }
}