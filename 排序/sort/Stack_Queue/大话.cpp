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

//ջ��˳��洢ʵ�֣�����ĵ�һ��λ����Ϊջ�ף����һ����Ϊջ��
typedef struct
{
	Selemtype data[MAXSIZE];
	int top;
}Sqstack;

//��ջ
Status push(Sqstack *s, Selemtype e)
{
	if (s->top > MAXSIZE)
		return error;
	s->top++;
	s->data[s->top] = e;
	return ok;
}

//��ջ
Status pop(Sqstack *s, Selemtype *e)
{
	if (s->top == -1)
		return error;
	*e = s->data[s->top];
	s->top--;
	return ok;
}

//��ջ����ռ�,������ջ������������һ�µģ�Ϊ�˽�ʡ�ռ�
//����ʹһ��ջ��ջ��Ϊ�����ͷ�ˣ���������
//��һ��ջ����ջ��Ϊ�����β�ˣ���ǰ����
//������ջ��ջ������ʱ������ָ��֮�����1����top1+=top2.��ʱ����ռ�ľ�
//������һ��ջ������һ��ջ���̵����
typedef struct
{
	Selemtype data[MAXSIZE];
	int top1;
	int top2;
}SqDoublestack;

Status Push(SqDoublestack *s, Selemtype e, int stacknumber)//stacknumber�ж���ջ1����ջ2
{
	if (s->top1 + 1 == s->top2)//����ջ��������ջ����������push��
		return error;
	if (stacknumber == 1)
	{
		s->data[++s->top1] = e;//ջ��1����ƶ���������ֵ
	}
	else if (stacknumber == 2)
	{
		s->data[--s->top2] = e;//ջ��2��ǰ�ƶ���������ֵ
	}
	return ok;
}

Status Pop(SqDoublestack *s, Selemtype *e, int stacknumber)
{
	if (stacknumber == 1)
	{
		if (s->top1 == -1)//ջ1�Ѿ�Ϊ��ջ
			return error;
		*e = s->data[s->top1--];//��ջ��1Ԫ��ȡ��
	}
	else if (stacknumber == 2)
	{
		if (s->top2 == MAXSIZE)//ջ2�Ѿ�Ϊ��ջ
			return error;
		*e = s->data[s->top2++];//��ջ��2Ԫ��ȡ��
	}
	return ok;
}


//ջ����ʽʵ�֣�ջ��Ϊ�����ͷ�ڵ㣬�������ͷ�ڵ����ջ��˵ʧȥ���壬��ջ����Ҫͷ�ڵ�
//��������ͷ�巨ʵ��ջ�Ĳ���
//����ջ��ʾΪ��top=NULL
//��������
typedef struct StackNode
{
	Selemtype data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

//����ջ
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
	if (stackempty(*S))//�п�
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



//����ʵ�ֶ��У������ͷ�ڵ���Ϊ��ͷ��β�ڵ���Ϊ��β

//��������
typedef struct QNode
{
	Qelemtype data;
	struct QNode *next;
}QNode, *QueuePtr;
//���ɶ���
typedef struct
{
	QueuePtr front, rear;
}Linkqueue;

//��ʼ��
Status initqueue(Linkqueue *q)
{
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)
		exit(0);
	q->front = q->rear = NULL;
}
//���
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

//����
Status DeleteQueue(Linkqueue *Q, Qelemtype *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
		return error;
	p = Q->front->next;
	*e = p->data;
	Q->rear->next = p->next;
	if (Q->rear == p)//���ɾ����Ԫ�������һ��
		Q->rear == Q->front;
	free(p);
	return ok;
}


