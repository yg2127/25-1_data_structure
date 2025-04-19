//
// Created by À¯°Ç on 25. 4. 19.
//
#include<stdio.h>
#include<stdlib.h>

int countOnes(int **arr, int n) {
        int sum = 0, column = n-1, row = 0;

        while (column >= 0 && row < n) {
                if (arr[row][column] == 0) {
                        column--;
                }
                else if(arr[row][column] == 1){
                        sum+= (column+1);
                        row++;
                }
        }
        return sum;
}

int main() {
        int n;
        scanf("%d", &n);

        int **arr = (int**)malloc(n*sizeof(int*));

        for (int i = 0; i < n; i++) {
                arr[i] = (int*)malloc(n*sizeof(int));
        }

        for (int i = 0; i<n; i++) {
                for (int j = 0; j < n; j++) {
                        scanf("%d", &arr[i][j]);
                }
        }

        printf("%d", countOnes(arr, n));

        return 0;
}