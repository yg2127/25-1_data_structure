#include <stdio.h>

int hm(char *p, char a) {
    if (*p == '\0') {
        return 0;
    }
    if (*p == a) {
        return 1 + hm(p + 1, a);
    } else {
        return hm(p + 1, a);
    }
}

int main() {
    char arr[101], a;
    scanf("%s", arr);
    getchar();
    scanf("%c", &a);

    printf("%d\n", hm(arr, a));
    return 0;
}