// 顺序表的相关操作
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0

typedef int ElementType;

typedef int Position;

typedef struct LNode *List;

struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

struct LNode L;// 访问下标为 i 的元素：L.Date[i] or PtrL->Data[i]
List PtrL;     // 线性表的长度：L.Last + 1 or PtrL->Last + 1

List MakeEmpty(void){// 初始化————建立空的顺序表
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    // 动态存储分配函数 void *malloc(unsigned size);
    // 若申请成功，PtrL指向被分配内存空间的起始地址
    // 若未申请成功，则PtrL的值为NULL
    PtrL->Last = -1;
    // 代表表内没有元素
    return PtrL;
}

int Find(ElementType X, List PtrL){// 查找PtrL中X的位置
    int i = 0;
    while(i <= PtrL->Last && PtrL->Data[i] != X) i++;
    if(i > PtrL->Last) return -1;// 如果没找到，返回-1
    else return i;// 找到后返回的是存储位置
}

void insert(ElementType X, int i, List PtrL){// 在第i(1 <= i <= n + 1)个位置上插入X
    if(PtrL->Last == MAXSIZE - 1){
        printf("表满");
        return ;
    }
    if(i < 1 || i > PtrL->Last + 2){
        printf("位置不合法");
        return ;
    }
    for(int j = PtrL->Last; j >= i - 1; j--){// 核心操作，将元素向后移动
        PtrL->Data[j + 1] = PtrL->Data[j];
    }
    PtrL->Data[i - 1] = X;
    PtrL->Last++;
    return ;
}

void Delete(int i, List PtrL){// 删除第i个位置上的元素
    if(i < 1 || i > PtrL->Last + 1){// 判断删除位置的合法性
        printf("不存在第%d个元素", i);
        return ;
    }
    for(int j = i; i <= PtrL->Last; j++){// 元素左移
        PtrL->Data[j - 1] = PtrL->Data[j];
    }
    PtrL->Last--;
    return ;
}

