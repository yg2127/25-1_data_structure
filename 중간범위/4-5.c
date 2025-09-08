#include <stdio.h>

int main() {
    int n, m;
    int arr[100][100] = {0};
    scanf("%d %d", &n, &m);

    int val = 1;
    for (int k = 0; k < n + m - 1; k++) {
        int x = (k < m) ? 0 : k - m + 1;
        int y = (k < m) ? k : m - 1;

        while (x < n && y >= 0) {
            arr[x][y] = val;
            val++;
            x++;
            y--;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
