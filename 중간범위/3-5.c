#include <stdio.h>

void H(int c, char s, char m, char e) {
    if (c == 1) {
        printf("%c %c\n", s, e);
        return;
    }

    H(c - 1, s, e, m);
    printf("%c %c\n", s, e);
    H(c - 1, m, s, e);
}

void G(int c) {
    H(c, 'A', 'B', 'C');
}

int main() {
    int d;
    scanf("%d", &d);

    G(d);

    return 0;
}