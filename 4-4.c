#include <stdio.h>

int main() {
    int N, M;
    int arr[100][100] = {0};
    scanf("%d %d", &N, &M);

    int top = 0, bottom = N - 1;
    int left = 0, right = M - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j)
            arr[top][j] = num++;
        top++;

        for (int i = top; i <= bottom; ++i)
            arr[i][right] = num++;
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; --j)
                arr[bottom][j] = num++;
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                arr[i][left] = num++;
            left++;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}