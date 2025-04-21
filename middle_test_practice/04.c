//
// Created by 유건 on 25. 4. 21.
//
#include<stdio.h>
typedef struct dev {
    int d, r;
}dev;

dev devider(int a, int b) { // 몫, 나머지
    dev result;
    if (a < b) {
        result.d = 0;
        result.r = a;
        return result;
    }
    dev tmp = devider(a-b, b);
    result.d = tmp.d + 1;
    result.r = tmp.r;
    return result;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);

    dev n = devider(n1,n2);
    printf("%d %d", dev.d, dev.r);
}