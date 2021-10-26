#include <cstdio>
#include <malloc.h>
#include <windows.h>
#include <cstdlib>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType *elem; //存储空间基址
    int length;     //当前长度
    int list_Size;
} SqList;

Status init_List(SqList &L);
Status value_List(SqList &L);
Status dstroy_List(SqList &L);
Status clear_List(SqList &L);
Status isEmpty(SqList L);
Status list_Length(SqList L);
Status get_Elem(SqList L, int i);
Status locata_Elem(SqList L, ElemType e);
Status prior_Elem(SqList L, int index);
Status next_Elem(SqList L, int index);
Status list_Insert(SqList &L, ElemType e, int pos);
Status list_Delete(SqList &L, int pos);
Status print_List(SqList L);

Status init_List(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
    {
        printf("存储空间分配失败\n");
        exit(OVERFLOW);
    }
    L.length = 0;
    L.list_Size = LIST_INIT_SIZE;
    printf("空表创建成功\n");
    return OK;
}

Status value_List(SqList &L)
{
    int i, j;
    printf("请输入线性表元素个数: ");
    scanf("%d", &i);
    if (i > L.list_Size)
    {
        while (1) //一直开辟新空间,直到开辟的空间大于需要的空间
        {
            if (i > L.list_Size)
            {
                L.elem = (ElemType *)realloc(L.elem, LISTINCREMENT * sizeof(ElemType));
                L.list_Size += LISTINCREMENT;
            }
            else
                break;
        }
    }

    for (j = 0; j < i; j++)
    {
        printf("请输入第%d个元素: ", j + 1);
        scanf("%d", &L.elem[j]);
        //L.length++;
    }

    L.length += i; //赋值成功,保存长度
    printf("赋值成功\n");
    return OK;
}

Status destroy_List(SqList &L)
{
    if (!L.elem)
    {
        printf("未创建线性表,请先创建线性表!\n");
        return ERROR;
    }
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.list_Size = 0;
    printf("线性表已销毁!\n");
    return OK;
}

Status clear_List(SqList &L)
{
    if (!L.elem)
    {
        printf("未创建线性表,请先创建线性表!\n");
        return ERROR;
    }
    else
    {
        L.length = 0;
        printf("线性表已重置\n");
        return OK;
    }
}

Status isEmpty(SqList L)
{
    if (L.elem)
    {
        if (L.length == 0)
        {
            printf("线性表是空表\n");
            return FALSE;
        }
        else
            printf("线性表非空\n");
    }
    else
        printf("线性表不存在\n");
    return OK;
}

Status list_Length(SqList L)
{
    if (L.elem)
    {
        int length;
        length = L.length;
        printf("线性表长度为: %d\n");
        return OK;
    }
    else
        printf("线性表不存在\n");
    return OK;
}

Status get_Elem(SqList L, int i)
{
    if (!L.elem)
    {
        printf("未创建线性表,请先创建线性表!\n");
        return ERROR;
    }
    else if (i < 1 || i > L.length)
    {
        printf("角标越界\n");
        return ERROR;
    }
    else
    {
        printf("第%d个元素为: %d\n", i, L.elem[i - 1]);
        return OK;
    }
}

Status locata_Elem(SqList L, ElemType e)
{
    if (!L.elem)
    {
        printf("未创建线性表,请先创建线性表!\n");
        return ERROR;
    }
    int i = 0;
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            printf("%d是表中第%d个元素\n", e, i);
            break;
        }
    }
    return OK;
}

Status prior_Elem(SqList L, int index)
{
    if (!L.elem)
    {
        printf("未创建线性表,请先创建线性表!\n");
        return ERROR;
    }
    if (index <= 1 || index > L.length + 1)
        return OVERFLOW;
    printf("第%d个元素的直接前驱是%d\n", index, L.elem[index - 2]);
    return OK;
}

Status next_Elem(SqList L, int index)
{
    if (!L.elem)
    {
        printf("未创建线性表,请先创建线性表!\n");
        return ERROR;
    }
    if (index < 1 || index >= L.length)
        return OVERFLOW;
    printf("第%d个元素的直接后继是%d\n", index, L.elem[index]);
    return OK;
}

Status list_Insert(SqList &L, ElemType e, int pos)
{
    if (!L.elem)
    {
        printf("未创建线性表,请先创建线性表!\n");
        return ERROR;
    }
    if (pos < 1 || pos > L.length + 1)
        return OVERFLOW;
    if (L.length >= L.list_Size)
    {
        printf("线性表已满!\n");
        return OVERFLOW;
    }
    for (int i = L.length; i >= pos - 1; i--)
    {
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[pos - 1] = e;
    L.length++;
    return OK;
}

Status list_Delete(SqList &L, int pos)
{
    if (!L.elem)
    {
        printf("未创建线性表,请先创建线性表!\n");
        return ERROR;
    }
    if (pos < 1 || pos > L.length)
        return OVERFLOW;
    for (int i = pos; i < L.length; i++)
    {
        L.elem[i - 1] = L.elem[i];
    }
    L.length--;
    return OK;
}

Status print_List(SqList L)
{
    if (!L.elem)
    {
        printf("未创建线性表,请先创建线性表!\n");
        return ERROR;
    }
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
    return OK;
}
