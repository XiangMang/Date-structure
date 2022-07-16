#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}

/* 你的代码将被嵌在这里 */
bool Insert( List L, ElementType X ){
    if(L->Last + 1 == MAXSIZE) return false;// 判断容量
    for(int i = 0; i <= L->Last; i++) if(L->Data[i] == X) return false;// 判断是否已经存在
    int addres = -1;
    while(L->Data[++addres] > X);// 记录第一个不符合条件的地址
    for(int i = L->Last; i >= addres; i--) L->Data[i + 1] = L->Data[i];// 数组右移
    L->Data[addres] = X;// 插入数组
    L->Last++;
    return true;
}