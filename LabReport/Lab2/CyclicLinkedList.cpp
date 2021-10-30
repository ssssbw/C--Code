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
void split_List(LinkList headNode, LinkList oddList, LinkList evenList);
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
        if (front->data > min_k && front->data < max_k)
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

void divide_Odd_Even(LinkList List, LinkList ListEven)
{
	//init(ListEven);//初始化B，使其成为带有头结点的空指针,用于将来存放偶数
	LinkList ListB = ListEven;//偶数链表的临时指针
	while (List->next != NULL)
	{
		if (List->next->data % 2 == 0)//如果为偶数
		{
			LinkList temp = List->next;//记录下这个偶数的节点的地址
			List->next = temp->next;//删除操作
			List = List->next;//前进一格
			ListB->next = temp;//将偶数节点接入ListB
			ListB = temp;//临时指针移动到表尾，注意，此时表尾的next并不是指向NULL
		}
		else//如果是奇数
		{
			List = List->next;//前进一格
		}
		if (List == NULL)//如果最后一个链表是偶数，则移动完链表后，因为要再前进一格，所以List为NULL，如果这个时候不结束循环，循环条件会爆炸
		{
			return;
		}
	}
	ListB->next = NULL;
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
    printf("请输入要删除的元素范围: ");
    scanf("%d %d", &min_k, &max_k);
    list = delete_Elem(list, min_k, max_k);
    printf("L :");
    print_List(list);
    printf("\n************************\n");

    // oddList = init_List();
    evenList = init_List();
    divide_Odd_Even(list, evenList);
    printf("L1 :");
    print_List(list);
    printf("\n************************");
    printf("L2 :");
    print_List(evenList);
    printf("\n************************");

    return 0;
}