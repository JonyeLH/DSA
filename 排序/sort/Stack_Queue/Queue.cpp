#include <string>
#include <math.h>
#include <algorithm>
using namespace std;


#define ok	1
#define error 0
#define MAXSIZE 100

typedef int Elemtype;
typedef int Status;

//队列的节点申明
typedef struct QNode
{
	Elemtype data;
	struct QNode *next;
}QNode, *QueuePrt;

typedef struct
{
	QueuePrt front, rear;	//队头，队尾
}LinkQueue;

//初始化
Status initQueue(LinkQueue *q)
{
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if (!q->front)
		exit(0);
	q->front = q->rear = NULL;
}


//入队
Status InsertQueue(LinkQueue *q, Elemtype e)
{
	QueuePrt p;
	p = (QueuePrt)malloc(sizeof(QNode));
	if (p == NULL)
		exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

//出队
Status DeleteQueue(LinkQueue *q, Elemtype *e)
{
	QueuePrt p;
	if (q->front = q->rear)
		return error;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)
	{
		q->rear = q->front;
	}
	free(p);
}

//销毁队列
Status DistoryQueue(LinkQueue *q)
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}

//队列的顺序存储方式
//定义一个循环列队
typedef struct
{
	Elemtype *base;	//用于存放内存分配基地址，可以使用数组存放
	int front;
	int rear;
}cycleQueue;

//初始化循环列队
Status InitQueue(cycleQueue *q)
{
	q->base = (Elemtype *)malloc(MAXSIZE * sizeof(Elemtype));
	if (!q->base)
		exit(0);
	q->front = q->rear = 0;
}

//入队
Status InsertQueue(cycleQueue *q, Elemtype e)
{
	if ((q->rear = 1) % MAXSIZE == q->front)
		return;
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
}

//出队
Status DeleteQueue(cycleQueue *q, Elemtype *e)
{
	if (q->front = q->rear)
		return;
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
}
