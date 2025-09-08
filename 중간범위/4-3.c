//
// Created by À¯°Ç on 25. 3. 27.
//
#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) {
                printf("%d ", i*n+j+1);
            }
            else {
                printf("%d ", (i+1)*n-j);
            }
        }
        printf("\n");
    }
}