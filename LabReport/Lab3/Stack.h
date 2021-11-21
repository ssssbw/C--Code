#include "stdio.h"
#include "string.h"
#include "assert.h"

typedef int ElemType;
#define MAX_SIZE 100
typedef struct Stack{
	
	ElemType arr[MAX_SIZE];
	int top;
}Stack;
 
void StackInit(Stack *stack)
{
	stack->top = 0;
}
 
void StackDestory(Stack *stack)
{
	stack->top = 0;
}
 
void StackPush(Stack *stack,ElemType data)
{
	assert(stack->top < MAX_SIZE);
	stack->arr[stack->top++] = data;
}
 
void StackPop(Stack *stack)
{
	assert(stack->top > 0);
	stack->top--;
}
 
ElemType StackTop(const Stack *stack)
{
	assert(stack->top > 0);
	return stack->arr[stack->top-1];
}
 
int stackSize(Stack *stack)
{
	return stack->top;
}
 
int StackFull(Stack *stack)
{
	return stack->top >= MAX_SIZE;
}
 
int StackEmpty(Stack *stack)
{
	return stack->top <= 0;
}