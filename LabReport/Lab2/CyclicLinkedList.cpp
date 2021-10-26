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

typedef struct List
{
    int data;
    List *next;
}*LinkList;

LinkList init_List();
LinkList create_List(LinkList headNode);
LinkList delete_Elem(LinkList headNode, int min_k, int max_k);
void split_List(LinkList headNode, LinkList oddList, LinkList evenList);
void print_List(LinkList headNode);

int main()
{
    LinkList list, oddList, evenList;
    
    list = init_List();
    list = create_List(list);
    printf("L :");
    print_List(list);
    printf("\n************************");

    int min_k, max_k;
    printf("请输入要删除的元素范围: ");
    scanf("%d %d", &min_k, &max_k);
    list = delete_Elem(list, min_k, max_k);
    printf("L :");
    print_List(list);
    printf("\n************************");

    oddList = init_List();
    evenList = init_List();
    split_List(list, oddList, evenList);
    printf("L1 :");
    print_List(oddList);
    printf("\n************************");
    printf("L2 :");
    print_List(evenList);
    printf("\n************************");

    return 0;
}