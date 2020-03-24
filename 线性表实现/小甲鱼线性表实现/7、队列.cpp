#include <string>
#include <math.h>
#include <algorithm>
using namespace std;


#define ok	1
#define error 0
#define MAXSIZE 100

typedef int Elemtype;
typedef int Status;

//���еĽڵ�����
typedef struct QNode
{
	Elemtype data;
	struct QNode *next;
}QNode, *QueuePrt;

typedef struct
{
	QueuePrt front, rear;	//��ͷ����β
}LinkQueue;

//��ʼ��
Status initQueue(LinkQueue *q)
{
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if (!q->front)
		exit(0);
	q->front = q->rear = NULL;
}


//���
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

//����
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

//���ٶ���
Status DistoryQueue(LinkQueue *q)
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}

//���е�˳��洢��ʽ
//����һ��ѭ���ж�
typedef struct
{
	Elemtype *base;	//���ڴ���ڴ�������ַ������ʹ��������
	int front;
	int rear;
}cycleQueue;

//��ʼ��ѭ���ж�
Status InitQueue(cycleQueue *q)
{
	q->base = (Elemtype *)malloc(MAXSIZE * sizeof(Elemtype));
	if (!q->base)
		exit(0);
	q->front = q->rear = 0;
}

//���
Status InsertQueue(cycleQueue *q, Elemtype e)
{
	if ((q->rear = 1) % MAXSIZE == q->front)
		return;
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
}

//����
Status DeleteQueue(cycleQueue *q, Elemtype *e)
{
	if (q->front = q->rear)
		return;
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
}
