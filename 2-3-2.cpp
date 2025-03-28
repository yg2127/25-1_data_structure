//
// Created by À¯°Ç on 25. 3. 15.
//
#include<stdio.h>
#include<stdlib.h>
int prefixAverage1(int n, int *arr) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    sum /= n;
    sum+=0.5;
    sum = (int)sum;
    return sum;
}

int prefixAverage2(int n, int *arr, int *sum) {
    *sum += arr[n];

}
int main() {
    int n;
    int *arr = NULL;

    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", prefixAverage1(i+1,arr));
    }
    printf("\n");

    int sum, *psum = &sum;

    for (int i = 0; i < n; i++) {
        printf("%d ", prefixAverage2(i, arr, sum));
    }
}