#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    if (!fgets(s, sizeof(s), stdin)) return 0;
    char stack[1001];
    int top = -1;
    int count = 0;
    int balanced = 1;

    for (int i = 0; s[i] && s[i] != '\n'; i++) {
        char c = s[i];
        if (c=='(' || c==')' || c=='{' || c=='}' || c=='[' || c==']') {
            count++;
            if (c=='(' || c=='{' || c=='[') {
                stack[++top] = c;
            } else {
                if (top < 0) {
                    balanced = 0;
                    break;
                }
                char t = stack[top--];
                if (!((t=='(' && c==')') ||
                      (t=='{' && c=='}') ||
                      (t=='[' && c==']'))) {
                    balanced = 0;
                    break;
                      }
            }
        }
    }

    if (balanced && top >= 0) balanced = 0;

    if (balanced)
        printf("OK_%d\n", count);
    else
        printf("Wrong_%d\n", count);
}