#include<stdio.h>
#include <stdlib.h>

typedef struct{
    char name[8];
    int score1, score2, score3;
    float avg;
}student;
int main() {
    int n;
    scanf("%d", &n);

    student* s = (student*)malloc(n*sizeof(student));

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", s[i].name, &s[i].score1, &s[i].score2, &s[i].score3);
        s[i].avg = (s[i].score1+s[i].score2+s[i].score3)/3.0;
    }

    for (int j = 0; j < n; j++) {
        printf("%s %.1f ", s[j].name, s[j].avg);
        if (s[j].score1 >= 90 || s[j].score2 >= 90 || s[j].score3 >= 90) {
            printf("GREAT ");
        }
        if (s[j].score1 <= 70 || s[j].score2 <= 70 || s[j].score3 <= 70) {
            printf("BAD ");
        }
        printf("\n");
    }
}