//
// Created by À¯°Ç on 25. 3. 20.
//
#include<stdio.h>
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    else if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a%b);
    }
}
int main() {
    int a,b;

    scanf("%d %d", &a, &b);

    printf("%d", gcd(a,b));
}