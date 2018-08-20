#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define Maxsize 20
typedef int ElemType;
typedef struct {
    ElemType Data[Maxsize];
    ElemType length;
} SqList;
typedef int Status;

Status GetElem(SqList L, int i, ElemType *e){
    if(L.length < i || L.length == 0 || i < 1)
        return ERROR;
    *e = L.Data[i-1];
    return 0;
}

Status ListInsert(SqList *L, int i, ElemType e){
    int p;
    if(L->length > Maxsize || L->length + 1 < i || i < 1)
        return ERROR;
    if(i <= L->length){
        for(p = L.length-1; p >= i-1; p--)
            L->Data[p+1] = L->Data[p];
    }
    L->Data[i-1] = e;
    L->length++;
    return 0;
}

Status ListDelete(SqList *L, int i, ElemType *e){
    int p;
    if(L->length < i || i < 1 || L->length == 0)
        return ERROR;
    *e = L->Data[i-1];
    if(i != L->length){
        for(p = i-1; p < L->length-1; p++)
            L->Data[p] = L->Data[p+1];
    }
    L->length--;
    return 0;
}






int UnionL(List *La, List Lb){
    int lengtha, lengthb, i;
    ElemType e;
    lengtha = ListLength(*La);
    lengthb = ListLength(Lb);
    for( i=1; i <= lengthb; i++){
        GetElem(Lb, i, &e);
        if(!LocateElem(La,e)){
            ListInsert(La, ++lengtha, e);
        }
    }
}