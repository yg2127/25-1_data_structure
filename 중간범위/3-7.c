#include <stdio.h>

int hm(char *p, char a) {
    if (*p == '\0') { // arr이 마지막 문자라면?
        return 0; //
    }
    if (*p == a) { // arr 첫 번째 문자가 a 라면 (다음 문자로 넘어가기)
        return 1 + hm(p + 1, a); // 결과값에 +1
    } else { // arr 첫 번째 문자가 a가 아니면
        return hm(p + 1, a); // 결과값 반환 (다음 문자로 넘어가기)
    }
}

int main() {
    char arr[101], a;
    scanf("%s", arr);
    getchar();
    scanf("%c", &a);

    printf("%d\n", hm(arr, a));
    return 0;
}