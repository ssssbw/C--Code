/*
3.设计并验证以下算法:判定带头结点单向链表L的数据元素是否为非递增有序。如果是非递增有序的，
删除值相同的多余元素，并就地逆置删除后的链表L;如果不是非递增有序的，输出相应的提示信息。
(1)根据键盘输入数据用尾插法建立带头结点单向链表L。
(2)输出带头结点单向链表L、删除值相同多余元素后的单向链表L、就地逆置后的单向链表L。
*/

#include "stdio.h"
#include "stdlib.h"


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
LinkList delete_Elem(LinkList headNode);
LinkList reverse_List(LinkList headNode);
bool judge_list(LinkList headNode);
void print_List(LinkList headNode);

LinkList init_List()
{
    LinkList headNode;
    headNode = (LinkList)malloc(sizeof(LinkList));
    if(!headNode) return ERROR;
    headNode->next = NULL;
    return headNode;
}

LinkList create_List(LinkList headNode)
{
    LinkList front, rear;
    front = headNode;
    int num;
    printf("请输入元素个数: ");
    scanf("%d", &num);
    while (num)
    {
        rear = (LinkList)malloc(sizeof(LinkList));
        scanf("%d", &rear->data);
        rear->next = NULL;
        front->next = rear;
        front = front->next;
        num--;
    }
    return headNode;
}

LinkList delete_Elem(LinkList head)
{
	if(head == NULL || head->next == NULL)
	    return head;
	head->next = delete_Elem(head->next);
	if(head->data == head->next->data) head = head->next;
	return head;  
}

LinkList reverse_List(LinkList headNode)
{
    LinkList front, rear, temp;
    if(!headNode || !headNode->next) return headNode;
    temp = headNode->next;
    front = temp->next;
    rear = NULL;
    temp->next = NULL;
    while (front)
    {
        rear = front->next;
        front->next = temp;
        temp = front;
        front = rear;
    }
    headNode->next = temp;
    return headNode;
}

bool judge_list(LinkList headNode)
{
    LinkList front;
    front = headNode->next;
    while (front->next)
    {
        if (front->data >= front->next->data)
        {
            front = front->next;
        }
        else
            return false;
    }
    return true;
}

void print_List(LinkList headNode)
{
    LinkList node;
    node = headNode->next;
    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    LinkList list;

    list = init_List();
    list = create_List(list);

    if(judge_list(list) == false) printf("此链表不是非递增有序!\n");
    
    else
    {
        printf("L: ");
        print_List(list);
        printf("\n************************\n");

        list = delete_Elem(list);
        printf("去重后L: ");
        print_List(list);
        printf("\n************************\n");

        list = reverse_List(list);
        printf("逆置后L: ");
        print_List(list);
        printf("\n************************\n");
    }
    return 0;
}