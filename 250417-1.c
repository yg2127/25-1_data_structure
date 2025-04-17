//
// Created by 유건 on 25. 4. 17.
//
#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* getnode() {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> next = NULL;
    return newnode;
}
void free_list(Node* Head) {
    Node* curr = Head;
    Node* N = NULL;

    while (curr != NULL) {
        N = curr -> next;
        free(curr);
        curr = N;
    }
}
Node* init() {
    Node* Head = getnode();
    Node* Tail = getnode();
    Head -> next = Tail;
    return Head;
}
Node* search(Node* Head, int number) {
    Node* curr = Head;
    for (int i = 1; i < number; i++) {
        curr = curr -> next;
    }
    if (curr == NULL) {
        printf("invalid position");
        return NULL;
    }
    else return curr;
}
void append(Node* Head, int d, int number) {
    Node* curr = search(Head, number);
    if (curr == NULL) return;

    Node* newnode = getnode();
    newnode -> next = NULL;
    newnode -> data = d;
    curr -> next = newnode;
}

int main() {
    Node* Head = init();
    Node* curr = Head;

    int d, l_number = 0;
    char c;
    while (1){
        printf("A = 연결리스트 추가, P = 연결리스트 출력, D = 연결리스트 삭제\n"
           "다음중 하나를 입력하세요(이외의 값 입력 시 종료): ");

        scanf(" %c", &c);
        if (c == 'A') {
            printf("추가할 값을 입력하세요");
            scanf("%d", &d);
            if (l_number == 0) {
                Head = getnode();
                Head -> data = d;
                l_number++;
            }
            else {
                append(Head, d, l_number);
                l_number++;
            }
        }
        else if (c == 'P'){
            curr = Head;
            printf("\n");
            while (curr != NULL) {
                printf("%d", curr-> data);
                curr = curr->next;
            }
            printf("\n");
            printf("\n");
        }
        else if (c == 'D') {
            printf("삭제할 데이터를 입력하시오");
            scanf("%d", &d);
            curr = Head;
            while (1) {
                if (curr == NULL) {
                    printf("invalid position");
                    break;
                }
                else if (Head -> data == d) { // 첫번째 노드를 삭제할 땐 Head를 옮기는게 중요하다!
                    Node* target = Head;
                    Head = Head -> next;
                    free(target);
                    l_number--;
                    break;
                }
                else if ((curr -> next)-> data == d){
                    Node* target = curr -> next;
                    curr -> next = target -> next;
                    free(target);
                    l_number--;
                    break;
                }
                else curr = curr -> next;
            }
        }
        else {
            printf("종료합니다");
            break;
        }
    }
}