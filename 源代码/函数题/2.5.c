#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 ){
    List L3, Rear;
    L3 = (PtrToNode)malloc(sizeof(struct Node));// 申请空间
    L3->Next = NULL;// init操作
    Rear = L3;//将尾指针初始状态下指向头结点
    // 即Rear为L3的指针

    while(L1->Next && L2->Next){// 如果两者的下一个结点都不为空
        if(L1->Next->Data < L2->Next->Data){
            Rear->Next = L1->Next;
            L1->Next = L1->Next->Next;// 相当于++操作
            Rear->Next->Next = NULL;// 重置尾节点
            Rear = Rear->Next;// L3指针++
        }
        else{
            Rear->Next = L2->Next;
            L2->Next = L2->Next->Next;
            Rear->Next->Next = NULL;
            Rear = Rear->Next;
        }

    }

    if(L1->Next){
        Rear->Next = L1->Next;
        L1->Next = NULL;
    }

    if(L2->Next){
        Rear->Next = L2->Next;
        L2->Next = NULL;
    }

    return L3;
}