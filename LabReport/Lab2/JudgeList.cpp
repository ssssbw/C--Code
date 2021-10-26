/*
3.设计并验证以下算法:判定带头结点单向链表L的数据元素是否为非递增有序。如果是非递增有序的，
删除值相同的多余元素，并就地逆置删除后的链表L;如果不是非递增有序的，输出相应的提示信息。
(1)根据键盘输入数据用尾插法建立带头结点单向链表L。
(2)输出带头结点单向链表L、删除值相同多余元素后的单向链表L、就地逆置后的单向链表L。
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
LinkList delete_Elem(LinkList headNode);
LinkList reverse_List(LinkList headNode);
bool judge_list(LinkList headNode);
void print_List(LinkList headNode);

int main()
{
    LinkList list;

    list = init_List();
    list = create_List(list);
    printf("L: ");
    print_List(list);
    printf("\n************************");

    list = delete_Elem(list);
    printf("L: ");
    print_List(list);
    printf("\n************************");

    list = reverse_List(list);
    printf("逆置后L: ");
    print_List(list);
    printf("\n************************");

    return 0;
}