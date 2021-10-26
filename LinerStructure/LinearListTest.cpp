#include "LinearList.h"
#include "cstdio"
#include "windows.h"
int main(){
	SetConsoleTitle("帅比文");
	SqList L;
	int choose,index,e;
	while(1){
		printf("*****************************************\n");
		printf("*                                       *\n");
		printf("*  线性表的顺序表示和实现：             *\n");
		printf("*                                       *\n");
		printf("*    1.  构造一个空的线性表             *\n");
		printf("*    2.  对线性表进行赋值               *\n");
		printf("*    3.  对线性表进行销毁               *\n");
		printf("*    4.  对线性表进行重置               *\n"); 
		printf("*    5.  判断线性表是否为空             *\n");
		printf("*    6.  获取线性表的长度               *\n");
		printf("*    7.  获取线性表某一位置对应的元素   *\n");
		printf("*    8.  在线性表某一位置插入元素       *\n");
		printf("*    9.  删除线性表某一位置的元素       *\n");
		printf("*    10. 求线性表某一元素的前驱         *\n");
		printf("*    11. 求线性表某一元素的后继         *\n");
		printf("*    12. 打印线性表                     *\n");
		printf("*    13. 退出                           *\n");
		printf("*                                       *\n");
		printf("*****************************************\n");
		printf("请做出您的选择：");
		scanf("%d",&choose);
		switch(choose){
			case 1:init_List(L);break;
			case 2:value_List(L);break;
			case 3:destroy_List(L);break;
			case 4:clear_List(L);break;
			case 5:isEmpty(L);break;
			case 6:list_Length(L);break;
			case 7:{
				printf("请输入要获取元素的位置：");
				scanf("%d",&index);
				get_Elem(L,index);
			}
			break;
			case 8:{
				printf("请输入要插入元素的位置：");
				scanf("%d",&index);
				printf("请输入要插入的元素：");
				scanf("%d",&e);
				list_Insert(L, e, index);
			}
			break;
			case 9:{
				printf("请输入要删除元素的位置：");
				scanf("%d",&index);
				list_Delete(L, index);	
			}
			break;
			case 10:{
				printf("请输入想要查找哪一个元素的前驱：");
				scanf("%d",&index);
				prior_Elem(L,index);
			}
			break;
			case 11:{
				printf("请输入想要查找哪一个元素的后继：");
				scanf("%d",&index);
				next_Elem(L,index);
			}
			break; 
			case 12:print_List(L);break;
			case 13:exit(0);
		}
	}
	return 0;
}
