#include <stdio.h>
#include <stdlib.h>

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

double prefixAverage2(int n, float avg, int *arr) {
    double sum = 0;
    sum += (avg*(n-1) + arr[n-1]);
    sum /= n;

    return sum;
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

    double avg = (double)arr[0];
    for (int i = 0; i < n; i++) {
        double num = prefixAverage2(i+1, avg, arr);
        avg = num;
        num += 0.5;
        int num2 = (int)num;
        printf("%d ", num2);
    }

    free(arr);
    return 0;
}