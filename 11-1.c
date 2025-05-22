//
// Created by À¯°Ç on 25. 5. 15.
//
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int q, n;
    if (scanf("%d", &q) != 1) return 0;
    if (scanf("%d", &n) != 1) return 0;

    int *data = calloc(q, sizeof(int));
    if (!data) return 0;

    int front = 0, rear = 0;

    for (int i = 0; i < n; ++i) {
        char cmd;
        scanf(" %c", &cmd);

        if (cmd == 'I') {
            int value;
            scanf("%d", &value);

            int next_rear = (rear + 1) % q;
            if (next_rear == front) {
                printf("overflow ");
                for (int j = 0; j < q; ++j) {
                    printf("%d", data[j]);
                    if (j + 1 < q) printf(" ");
                }
                return 0;
            }

            rear = next_rear;
            data[rear] = value;

        } else if (cmd == 'D') {
            if (front == rear) {
                printf("underflow");
                return 0;
            }
            front = (front + 1) % q;
            data[front] = 0;

        } else if (cmd == 'P') {
            for (int j = 0; j < q; ++j) {
                printf("%d", data[j]);
                if (j + 1 < q) printf(" ");
            }
            putchar('\n');
        }
    }

    return 0;
}