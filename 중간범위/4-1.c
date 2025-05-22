//
// Created by À¯°Ç on 25. 3. 27.
//
#include<stdio.h>

void swap(int *X,int a,int b){
    int rep = (b - a)/2+1,tmp;
    for(int i=0;i<rep;i++){
        tmp = X[a+i];
        X[a+i] = X[b-i];
        X[b-i] = tmp;
    }
}

int main() {
    int n, arr[100], *p, n2, a,b;

    scanf("%d", &n);

    for (int i =0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    p = arr;

    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        scanf("%d",&a);
        scanf("%d",&b);
        swap(p,a,b);
    }

    for (int i = 0; i < n; i++) {
        printf(" %d", *(p+i));
    }
}