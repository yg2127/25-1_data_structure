#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    int top, size;
    char *data;
}Stack;
void init(Stack *s, int max) {
    s -> top = -1;
    s -> size = max;
    s -> data = (char*)malloc(max*sizeof(char));
}

void push(Stack *s, char value) {
    s -> top++;
    s -> data[s -> top] = value;
}
char pop(Stack *s) {
    return s -> data[s -> top--];
}
char peek(Stack *s) {
    return s -> data[s -> top];
}

int pri(char val) {
    if (val == '!') return 6;
    else if (val == '*' || val == '/') return 5;
    else if (val == '+' || val == '-') return 4;
    else if (val == '<' || val == '>') return 3;
    else if (val == '&') return 2;
    else if (val == '|') return 1;
}

void rtop(char *rda, char *pda) {
    Stack s1, *s = &s1;
    init(s, strlen(rda));
    int nr=0, np=0;

    for (nr = 0; nr < strlen(rda); nr++) {
        if ('A' <= rda[nr] && rda[nr] <= 'Z') {
            pda[np++] = rda[nr];
            continue;
        }
        else if (rda[nr] == '(') {
            push(s, rda[nr]);
            continue;
        }
        else if (rda[nr] == ')') {
            while (peek(s) != '(') {
                pda[np++] = pop(s);
            }
            pop(s);
            continue;
        }
        else if (rda[nr] == '&' || rda[nr] == '|') nr++;

        while (pri(peek(s))>pri(rda[nr])) {
            pda[np++] = pop(s);
        }
        push(s, rda[nr]);
    }
    while (s -> top != -1) {
        pda[np++] = pop(s);
    }
}
int main() {
    char rdata[100], pdata[100];
    int n;

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%s", rdata);
        getchar();
        rtop(rdata, pdata);
        printf("%s\n", pdata);
    }
}