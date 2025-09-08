#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int top, size;
    char *data;
}Stack;

void init(Stack *s, int Maxsize) {
    s -> data = (char*)malloc(Maxsize*sizeof(char));
    s -> top = -1;
    s -> size = Maxsize;
}
int isFull(Stack *s) {
    return (s -> top + 1 == s -> size);
}
int isEmpty(Stack *s) {
    return (s -> top == -1);
}
void push(Stack *s, char data) {
    if (isFull(s)) printf("Stack Full\n");
    else {
        s -> top++;
        s -> data[s -> top] = data;
    }
}
void pop(Stack *s) {
    if (isEmpty(s)) printf("Stack Empty\n");
    else {
        s -> top--;
    }
}
void peek(Stack *s) {
    if (isEmpty(s)) printf("Stack Empty\n");
    else printf("%c", s -> data[s -> top]);
}
void dup(Stack *s) {
    if (isFull(s)) printf("Stack Full\n");
    else push(s, s -> data[s -> top]);
}
void uprotate(Stack *s, int rn) {
    char tmp = s -> data[s -> top];
    for (int i = s -> top - 1; i > s -> top - rn; i--) {
        s -> data[i] = s -> data[i-1];
    }
    s -> data[s -> top - rn] = tmp;
}
void downrotate(Stack *s, int rn) {
    char tmp = s -> data[s -> top - rn];
    for (int i = s -> top - rn; i < s -> top - 1; i++) {
        s -> data[i] = s -> data[i+1];
    }
    s -> data[s -> top] = tmp;
}
void print(Stack *s) {
    if (isEmpty(s)) printf("Stack Empty\n");
    else {
        for (int i = s -> top; i >= 0; i--) {
            printf("%c", s -> data[i]);
        }
        printf("\n");
    }
}
int main() {
    int ns, nf, rn;
    char str[10], data;
    scanf("%d %d", &ns, &nf);
    getchar();
    Stack s1;
    Stack *s = &s1;
    init(s, ns);
    for (int i = 0; i < nf; i++) {
        scanf("%s", str);
        if (strcmp(str,"POP")==0) {
            pop(s);
        }
        else if (strcmp(str,"PUSH")==0) {
            getchar();
            scanf("%c", &data);
            push(s, data);
        }
        else if (strcmp(str,"PEEK")==0) {
            peek(s);
        }
        else if (strcmp(str,"DUP")==0) {
            dup(s);
        }
        else if (strcmp(str,"UpR")==0) {
            scanf("%d", &rn);
            uprotate(s, rn);
        }
        else if (strcmp(str,"DownR")==0) {
            scanf("%d", &rn);
            downrotate(s, rn);
        }
        else if (strcmp(str,"PRINT")==0) {
            print(s);
        }
    }
}