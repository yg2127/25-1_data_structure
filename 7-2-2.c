//
// Created by 유건 on 25. 4. 21.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
}Node;

Node* getnode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> next = NULL;
    return newNode;
}
//============================================================================================
Node* search(Node* setA) { // 맨 마지막 노드를 반환
    Node* curr = setA;
    while (curr -> next != NULL) {
        curr = curr -> next;
    }
    return curr;
}
int contain(Node* setA, int data) { // 포함여부 검사
    Node* curr = setA; // Header
    while (1) {
        if (curr -> data == data) return 1; // 있으면 1 반환 (추가하면 안됨)
        if (curr -> next == NULL) break;
        else curr = curr -> next;
    }
    return 0; // 없으면 0 반환 (추가해야함)
}
Node* add(Node* setA, int data) { // 맨 뒤쪽에 노드추가
    if (contain(setA, data)) return setA; // 집합에 이미 존재할 경우 원형 그대로 반환
    Node* newnode = getnode(data);
    newnode -> data = data;
    Node* Tail = search(setA);
    Tail -> next = newnode;
    return setA;
}
Node* union1(Node* setA, Node* setB){
    Node* setU = getnode();
    Node* currA = setA -> next, *currB = setB -> next; // 헤더노드 제외
    // setU에 노드를 추가할 때 오름차순으로 추가해야 하므로 아래의 알고리즘에 따라
    while (currA -> next != NULL && currB -> next != NULL) {
        if (currA -> data < currB -> data) {
            setU = add(setU, currA -> data);
            currA = currA -> next;
        }
        else if (currA -> data > currB -> data) {
            setU = add(setU, currB -> data);
            currB = currB -> next;
        }
        else {
            setU = add(setU, currA -> data);
            currA = currA -> next;
            currB = currB -> next;
        }
    }
    while (currA -> next != NULL) {
        setU = add(setU, currA -> data);
        currA = currA -> next;
    }
    while (currB -> next != NULL) {
        setU = add(setU, currB -> data);
        currB = currB -> next;
    }
    return setU;
}
Node* intersect1(Node* setA, Node* setB) { // A와B 둘 중 하나 작은걸 contain이 1 일 때 추가
    Node* setI = getnode();
    Node *currA = setA -> next, *currB = setB -> next;

    while (currA -> next != NULL && currB -> next != NULL) {
        if (currA -> data < currB -> data) {
            currA = currA -> next;
        }
        else if (currA -> data > currB -> data) {
            currB = currB -> next;
        }
        else {
            setI = add(setI, currA -> data);
            currA = currA -> next;
            currB = currB -> next;
        }
    }
    return setI;
}
void print(Node* set) { //공집합이라면(헤더노드만 있으면) 0 출력 아니라면 원소 출력
    if (set -> next == NULL) { // 헤더노드만 있으면?
        printf("0\n"); // 0 출력
    }
    else {
        Node* curr = set -> next; // 헤더노드 제외
        while (curr -> next != NULL) {
            printf(" %d", curr -> data);
            curr = curr -> next;
        }
        printf("\n");
    }
}
//============================================================================================
int main() {
    Node *setA, *setB, *setU, *setI;
    setA = getnode(); // A의 헤더설정
    setB = getnode(); // B의 헤더설정

    int nA, nB, data;
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
    setU = union1(setA,setB);
    setI = intersect1(setA,setB);
    print(setU);
    print(setI);
}