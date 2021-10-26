/*******
1.一元稀疏多项式计算器
(1)设Pn(x)和Qm(X)分别为两个一元稀疏多项式,利用单链表存储Pn(x)和Qm(x)。
(2)从鍵盘輸入一元多項式的信息，建立一元稀疏多項式 Pn(x)和Qm(x)，并輸出。
(3)实現Pn(x)和Qm(x)相加，并輸出丙者的和Pn(x)+Qm(x)。
(4)实現Pn(x)和Qm(x)相減，并輸出兩者的差Pn(x)-Qm(x)。
(5)就地逆置两者的差Pn(x)-Qm(x)。
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR 0

typedef int Status;
typedef struct Polynomial
{
    double coeff;
    int exp;
}ElemType;

typedef struct PolyNode
{
    ElemType data;
    PolyNode *next;
}*List;

Status destroy_Poly(List headNode);
Status print_Poly(List headNode);
Status attach_Poly(double coeff, int exp, List &headNode);
List reverse_Poly(List headNode);
List init_List();
List create_Poly(List headNode);
List additionOfPoly(List headNode1, List headNode2);
List subtractOfPoly(List headNode1, List headNode2);

List init_List()
{
    List headNode = NULL;
    headNode = (List)malloc(sizeof(List));
    if(!headNode) return ERROR;
    headNode->next = NULL;
    return headNode;
}

List create_Poly(List headNode)
{
    List front,rear;
    front = headNode;
    int num = 0;
    printf("\n项数: ");
    scanf("%d", &num);
    printf("系数与指数: ");
    while (front->next) front = front->next;  
    while (num)
    {
        rear = (List)malloc(sizeof(List));
        scanf("%lf %d", &rear->data.coeff, &rear->data.exp);
        front->next = rear;
        front = rear;
        num--;
    }
    front->next = NULL;
    return headNode;
}

Status print_Poly(List headNode)
{
    List front = headNode->next;
    while(front)
    {
        printf("[%.1lf %d] ", front->data.coeff, front->data.exp);
        front = front->next;
    }
    printf("\n");
    return OK;
}

Status destroy_Poly(List headNode)
{
    List p;
    p = headNode;
    while(p) 
    {
        headNode = headNode->next;
        free(p);
        p = headNode;
    }
    printf("链表销毁成功\n");
    return OK;
}

Status attach_Poly(double coeff, int exp, List &newHeadNode)
{
    List temp;
    temp = (List)malloc(sizeof(List));
    temp->data.coeff = coeff;
    temp->data.exp = exp;
    temp->next = NULL;
    newHeadNode->next = temp;
    newHeadNode = temp;
    return OK;
}

List additionOfPoly(List headNode1, List headNode2)
{
    List p1, p2;
    List newHeadNode, newFrontNode;
    p1 = headNode1->next;
    p2 = headNode2->next;
    newHeadNode = init_List();
    newFrontNode = newHeadNode;
    while (p1 && p2)
    {
        if (p1->data.exp == p2->data.exp)
        {
            if (!(p1->data.coeff + p2->data.coeff))
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            else
            {
                attach_Poly((p1->data.coeff + p2->data.coeff), p1->data.exp, newFrontNode);
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        else
        {
            if (p1->data.exp < p2->data.exp)
            {
                attach_Poly(p1->data.coeff, p1->data.exp, newFrontNode);
                p1 = p1->next;
            }
            else
            {
                attach_Poly(p2->data.coeff, p2->data.exp, newFrontNode);
                p2 = p2->next;
            }
        } 
    }        

    for(; p1; p1 = p1->next) attach_Poly(p1->data.coeff, p1->data.exp, newFrontNode);
    for(; p2; p2 = p2->next) attach_Poly(p2->data.coeff, p2->data.exp, newFrontNode);
    newFrontNode->next = NULL;
    return newHeadNode;
}

List subtractOfPoly(List headNode1, List headNode2)
{
    List p1, p2;
    List newHeadNode, newFrontNode;
    p1 = headNode1->next;
    p2 = headNode2->next;
    newHeadNode = init_List();
    newFrontNode = newHeadNode;
    while (p1 && p2)
    {
        if (p1->data.exp == p2->data.exp)
        {
            if (!(p1->data.coeff - p2->data.coeff))
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            else
            {
                attach_Poly((p1->data.coeff - p2->data.coeff), p1->data.exp, newFrontNode);
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        else
        {
            if (p1->data.exp < p2->data.exp)
            {
                attach_Poly(p1->data.coeff, p1->data.exp, newFrontNode);
                p1 = p1->next;
            }
            else
            {
                attach_Poly((0 - p2->data.coeff), p2->data.exp, newFrontNode);
                p2 = p2->next;
            }
        } 
    }        

    for(; p1; p1 = p1->next) attach_Poly(p1->data.coeff, p1->data.exp, newFrontNode);
    for(; p2; p2 = p2->next) attach_Poly((0 - p2->data.coeff), p2->data.exp, newFrontNode);
    newFrontNode->next = NULL;
    return newHeadNode;
}

List reverse_Poly(List headNode)
{
    List p ,q, r;
    if(!headNode || !headNode->next) return headNode;
    p = headNode->next;
    q = p->next;
    r = NULL;
    p->next = NULL;
    while (q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    headNode->next = p;
    return headNode;
}

int main()
{
    List P1, P2;
    printf("请输入多项式P1的项数,系数与指数: ");
    P1 = init_List();
    P1 = create_Poly(P1);
    printf("请输入多项式P2的项数,系数与指数: ");
    P2 = init_List();
    P2 = create_Poly(P2);
    printf("****************************************************************\n");

    printf("P1: ");
    print_Poly(P1);
    printf("P2: ");
    print_Poly(P2);
    printf("****************************************************************\n");

    List P3, P4;
    P3 = additionOfPoly(P1, P2);
    printf("P1与P2相加的P3为: ");
    print_Poly(P3);
    P4 = subtractOfPoly(P1, P2);
    printf("P1与P2相减的P4为: ");
    print_Poly(P4);
    printf("逆转后的P4为: ");
    P4 = reverse_Poly(P4);
    print_Poly(P4);
    printf("****************************************************************\n");

    destroy_Poly(P1);
    destroy_Poly(P2);
    destroy_Poly(P3);
    destroy_Poly(P4);
    return 0;
}