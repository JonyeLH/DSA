#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define ok	1
#define error 0

typedef int Elemtype;
typedef int Status;

typedef struct DualNode
{
	Elemtype data;
	struct DualNode *prior;
	struct DualNode *next;
}DualNode, *DuLinkList;

Status DualInsert(DuLinkList *L, int i, Elemtype e)
{
	int j = 1;	//计数器
	DuLinkList p, s;	//生成循环链接节点p，插入节点s
	p = *L;	//节点p为初始链表

	while (p && j < i)//循环找到第i个位置，且满足p为真
	{
		p = p->next;	//不断将链表传接下去
		j++;	//自加循环
	}

	if (!p || j > i)	//不满足条件时
	{
		return error;
	}

	s = (DuLinkList)malloc(sizeof(DualNode));	//为新节点s申请内存空间
	s->data = e;	//将要插入的数据赋到节点s的数据域

	s->next = p;
	s->prior = p->prior;
	p->prior->next = s;
	p->prior = s;

	return ok;
}

Status DualDelete(DuLinkList *L, int i, Elemtype e)
{
	int j = 1;
	DuLinkList p;	//生成一个循环链接节点p，临时节点q
	p = *L;

	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}

	if (!p->next || j > i)
	{
		return error;
	}

	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
}