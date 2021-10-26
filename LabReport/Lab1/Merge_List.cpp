/*
2.设计并验证以下算法:设顺序表A和B中的数据元素为整数且单调递增
有序，将这两张表合并成顺序表C。
(1)顺序表C单调递减有序。
(2)根据键盘输入数据建立顺序表A和B。
(3)输出顺序表A、B和C。
*/
#include "stdio.h"
#include "stdlib.h"

#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define MALLOC(n, type) {(type *)malloc(n * sizeof(type))}
#define SWAP(a,b) {a = a + b; b = a - b; a = a - b;}

typedef int ElemType;
typedef struct 
{
    ElemType *elem;
    int length;
    int size;
}SqList;

int init_List(SqList *list);
int value_List(SqList *list);
int merge_List(SqList *A, SqList *B, SqList *C);
void sort_List(SqList *list);
void print_List(SqList *list);
void destroy_List(SqList *list);

int init_List(SqList *list)
{
    list->elem = MALLOC(LIST_INIT_SIZE, ElemType);
    if(!list->elem) exit(OVERFLOW);
    list->length = 0;
    list->size = LIST_INIT_SIZE;
    printf("空表创建成功!\n");
    return OK;
}

int value_List(SqList *list)
{
    int i;
    printf("请输入元素个数: ");
    scanf("%d", &i);
    if(i > list->size)
    {
        while(TRUE)
        {
            if(i > list->size)
            {
                list->elem = (ElemType *)realloc(list->elem, LISTINCREMENT * sizeof(ElemType));
                list->size += LISTINCREMENT;
            }
            else break;
        }
    }

    for (int j = 0; j < i; j++)
    {
        scanf("%d", &list->elem[j]);
    }
    list->length += i;
    sort_List(list);
    printf("赋值成功!\n");
    return OK;
}

int merge_List(SqList *A, SqList *B, SqList *C)
{
    C->elem = MALLOC((A->length + B->length),ElemType);
    if(!C->elem) exit(OVERFLOW);
    C->size = A->length + B->length;
    C->length = C->size;
    int pa = A->length - 1, pb = B->length - 1, i = 0;
    while(pa >= 0 && pb >= 0) C->elem[i++] = A->elem[pa] > B->elem[pb] ? A->elem[pa--] : B->elem[pb--];     
    while(pa >= 0) C->elem[i++] = A->elem[pa--];
    while(pb >= 0) C->elem[i++] = B->elem[pb--];
    return OK;
}

void sort_List(SqList *list)
{
    for (int j = list->length - 1; j >= 0; j--)
    {
        int flag = 0;
        for (int i = 0; i < list->length - 1; i++)
        {
            if(list->elem[i] > list->elem[i + 1])
            {
                SWAP(list->elem[i],list->elem[i + 1]);
                flag = 1;
            }
        } 
        if(!flag) break;
    }  
}

void destroy_List(SqList *list)
{
    free(list->elem);
    list->length = 0;
    list->size = 0;
    printf("线性表已销毁!\n"); 
}

void print_List(SqList *list)
{
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->elem[i]);
    }
    printf("\n");
}

int main()
{
    SqList A, B, C;

    init_List(&A);
    value_List(&A);
    printf("A表如下 :\n");
    print_List(&A);
    printf("***********\n");

    init_List(&B);
    value_List(&B);
    printf("B表如下 :\n");
    print_List(&B);
    printf("***********\n");

    init_List(&C);
    merge_List(&A, &B, &C);
    printf("C表如下 :\n");
    print_List(&C);
    printf("***********\n");

    destroy_List(&A);
    destroy_List(&B);
    destroy_List(&C);
    return 0;
}