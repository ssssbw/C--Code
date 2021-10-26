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
#include "string.h"

#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define MALLOC(n, type) {(type *)malloc(n * sizeof(type))}

typedef int Status;
typedef struct Student
{
    int num;
    char name[15];
    char sex[6];
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
Status list_Delete(SqList *L);
Status list_ModifyScore(SqList *list);
Status list_Query(SqList *list, int num);
Status list_Destroy(SqList *list);
Status print_List(SqList *list);
void sort_ByNum(SqList *list);


Status init_List(SqList *list)
{
    list->elem = MALLOC(LIST_INIT_SIZE, ElemType);
    if(!list->elem) exit(OVERFLOW);
    list->length = 0;
    list->size = LIST_INIT_SIZE;
    return OK;
}

Status value_List(SqList *list)
{
    int i;
    printf("请输入元素个数: ");
    scanf("%d", &i);
    if(i > list->size)
    {
        while (TRUE)
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
        printf("学号: ");
        scanf("%d", &list->elem[j].num);
        printf("姓名: ");
        scanf("%s", list->elem[j].name);
        printf("性别: ");
        scanf("%s", list->elem[j].sex);
        printf("高数成绩: ");
        scanf("%lf", &list->elem[j].advancedMath);
        printf("大学英语成绩: ");
        scanf("%lf", &list->elem[j].English);
        printf("程序设计基础成绩: ");
        scanf("%lf", &list->elem[j].programmingDesign);
        list->elem[j].average = (list->elem[j].advancedMath + list->elem[j].English + list->elem[j].programmingDesign) / 3;
    }
    list->length += i;
    sort_ByNum(list);
    printf("赋值成功!\n");
    return OK;
}

Status list_Insert(SqList *list, ElemType e)
{
    if(!list->elem) return ERROR;
    else
    {
        list->elem[list->length].num = e.num;
        strcpy(list->elem[list->length].name, e.name);
        strcpy(list->elem[list->length].sex, e.sex);
        list->elem[list->length].advancedMath = e.advancedMath;
        list->elem[list->length].English = e.English;
        list->elem[list->length].programmingDesign = e.programmingDesign;
        list->elem[list->length].average = e.average;
        list->length++;
        sort_ByNum(list);
        return OK;
    }
}

Status list_Delete(SqList *list)
{
    if(!list->elem) return ERROR;

    int num = 0, i = 0;
    printf("请输入要删除的学生学号: ");
    scanf("%d", &num);

    while (i < list->length)
    {
        if(list->elem[i].num != num) i++;
        else break;
    }
    
    for(int j = i; j < list->length - 1; j++)
    {
        list->elem[j] = list->elem[j + 1];
    }
    list->length--;
    return OK;
}

Status list_ModifyScore(SqList *list)
{
    if(!list->elem) return ERROR;
    int num;
    int i = 0;
    printf("请输入要修改的学生学号: \n");
    scanf("%d", &num);

	for (i = 0; i < list->length; i++)
	{
		if (list->elem[i].num == num)
		{
			printf("请重新输入该学生的信息:\n");
			printf("高数：");
			scanf("%lf", &list->elem[i].advancedMath);
			printf("英语：");
			scanf("%lf", &list->elem[i].English);
			printf("程序设计：");
			scanf("%lf", &list->elem[i].programmingDesign);
            list->elem[i].average = (list->elem[i].advancedMath + list->elem[i].English + list->elem[i].programmingDesign) / 3;
			break;
		}
	}
	if (i >= list->length)
		printf("表中没有该学生的信息：\n");
	return OK;
}

Status list_Query(SqList *list, int num)
{
    if(!list->elem) return ERROR;
    for(int i = 0; i < list->length; i++)
    {
        if(list->elem[i].num == num)
        {
            printf("-------------------------------------------------------------\n");
            printf("| %d | %s | %s | %.1f | %.1f | %.1f | %.2f |\n"
            , list->elem[i].num, list->elem[i].name, list->elem[i].sex
            , list->elem[i].advancedMath, list->elem[i].English, 
            list->elem[i].programmingDesign, list->elem[i].average);
            printf("-------------------------------------------------------------\n");  
        }
        else 
        {
            printf("没有该学员\n");
            break;
        }
    }
    
    return OK;
}

Status list_Destroy(SqList *list)
{
    if(!list->elem) return ERROR;
    free(list->elem);
    list->length = 0;
    list->size = 0;
    printf("学生表已销毁!\n");
    return OK;
}

void sort_ByNum(SqList *list)
{
    for(int i = list->length - 1; i >= 0; i--) 
    {
        int flag = 0;
        for(int j = 0; j < list->length - 1; j++)
        {
            if(list->elem[j].num > list->elem[j + 1].num)
            {
                Student temp;
                temp = list->elem[j];
                list->elem[j] = list->elem[j + 1];
                list->elem[j + 1] = temp;
                flag = 1;
            }
        }
        if(!flag) break;  
    }
}

Status print_List(SqList *list)
{
    if(!list->elem) return ERROR;
    for(int i = 0; i < list->length; i++)
    {
        printf("| %d | %s | %s | %.1f | %.1f | %.1f | %.2f |\n"
        , list->elem[i].num, list->elem[i].name, list->elem[i].sex
        , list->elem[i].advancedMath, list->elem[i].English, 
        list->elem[i].programmingDesign, list->elem[i].average);
        printf("-------------------------------------------------------------\n");
    }
    printf("共%d条学生信息\n", list->length);
    return OK;
}

int main()
{
    int select, num;
    SqList List;
    Student newStu;

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
                printf("请输入新学生信息\n");
                printf("学号: ");
                scanf("%d", &newStu.num);
                printf("姓名: ");
                scanf("%s", newStu.name);
                printf("性别: ");
                scanf("%s", newStu.sex);
                printf("高数成绩: ");
                scanf("%lf", &newStu.advancedMath);
                printf("大学英语成绩: ");
                scanf("%lf", &newStu.English);
                printf("程序设计基础成绩: ");
                scanf("%lf", &newStu.programmingDesign);
                newStu.average = (newStu.advancedMath + newStu.English + newStu.programmingDesign) / 3;
                list_Insert(&List, newStu);
            break;

            case 4:
                list_ModifyScore(&List);
            break;

            case 5:
                list_Delete(&List);
            break;

            case 6:
                scanf("%d", &num);
                list_Query(&List, num);
            break;

            case 0:default:
                printf("系统已安全退出!\n");      
                exit(0);
        }
    }
    return 0;
}