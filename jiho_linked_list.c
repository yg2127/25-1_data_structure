//
// Created by À¯°Ç on 25. 4. 19.
//
#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct {
    struct ListNode* next,*prev;
    element data;
}ListNode;

typedef struct {
    ListNode* H, * T;
    int size;
}ListType;

void init(ListType* L)
{
    L->H = NULL;
    L->T = NULL;
    L->size = 0;
}
//=========================================================================
void add(ListType *L,int pos,element e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* p = L->H,*q;
    int i;
    node->data = e;
    if (L->size == 0)
    {
        node->prev = NULL;
        L->H = node;
        L->T = node;
        node->next = NULL;
    }
    else if(pos==1)
    {
        node->prev = NULL;
        node->next = L->H;
        L->H->prev = node;
        L->H = node;

    }
    else if (pos == L->size + 1)
    {
        L->T->next = node;
        node->prev = L->T;
        L->T = node;
        node->next = NULL;
    }
    else
    {

        for (i = 1; i < pos; i++)
        {

            p = p->next;
        }
        q = p->prev;
        q->next = node;
        p->prev = node;
        node->next = p;
        node->prev = q;

    }
    L->size++;
}
void delete(ListType *L,int pos)
{
    ListNode* p = L->H, * q, * r = L->T,*s;
    int i;
    if (L->size == 1)
    {
        L->H = NULL;
        L->T = NULL;
    }
    else if (pos==1)
    {
        L->H = p->next;
        L->H->prev = NULL;
        free(p);
    }
    else if (pos == L->size)
    {
        L->T = r->prev;
        L->T->next = NULL;
        free(r);
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {

            p = p->next;
        }
        q = p->prev;
        q->next = p->next;
        s = p->next;
        s->prev = q;

        free(p);


    }
    L->size--;
}

element get(ListType *L,int pos)
{
    int i;
    ListNode* p = L->H;
    for (i = 1; i < pos; i++)
    {
        p = p->next;
    }
    return p->data;
}

void print(ListType *L)
{
    for (ListNode *p = L->H; p !=NULL ; p=p->next)
    {
        printf("%c", p->data);
    }
    printf("\n");
}
//=========================================================================
int main() {
    int n,i,m;
    char c1, c2;
    ListType L;
    init(&L);
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        getchar();
        scanf("%c", &c1);

        if (c1 == 'A')
        {
            scanf("%d %c",&m, &c2);
            if (m == 0 || m > ((L.size) + 1)) {
                printf("invalid position\n");

            }
            else
                add(&L, m, c2);


        }
        else if (c1 == 'D')
        {
            scanf("%d", &m);
            if (m > (L.size) ) {
                printf("invalid position\n");

            }
            else
                delete(&L, m);


        }
        else if (c1 == 'G')
        {
            scanf("%d", &m);
            if (m > (L.size)) {
                printf("invalid position\n");

            }
            else
                printf("%c", get(&L, m));



        }
        else if (c1 == 'P')
        {
            print(&L);

        }
        else {
            printf("invalid position\n");
        }
    }
    return 0;
}
