//
// Created by 유건 on 25. 3. 27.
//
//
// Created by 유건 on 25. 3. 27.
//
#include<stdio.h>

void swap(int *p,int a,int b){

}

int main() {
    int n, arr[100], *p, n2, x[100];

    scanf("%d", &n);

    for (int i =0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    p = arr;

    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        scanf("%d", &x[i]);
    }

    int tmp2 = *(p+x[0]);
    int tmp1;
    for (int i = 0; i < n2-1; i++) {
        tmp1 = *(p+x[i+1]);
        *(p+x[i+1]) = tmp2;
        tmp2 = tmp1;
    }

    for (int i = 0; i < n; i++) {
        printf(" %d", *(p+i));
    }
}