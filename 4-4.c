#include <stdio.h>

int main() {
    int n, m;
    int arr[100][100] = {0};
    scanf("%d %d", &n, &m);

    int r1 = 0, r2 = n-1;
    int c1 = 0, c2 = m-1;
    int val = 1;

    while (1) {
        if (r1 > r2 || c1 > c2) {
            break;
        }

        for (int j = c1; j <= c2; j++) {
            arr[r1][j] = val;
            val++;
        }
        r1++;

        if (r1 > r2 || c1 > c2) {
            break;
        }

        for (int i = r1; i <= r2; i++) {
            arr[i][c2] = val;
            val++;
        }
        c2--;

        if (r1 > r2 || c1 > c2) {
            break;
        }

        for (int j = c2; j >= c1; j--) {
            arr[r2][j] = val;
            val++;
        }
        r2--;

        if (r1 > r2 || c1 > c2) {
            break;
        }

        for (int i = r2; i >= r1; i--) {
            arr[i][c1] = val;
            val++;
        }
        c1++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}