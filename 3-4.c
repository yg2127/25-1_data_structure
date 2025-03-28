//
// Created by À¯°Ç on 25. 3. 20.
//
#include<stdio.h>

int max(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    } else {
        int x = max(arr, n - 1);
        return (x > arr[n - 1] ? x : arr[n - 1]);
    }
}

int main() {
    int arr[20], n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", max(arr, n));
}