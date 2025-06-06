

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000

// ==========================
typedef struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
} Tree;

// ==========================
Tree *makeTree(int d, Tree *L, Tree *R) {
    Tree *n = (Tree*)malloc(sizeof(Tree));
    if (n == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }
    n->data  = d;
    n->left  = L;
    n->right = R;
    return n;
}

// ==========================
int N;
int triples[MAX_N][3];
int curIndex = 0;

// ==========================
Tree* BuildTree() {
    int x  = triples[curIndex][0];  // 노드 번호
    int yl = triples[curIndex][1];  // 왼쪽 자식 번호 (0이면 없음)
    int zr = triples[curIndex][2];  // 오른쪽 자식 번호 (0이면 없음)

    Tree *node = makeTree(x, NULL, NULL);

    if (yl != 0) {
        curIndex++;
        node->left = BuildTree();
    }

    if (zr != 0) {
        curIndex++;
        node->right = BuildTree();
    }

    return node;
}

// ==========================
void PrintPath(Tree *root, const char *path) {
    Tree *cur = root;
    // 1) 루트 방문
    printf("%d", cur->data);

    // 2) 문자열 한 글자씩 따라가며 방문할 때마다 data 출력
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == 'L') {
            cur = cur->left;
        }
        else if (path[i] == 'R') {
            cur = cur->right;
        }
        // “유효하지 않은 경로”는 입력으로 주어지지 않는다고 가정합니다.
        printf(" %d", cur->data);
    }
    printf("\n");
}

// ==========================

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        triples[i][0] = x;
        triples[i][1] = y;
        triples[i][2] = z;
    }

    curIndex = 0;
    Tree *root = BuildTree();

    int s;
    scanf("%d", &s);

    char path[101];
    for (int i = 0; i < s; i++) {
        scanf("%s", path);
        PrintPath(root, path);
    }

    return 0;
}