//
// Created by À¯°Ç on 25. 3. 20.
//
#include<stdio.h>
int dev(int n) {
    if (n == 0) {
        return 0;
    }
    printf("%d\n", n % 10);
    dev(n / 10);
}
int main() {
    int n;
    scanf("%d", &n);

    dev(n);
}