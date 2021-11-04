#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void BracketMatch(const char *str,int size)
{
	Stack stack;
	char ch;
	char leftBracket;
	int i = 0;
	StackInit(&stack);
 
 
	for (i=0;i<size;i++)
	{
		ch = str[i];
 
		switch(ch)
		{
		case '(':
		case '[':
		case '{':
			StackPush(&stack,(DataType)ch);
			break;
		case ')':
		case ']':
		case '}':
			if (StackEmpty(&stack))
			{
				printf("右括号多\n");
				StackDestory(&stack);
				return;
			}
 
			leftBracket = (char)StackTop(&stack);
			StackPop(&stack);
 
			if (leftBracket == '(' && ch != ')')
			{
				printf("不匹配\n");
				return;
			}
 
			if (leftBracket == '[' && ch != ']')
			{
				printf("不匹配\n");
				return;
			}
			if (leftBracket == '{' && ch != '}')
			{
				printf("不匹配\n");
				return;
			}
		default:
			break;
		}
	}
	if (!StackEmpty(&stack))
	{
		printf("左括号多\n");
		return;
	}
	printf("匹配正常\n");
}

void TestBracket()
{
	const char *seq[]={
		"(())abc{[(])}",
		"(()))abc{[]}",
		"(()()abc{[]}",
		"(())abc{[]()}"
	};
	int i = 0;
	for (i=0;i<4;i++)
	{
		BracketMatch(seq[i],strlen(seq[i]));
	}
}
 
int main()
{
    TestBracket();
    return 0;
}