//
// Created by 유건 on 25. 4. 19.
//
#include<stdio.h>

int gcd1(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd1(b, a % b);
}
int gcd2 (int a, int b) {
    if (a < b) {
        return gcd2(a, b - a);
    }
    else if (a > b) {
        return gcd2(a-b,b);
    }
    else {
        return a;
    }
}
int main() {
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
// a는 b보다 무조건 커야 함

    printf("%d\n", gcd1(n1, n2));
    printf("%d\n", gcd2(n1,n2));
}