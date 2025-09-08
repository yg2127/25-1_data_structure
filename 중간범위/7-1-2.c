//
// Created by 유건 on 25. 4. 21.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node* getnode() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> next = NULL;

    return newNode;
}
int contain (Node* set, int data) { // *정상작동*
    Node* curr = set;
    while (curr != NULL) {
        if (curr -> data == data) return 1; // 포함되어있음
        curr = curr -> next;
    }
    return 0; // 포함되어있지 않음
}
Node* add(Node* set, int data) { // *정상작동*
    if (contain(set, data)) return set;

    Node* newnode = getnode();
    newnode -> data = data;
    newnode -> next = set;

    return newnode;
}

void subset(Node* setA, Node* setB) {
    Node *curr_A = setA;
    int p = 0;
    while (curr_A != NULL) {
        if (contain(setB, curr_A -> data)) {
            curr_A = curr_A -> next;
        }
        else {
            printf("%d ", curr_A -> data);
            curr_A = curr_A -> next;
            p = 1;
        }
    }

    if (p == 0) printf("0");
}

int main() {
    int nA, nB, data;
    Node* setA = NULL, *setB = NULL;

    scanf("%d", &nA);
    for (int i = 0; i < nA; i++) {
        scanf("%d", &data);
        setA = add(setA, data);
    }
    scanf("%d", &nB);
    for (int i = 0; i < nB; i++) {
        scanf("%d", &data);
        setB = add(setB, data);
    }
    subset(setA, setB);

}