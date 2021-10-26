/*
3.设计并实现一个简单的学生成绩管理系统。
(1)采用顺序存储结构，每位学生的成绩信息包括学号、姓名、性别、
高等数学、大学英语、程序设计基础、平均分。
(2)能实现查询(按学号查找学生的信息)、修改(按学号对某个学生的
某门课程成绩进行修改)、插入(增加新学生的信息)、删除(按学号删
除已退学的学生的信息)功能。
(3)根据屏幕菜单的选择(提示:参考“12.4.4 参考源程序”的主函数部分)，
可以进行数据的查询、修改、插入与删除,并在插入或删除数据元素后，
再输出成绩表。
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
#define MALLOC(n, type) {(type *)malloc(n * sizeof(type))}

typedef int Status;
typedef struct Student
{
    int num;
    char name[15];
    char sex[4];
    double advancedMath;
    double English;
    double programmingDesign;
    double average;
}ElemType;

typedef struct
{
    ElemType *elem;
    int length;
    int size;
}SqList;

Status init_List(SqList *list);
Status value_List(SqList *list);
Status list_Insert(SqList *L, ElemType e);
Status list_Delete(SqList *L, int num);
Status list_ModifyScore(SqList *list, int num);
Status list_Query(SqList *list, int num);
Status list_Destroy(SqList *list);
void sort_ByNum(SqList *list);
void print_List(SqList *list);

Status init_List(SqList *list)
{
    list->elem = MALLOC(LIST_INIT_SIZE, ElemType);
    if(!list->elem) exit(OVERFLOW);
    list->length = 0;
    list->size = LIST_INIT_SIZE;
    return OK;
}

void sort_ByNum(SqList *list)
{
    for(int j = 0; j < list->length; j++)
    {
        
    }
}

int main()
{
    int select, num;
    SqList List;
    ElemType elem;

    while(TRUE)
    {
        printf("******************************\n");
        printf("*   1.对学生表进行赋值\n");
        printf("*   2.显示学生信息\n");
        printf("*   3.插入新学生信息\n");
        printf("*   4.修改学生成绩\n");
        printf("*   5.删除学生信息\n");
        printf("*   6.查询学生信息\n");
        printf("*   0.退出\n");
        printf("******************************\n");
        printf("请做出你的选择: ");
        scanf("%d", &select);
        switch(select)
        {
            case 1:
                init_List(&List);
                value_List(&List);
            break;

            case 2:
                print_List(&List);
            break;

            case 3:
                list_Insert(&List, elem);
            break;

            case 4:
                list_ModifyScore(&List, num);
            break;

            case 5:
                list_Delete(&List, num);
            break;

            case 6:
                list_Query(&List, num);
            break;

            case 0:default:      
                exit(0);
        }
    }
    return 0;
}