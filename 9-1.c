#include <stdio.h>
#include <string.h>
#define MAX 100

char stack_arr[MAX];
int top_idx = -1;
int capacity;

void do_push(char c) {
    if (top_idx >= capacity - 1) {
        printf("Stack FULL\n");
    } else {
        stack_arr[++top_idx] = c;
    }
}

void do_pop() {
    if (top_idx >= 0) {
        top_idx--;
    }
    else printf("Stack Empty");
}

void do_peek() {
    if (top_idx < 0) {
        printf("Stack Empty\n");
    } else {
        printf("%c\n", stack_arr[top_idx]);
    }
}

void do_dup() {
    if (top_idx < 0) {
        printf("Stack Empty\n");
    } else if (top_idx >= capacity - 1) {
        printf("Stack FULL\n");
    } else {
        char tmp = stack_arr[top_idx];
        stack_arr[++top_idx] = tmp;
    }
}

void do_up_rotate(int n) {
    if (n > top_idx + 1) return;
    char tmp = stack_arr[top_idx];
    for (int i = 0; i < n - 1; i++) {
        stack_arr[top_idx - i] = stack_arr[top_idx - i - 1];
    }
    stack_arr[top_idx - n + 1] = tmp;
}

void do_down_rotate(int n) {
    if (n > top_idx + 1) return;
    char tmp = stack_arr[top_idx - n + 1];
    for (int i = top_idx - n + 1; i < top_idx; i++) {
        stack_arr[i] = stack_arr[i + 1];
    }
    stack_arr[top_idx] = tmp;
}

void do_print() {
    for (int i = top_idx; i >= 0; i--) {
        putchar(stack_arr[i]);
    }
    putchar('\n');
}

int main() {
    int cmd_count;
    scanf("%d", &capacity);
    scanf("%d", &cmd_count);
    getchar();
    for (int i = 0; i < cmd_count; i++) {
        char op[10];
        scanf("%s", op);
        if (strcmp(op, "PUSH") == 0) {
            char ch;
            scanf(" %c", &ch);
            do_push(ch);
        } else if (strcmp(op, "POP") == 0) {
            do_pop();
        } else if (strcmp(op, "PEEK") == 0) {
            do_peek();
        } else if (strcmp(op, "DUP") == 0) {
            do_dup();
        } else if (strcmp(op, "UpR") == 0) {
            int n;
            scanf("%d", &n);
            do_up_rotate(n);
        } else if (strcmp(op, "DownR") == 0) {
            int n;
            scanf("%d", &n);
            do_down_rotate(n);
        } else if (strcmp(op, "PRINT") == 0) {
            do_print();
        }
    }
    return 0;
}