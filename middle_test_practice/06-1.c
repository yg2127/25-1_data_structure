//
// Created by À¯°Ç on 25. 4. 21.
//
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    struct Node* next;
    int coef, exp;
}Node;

Node* getnode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> next = NULL;
    return newNode;
}

void addTerm(Node* Head, int c, int e) {
    Node* curr = Head;
    while (curr -> next != NULL) {
        curr = curr -> next;
    }

    Node* newnode = getnode();
    newnode -> coef = c;
    newnode -> exp = e;
    curr -> next = newnode;
}

void addpoly(Node* Head1, Node* Head2, Node* Head3) {
    Node* curr1 = Head1 -> next, *curr2 = Head2 -> next;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1 -> exp > curr2 -> exp) {
            addTerm(Head3,curr1 -> coef, curr1-> exp);
            curr1 = curr1 -> next;
        }
        else if (curr1 -> exp < curr2 -> exp) {
            addTerm(Head3, curr2 -> coef, curr2 -> exp);
            curr2 = curr2 -> next;
        }
        else {
            if (curr1 -> coef + curr2 -> coef != 0) {
                addTerm(Head3, curr1 -> coef + curr2 -> coef, curr1->exp);
                curr1 = curr1 -> next;
                curr2 = curr2 -> next;
            }
        }
    }
    while (curr1 != NULL) {
        addTerm(Head3, curr1 -> coef, curr1->exp);
        curr1 = curr1 -> next;
    }
    while (curr2 != NULL) {
        addTerm(Head3, curr2 -> coef, curr2->exp);
        curr2 = curr2 -> next;
    }
}

int main() {
    Node* HeadA, *HeadB, *HeadC;
    HeadA = getnode();
    HeadB = getnode();
    HeadC = getnode();

    int nA, nB, co, ex;

    scanf("%d", &nA);
    for (int i = 0; i < nA; i++) {
        scanf("%d", &co);
        scanf("%d", &ex);
        addTerm(HeadA, co, ex);
    }
    scanf("%d", &nB);
    for (int i = 0; i < nB; i++) {
        scanf("%d", &co);
        scanf("%d", &ex);
        addTerm(HeadB, co, ex);
    }
    addpoly(HeadA,HeadB,HeadC);

}