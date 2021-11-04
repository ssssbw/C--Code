/*
2设计井验证以下算法:带头结点单向循环链表L中的数据元素为整数且非递增有序，
删除L中所有值大于min_k且小于max_k的元素(若表中存在这样的元素)，并将删除后
链表L分解成两个带头结点单向循环链表L1、L2,使两个链表中各自仅含奇数或偶数。
(1)根据键盘输入数据用头插法建立带头结点单向循环链表L。
(2)利用原带头结点单向循环链表L的结点空间构成链表L1、L2。
(3)输出带头结点单向循环链表L、删除后的链表L、拆分后的带头结点单向循环链表L1、L2。
*/

#include <stdlib.h>
#include <stdio.h>

#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR 0

typedef struct List
{
    int data;
    List *next;
}*LinkList;

LinkList init_List();
LinkList create_List(LinkList headNode);
LinkList delete_Elem(LinkList headNode, int min_k, int max_k);
void split_List(LinkList headNode, LinkList *oddList, LinkList *evenList);
void print_List(LinkList headNode);

LinkList init_List()
{
    LinkList headNode;
    headNode = (LinkList)malloc(sizeof(LinkList));
    if(!headNode) return ERROR;
    headNode->next = headNode;
    return headNode;
}

LinkList create_List(LinkList headNode)
{
    LinkList rear;
    int num;
    printf("请输入元素个数: ");
    scanf("%d", &num);
    while (num)
    {
        rear = (LinkList)malloc(sizeof(LinkList));
        scanf("%d", &rear->data);
        rear->next = headNode->next;
        headNode->next = rear; 
        num--;
    }
    return headNode;
}

LinkList delete_Elem(LinkList headNode, int min_k, int max_k)
{

    LinkList front, rear, pre;
    pre = headNode;
    front = headNode->next;
    while (front != headNode)
    {
        if (front->data > min_k && front->data <= max_k)
        {
            rear = front->next;
            pre->next = front->next;
            free(front);
            front = rear;
        }
        else
        {
            pre = front;
            front = front->next;
        }
    }
    return headNode;
}

void split_List(LinkList List, LinkList *oddList, LinkList *evenList)
{
    LinkList front, rear, temp;
    front = List;
    rear = front->next;
    while (rear != List)
    {
        if (rear->data % 2 == 0)
        {
            temp = rear->next;
            rear->next = (*evenList)->next;
            (*evenList)->next = rear;
            rear = temp;
        }
        else
        {
            temp = rear->next;
            rear->next = (*oddList)->next;
            (*oddList)->next = rear;
            rear = temp;
        }
    }
}

void print_List(LinkList headNode)
{
    LinkList node;
    node = headNode->next;
    while (node != headNode)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    LinkList list, oddList, evenList;
    
    list = init_List();
    list = create_List(list);
    printf("L :");
    print_List(list);
    printf("\n************************\n");

    int min_k, max_k;
    printf("请输入要删除的元素范围(左开右闭): ");
    scanf("%d %d", &min_k, &max_k);
    list = delete_Elem(list, min_k, max_k);
    printf("L :");
    print_List(list);
    printf("\n************************\n");

    oddList = init_List();
    evenList = init_List();
    split_List(list, &oddList, &evenList);
    printf("L1 :");
    print_List(oddList);
    printf("\n************************\n");
    printf("L2 :");
    print_List(evenList);
    printf("\n************************\n");

    return 0;
}