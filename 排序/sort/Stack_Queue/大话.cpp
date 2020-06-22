#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

#define ok	1
#define error 0
#define MAXSIZE 20
//#define stacksize 10
//#define STACT_INIT_SIZE 100
//#define STACTINCREMENT 10
//#define MAXBUFFER	10
typedef int Selemtype;
typedef int Status;

//栈的顺序存储实现，数组的第一个位置作为栈底，最后一个作为栈顶
typedef struct
{
	Selemtype data[MAXSIZE];
	int top;
}Sqstack;

//入栈
Status push(Sqstack *s, Selemtype e)
{
	if (s->top > MAXSIZE)
		return error;
	s->top++;
	s->data[s->top] = e;
	return ok;
}

//出栈
Status pop(Sqstack *s, Selemtype *e)
{
	if (s->top == -1)
		return error;
	*e = s->data[s->top];
	s->top--;
	return ok;
}

//两栈共享空间,当两个栈的数据类型是一致的，为了节省空间
//可以使一个栈的栈底为数组的头端，往后生长
//另一个栈则是栈底为数组的尾端，往前生长
//当两个栈的栈顶相遇时，两个指针之间相差1，即top1+=top2.这时数组空间耗尽
//多用于一个栈增长，一个栈缩短的情况
typedef struct
{
	Selemtype data[MAXSIZE];
	int top1;
	int top2;
}SqDoublestack;

Status Push(SqDoublestack *s, Selemtype e, int stacknumber)//stacknumber判断是栈1还是栈2
{
	if (s->top1 + 1 == s->top2)//两个栈顶相遇，栈已满，不能push了
		return error;
	if (stacknumber == 1)
	{
		s->data[++s->top1] = e;//栈顶1向后移动，并插入值
	}
	else if (stacknumber == 2)
	{
		s->data[--s->top2] = e;//栈顶2向前移动，并插入值
	}
	return ok;
}

Status Pop(SqDoublestack *s, Selemtype *e, int stacknumber)
{
	if (stacknumber == 1)
	{
		if (s->top1 == -1)//栈1已经为空栈
			return error;
		*e = s->data[s->top1--];//将栈顶1元素取出
	}
	else if (stacknumber == 2)
	{
		if (s->top2 == MAXSIZE)//栈2已经为空栈
			return error;
		*e = s->data[s->top2++];//将栈顶2元素取出
	}
	return ok;
}


//栈的链式实现，栈顶为链表的头节点，但是这个头节点对于栈来说失去意义，链栈不需要头节点
//考虑适用头插法实现栈的插入
//空链栈表示为：top=NULL
//定义链表
typedef struct StackNode
{
	Selemtype data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

//定义栈
typedef struct Linkstack
{
	LinkStackPtr top;
	int count;
}Linkstack;

Status push(Linkstack *S, Selemtype e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return ok;
}

Status pop(Linkstack *S, Selemtype *e)
{
	LinkStackPtr p;
	if (stackempty(*S))//判空
		return error;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return ok;
}





typedef int Qelemtype;
typedef int Status;

typedef struct
{
	Qelemtype data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status initQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return ok;
}

Status lengthQueue(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status InsertQueue(SqQueue *Q, Qelemtype e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return error;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return ok;
}

Status DeleteQueue(SqQueue *Q, Qelemtype*e)
{
	if (Q->front == Q->rear)
		return error;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return ok;
}



//链表实现队列，链表的头节点作为队头，尾节点作为队尾

//生成链表
typedef struct QNode
{
	Qelemtype data;
	struct QNode *next;
}QNode, *QueuePtr;
//生成队列
typedef struct
{
	QueuePtr front, rear;
}Linkqueue;

//初始化
Status initqueue(Linkqueue *q)
{
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)
		exit(0);
	q->front = q->rear = NULL;
}
//入队
Status EnQueue(Linkqueue *Q, Qelemtype e)
{
	QueuePtr s;
	s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)
		return error;
	s->data = e;
	Q->rear->next = s;
	Q->rear = s;
	return ok;
}

//出队
Status DeleteQueue(Linkqueue *Q, Qelemtype *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
		return error;
	p = Q->front->next;
	*e = p->data;
	Q->rear->next = p->next;
	if (Q->rear == p)//如果删除的元素是最后一个
		Q->rear == Q->front;
	free(p);
	return ok;
}


