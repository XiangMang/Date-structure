// 链表的相关操作
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;// 结构的递归定义
};
typedef PtrToNode List;

struct Lnode L;
List PtrL;

int Length(List PtrL){// 求表长
    List p = PtrL;
    int len = 0;
    while(p){// 表尾为NULL
        p = p->Next;
        len++;
    }
    return len;
}

List FindKth(int K, List PtrL){// 按序号进行查找
    List p = PtrL;
    int i = 1;
    while(p != NULL && i < K){
        p = p->Next;
        i++;
    }
    if(i == K) return p;
    else return NULL;
}

List Find(ElementType X, List PtrL){// 按值进行查找
    List p = PtrL;
    while(p != NULL && p->Data != X){
        p = p->Next;
    }
    return p;
}

List Insert(ElementType X, int i, List PtrL){// 进行插入操作
    // 先构造一个新结点，用s指向
    // 再找到链表的第i-1个结点，用p指向
    // 然后修改指针，插入结点（p之后插入新结点是s）
    List p, s;
    if(i == 1){// 新结点插入在表头
        s = (List)malloc(sizeof(struct(LNode)));// 申请、填装结点
        s->Data = X;
        s->Next = PtrL;
        return s;// 返回新表头指针
    }
    p = FindKth(i - 1, PtrL);// 查找第i-1个结点
    if(p == NULL){// 第i-1个不存在，不能插入
        printf("参数i错");
        return NULL;
    }
    else{
        s = (List)malloc(sizeof(struct LNode));// 申请、填装结点
        s->Data = X;// 新结点插入在第i-1个结点的后面
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

List Delete(int i, List PtrL){// 删除结点
    List p, s;
    if(i == 1){// 如果删除的是第一个结点
        s = PtrL;// s指向第1个结点
        if(PtrL != NULL) PtrL = PtrL->Next;// 从链表中删除
        else return NULL;
        free(s);// 释放被删除结点
        return PtrL;
    }
    p = FindKth(i - 1, PtrL){// 查找第i-1个结点
        if(p == NULL){
            printf("第%d个结点不存在", i - 1);
            return NULL;
        }
        else if(p->Next == NULL){
            printf("第%d个结点不存在", i);
            return NULL;
        }
        else{
            s = p->Next;// s指向第i个结点
            p->Next = s->Next;// 从链表中删除
            free(s);// 释放被删除结点
            return PtrL;
        }
    }
}