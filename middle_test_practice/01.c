//
// Created by À¯°Ç on 25. 4. 19.
//
#include<stdio.h>
#include<stdlib.h>

int findMissing(int arr[], int n) {
    int all = n * (n+1)/2;

    for (int i = 0; i < n; i++) {
        all -= arr[i];
    }

    return all;
}
int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", (arr+i));
    }

    printf("%d", findMissing(arr, n));

    free(arr);

    return 0;
}