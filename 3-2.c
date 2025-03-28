//
// Created by À¯°Ç on 25. 3. 20.
//
#include<stdio.h>
int dev(int n) {
    if (n == 0) {
        return 0;
    }
    dev(n / 10);
    n %= 10;
    printf("%d\n", n);
}
int main() {
    int n;
    scanf("%d", &n);

    dev(n);
}