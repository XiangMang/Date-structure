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

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    // 创建一个链表
    ElementType X;
    // 需要查找的数值
    Position P;
    // 查询函数的返回值

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X ){
    int l = 1, r = L->Last;
    while(l < r){
        int mid = l + r >> 1;
        if(L->Data[mid] >= X) r = mid;
        else l = mid + 1;
    }
    if(L->Data[l] == X) return l;
    else return NotFound;
}