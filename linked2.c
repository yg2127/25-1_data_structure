#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int num;
    struct Node* next;
}Node;

Node* Head = NULL; // 첫번째 노드를 의미
Node* Tail = NULL; // 맨 마지막 노드를 의미

int main() {
    // 1. 연결리스트의 노드 입력받기
    while (1) {
        int pre;
        printf("입력할 데이터를 입력하시오\n");
        scanf("%d", &pre);
        if (pre < 0) break; // 입력값이 0보다 작으면 반복문 종료

        Node *Newnode = (Node*)malloc(sizeof(Node)); // 입력받는 값을 동적할당 된 포인터변수에 저장한다.

        Newnode -> num = pre; // 뉴노드의 숫자값에 입력받은 데이터 저장
        Newnode -> next = NULL; // 주소를 NULL로 지정

        if (Head == NULL) Head = Newnode; // Head 노드가 없으면 첫번째 입력받은 노드이므로 Head Node로 지정함
        else Tail -> next = Newnode; // Tail 노드의 다음 노드로 뉴노드의 주소를 입력한다.

        Tail = Newnode; // 뉴노드를 무조건 Tail 노드로 지정함
    }

    // 첫번째로 입력된 노드는 Head와 Tail 둘 다 포인터로 지정되어있음.
    // 두번째로 입력된 노드는 첫번째 노드의 포인터인 Tail의 다음 노드로 지정된 후 자신이 Tail node가 됨
    // 세 번째부터는 Tail node의 다음 노드가 되고 자기자신이 노드가 되는 것을 반복한다.

    // 2. 연결리스트 전체 출력하기

    Node* curr = Head;
    while (curr != NULL) { // 다음 노드가 없으면 출력을 위한 반복문 종료
        printf("%d\n", curr -> num);

        curr = curr -> next; // 다음노드로 전환(이게 제일중요)

    }

    while (1) {
        int n2;
        printf("삭제할 데이터를 입력하시오\n");
        scanf("%d", &n2);

        if (n2 < 0) break;

        curr = head;
        curr_prev = NULL;

        while (1) {
            if (curr -> num == n2) break;
            else curr = curr -> next;
        }

        curr
    }
}