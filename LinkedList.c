#include 'Myheader.h'

typedef struct Node 
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

//=== typedef struct Node* LinkList


LinkList InitLinkedList()
{
    LinkList L_head;
    L_head = (LinkList)malloc(sizeof(Node));
    if(L_head == NULL)
        printf("applying for memory space fails");
    else
        L_head->next = NULL;
    return L_head;
}

LinkList CreatLinkedList_H(LinkList L, ElemType data)
{   
    LinkList ptr;
    ptr = (LinkList)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = L;
    L = ptr;
    return L;
}

LinkList CreatLinkedList_T(LinkList L, ElemType data)
{
    LinkList ptr;
    ptr = (LinkList)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    L->next = ptr;
    return L;
}



Status GetElem(LinkList L, int i, ElemType *e)
{
    int k;
    if(L == NULL)
        return ERROR;
    for(k = 1; k < i; k++)
    {
        L = L->next;
        if(L == NULL)
        {
            printf("cannot find required node");
            return ERROR;
        }
    }
    *e = L->data;
    return 0;
}