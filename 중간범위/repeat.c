#include<stdio.h>

int mostones(int arr[][100],int n) {
    int i = 0, j = 0, row = 0;
    while (i < n & j < n) {
        if (arr[i][j] == 0) {
            i++;
        }
        else {
            row = i;
            j++;
        }
    }
    return row;
}
int main(){
    int arr[100][100], n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d", mostones(arr, n));
}

/*
8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0

*/