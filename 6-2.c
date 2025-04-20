//
// Created by 유건 on 25. 4. 20.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *next;
    int coef, exp;
}Node;

Node* getnode() {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> next = NULL;
    return newnode;
}
void init(Node **Head, Node **Tail) {
    *Head = getnode();
    *Tail = getnode();
    (*Head) -> next = (*Tail);
}
//============================================================================
Node* searchlast(Node* Head, Node* Tail) { //범위 = Head ~ Tail 전 노드
    Node* curr = Head;
    while (curr -> next != Tail) {
        curr = curr -> next;
    }
    return curr;
}
void appendTerm(Node* Head, Node* Tail, int coef1, int exp1) { // search 바로 다음노드에 노드추가
    Node* newnode = getnode(), *curr;

    newnode -> coef = coef1;
    newnode -> exp = exp1;

    curr = searchlast(Head, Tail);

    curr -> next = newnode;
    newnode -> next = Tail;
}

void addPoly(Node* Head1, Node* Tail1, Node* Head2, Node* Tail2, Node* Head3, Node* Tail3) {
    Node *curr1 = Head1, *curr2 = Head2, *curr3 = Head3;
    int sum_c, sum_e;
    // Head부터 시작해야 appendTerm함수가 Head 다음에 노드를 추가한다
    while (curr1 != Tail1 || curr2 != Tail2) {
        if (curr1 -> exp > curr2 -> exp) {
            appendTerm(Head3, Tail3, curr1 -> coef, curr1->exp);
            curr1 = curr1 -> next;
        }
        else if (curr1 -> exp < curr2 -> exp) {
            appendTerm(Head3, Tail3, curr2 -> coef, curr2 -> exp);
            curr2 = curr2 -> next;
        }
        else {
            sum_c = curr1 -> coef + curr2 -> coef;
            sum_e = curr1 -> exp + curr2 -> exp;
            appendTerm(Head3, Tail3, sum_c, sum_e);
            curr1 = curr1 -> next, curr2 = curr2 -> next;
        }
    }
    while (curr1 != Tail1) {
        appendTerm(Head3, Tail3, curr1 -> coef, curr1 -> exp);
        curr1 = curr1 -> next;
    }
    while (curr2 != Tail2) {
        appendTerm(Head3, Tail3, curr2 -> coef, curr2 -> exp);
        curr2 = curr2 -> next;
    }
}
//==============================================================================
int main() {
    Node *Head1, *Head2, *Tail1, *Tail2, *Head3, *Tail3, *curr;
    init(&Head1, &Tail1);
    init(&Head2, &Tail2);
    init(&Head3, &Tail3);

    int n1, n2, coef1, exp1, coef2, exp2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &coef1);
        scanf("%d", &exp1);
        appendTerm(Head1, Tail1, coef1, exp1);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &coef2);
        scanf("%d", &exp2);
        appendTerm(Head2, Tail2, coef2, exp2);
    }
    curr = Head3 -> next;
    while (curr != Tail3) {
        printf("%d ", curr -> coef);
        printf("%d ", curr -> exp);
        curr = curr -> next;
    }
}