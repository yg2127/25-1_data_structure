#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* prv;
    struct Node* nxt;
} Node;

Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prv = NULL;
    node->nxt = NULL;
    return node;
}

int length(Node* h, Node* t) {
    int size = 0;
    Node* cur = h->nxt;
    while (cur != t) {
        size++;
        cur = cur->nxt;
    }
    return size;
}

void insert(Node* h, Node* t, int rank, char data) {
    int size = length(h, t);
    Node* cur = h;
    for (int i = 0; i < rank - 1; i++) {
        cur = cur->nxt;
    }

    Node* node = newNode(data);
    Node* nxt = cur->nxt;

    node->prv = cur;
    node->nxt = nxt;
    cur->nxt = node;
    nxt->prv = node;
}

void erase(Node* h, Node* t, int rank) {
    int size = length(h, t);
    Node* cur = h->nxt;
    for (int i = 0; i < rank - 1; i++) {
        cur = cur->nxt;
    }

    Node* prv = cur->prv;
    Node* nxt = cur->nxt;

    prv->nxt = nxt;
    nxt->prv = prv;

    free(cur);
}

void getVal(Node* h, Node* t, int rank) {
    Node* cur = h->nxt;
    for (int i = 0; i < rank - 1; i++) {
        cur = cur->nxt;
    }

    printf("%c\n", cur->data);
}

void show(Node* h, Node* t) {
    Node* cur = h->nxt;
    while (cur != t) {
        printf("%c", cur->data);
        cur = cur->nxt;
    }
    printf("\n");
}

int main() {
    Node* h = newNode(0);
    Node* t = newNode(0);
    h->nxt = t;
    t->prv = h;

    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char cmd;
        scanf("%c", &cmd);

        if (cmd == 'A') {
            int r;
            char e;
            scanf("%d %c", &r, &e);
            insert(h, t, r, e);
        } else if (cmd == 'D') {
            int r;
            scanf("%d", &r);
            erase(h, t, r);
        } else if (cmd == 'G') {
            int r;
            scanf("%d", &r);
            getVal(h, t, r);
        } else if (cmd == 'P') {
            show(h, t);
        }
        getchar();
    }

    Node* cur = h;
    while (cur != NULL) {
        Node* nxt = cur->nxt;
        free(cur);
        cur = nxt;
    }

    return 0;
}