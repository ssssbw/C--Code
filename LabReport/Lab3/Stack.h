#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"


// #define TRUE  1
// #define FALSE 0
// #define OK    1
// #define ERROR 0
// #define STACK_INIT_SIZE 100
// #define STACKINCREMENT 10

// typedef char SElemType;
// typedef int Status;
// typedef struct 
// {
//     SElemType *base;
//     SElemType *top;
//     int stackSize;
// }SqStack;

// Status initStack(SqStack *s);
// Status destroyStack(SqStack *s);
// Status isEmpty(SqStack *s);
// Status push(SqStack *s, SElemType e);
// Status pop(SqStack *s, SElemType e);
// Status getTop(SqStack *s, SElemType *e);
// Status clearStack(SqStack *s);
// int getStackLength(SqStack *s);

// Status initStack(SqStack *s)
// {
//     s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
//     if(!s->base) exit(ERROR);
//     s->top = s->base;
//     s->stackSize = STACK_INIT_SIZE;
//     return OK;
// }

// Status destroyStack(SqStack *s)
// {
//     if(!s->base) exit(ERROR);
//     else
//     free(s->base);
//     return OK;
// }

// Status isEmpty(SqStack *s)
// {
//     if(!getStackLength(s)) return 0;
//     return 1;
// }

// int getStackLength(SqStack *s)
// {
//     return (s->top - s->base);
// }

// Status clearStack(SqStack *s)
// {
//     s->top = s->base;
//     return OK;
// }

// Status pop(SqStack *s, SElemType *e)
// {
//     if(!isEmpty(s)) return ERROR;
//     *e = *(--s->top);
//     return OK;
// }

// Status push(SqStack *s, SElemType e)
// {
//     if(s->top - s->base = s->stackSize)
//     {
//         s->base = (SElemType *)realloc(s->base, STACKINCREMENT * sizeof(SElemType));
//         if (!s->base) exit(ERROR);
//         s->top += s->base + s->stackSize;
//         s->stackSize += STACKINCREMENT;
//     }
//     *s->top++ = e;
//     return OK;
// }

// Status getTop(SqStack *s, SElemType *e)
// {
//     if(!isEmpty(s)) return ERROR;
//     *e = *(--s->top);
//     return OK;
// }

typedef int DataType;
 
#define MAX_SIZE (100)
 
typedef struct Stack{
	
	DataType arr[MAX_SIZE];
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
 
void StackPush(Stack *stack,DataType data)
{
	assert(stack->top <MAX_SIZE);
	stack->arr[stack->top++] = data;
}
 
 
void StackPop(Stack *stack)
{
	assert(stack->top > 0);
	stack->top--;
}
 
DataType StackTop(const Stack *stack)
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