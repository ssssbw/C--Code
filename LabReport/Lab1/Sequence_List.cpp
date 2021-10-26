/*
1.设计并验证以下算法:设顺序表L中的数据元素为整数且非递增有序，
删除其值相同的多余元素，即顺序表L中相同的元素只保留一个
，并逆置删除后的顺序表L。
(1)根据键盘输入数据建立顺序表L.
(2)输出顺序表L、删除值相同多余元素后的顺序表L、逆置的顺序表L。
(3)假设顺序表L的长度为n,要求以O(n)的时间复杂度完成对值相同多余元素的删除.
*/

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define SWAP(a,b) {a = a + b; b = a - b; a = a - b;}

typedef int ElemType; 
typedef struct 
{
    ElemType *elem;
    int length;
    int size;
}SqList;

int init_List(SqList *L);
int reverse_List(SqList *L);
int removeDuplicates_List(SqList *L);
void destroy_List(SqList *L);
void value_List(SqList *L);
void print_List(SqList *L);
void sort_List(SqList *L);

int init_List(SqList *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L->elem)
    {
        printf("存储空间分配失败\n");
        exit(OVERFLOW);
    }
    L->length = 0;
    L->size = LIST_INIT_SIZE;
    printf("空表创建成功\n");
    return OK;
}

void sort_List(SqList *L)
{
    for (int j = L->length - 1; j >= 0; j--)
    {
        int flag = 0;
        for (int i = 0; i < L->length - 1; i++)
        {
            if(L->elem[i] < L->elem[i + 1]) 
            {
                SWAP(L->elem[i], L->elem[i + 1]);
                flag = 1;
            }    
        } 
        if(!flag) break;
    }
}

void value_List(SqList *L)
{
    int i;
    printf("请输入元素个数: \n");
    scanf("%d", &i);
    if(i > L->size)
    {
        while (TRUE)
        {
            if(i > L->size)
            {
                L->elem = (ElemType *)realloc(L->elem, LISTINCREMENT * sizeof(ElemType));
                L->size += LISTINCREMENT;
            }
            else break;
        }
    }

    for (int j = 0; j < i; j++)
    {
        scanf("%d", &L->elem[j]);
    }

    L->length += i;
    sort_List(L);
    printf("赋值成功\n");
}

int reverse_List(SqList *L)
{
    for (int i = 0; i < L->length / 2; i++)
    {
        SWAP(L->elem[i], L->elem[L->length - 1 - i]);
    }
    return OK;
}

int removeDuplicates_List(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        for (int j = i + 1 ; j < L->length; j++)
        {
            if(L->elem[j] == L->elem[i])
            {
                for (int k = j; k < L->length - 1; k++)
                {
                    L->elem[k] = L->elem[k + 1];
                }
                L->length--;
                j--;
            }
        }      
    }
    return OK;
}

void destroy_List(SqList *L)
{
    free(L->elem);
    L->length = 0;
    L->size = 0;
    printf("线性表已销毁!\n"); 
}

void print_List(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

int main()
{
    SqList L;
    int choose;
    while (TRUE)
    {
        printf("请做出你的选择: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            init_List(&L);
            value_List(&L);
            printf("线性表如下: \n");
            print_List(&L);
            printf("********************************\n");
            break;
        case 2:
            removeDuplicates_List(&L);
            printf("线性表如下: \n");
            print_List(&L);
            printf("********************************\n");
            break;
        case 3:
            reverse_List(&L);
            printf("线性表如下: \n");
            print_List(&L);
            printf("********************************\n");
            break;
        case 4:destroy_List(&L);
            break;
        case 0:exit(0);
        } 
    }
    return 0;
}
