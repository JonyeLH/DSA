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
	int j = 1;	//������
	DuLinkList p, s;	//����ѭ�����ӽڵ�p������ڵ�s
	p = *L;	//�ڵ�pΪ��ʼ����

	while (p && j < i)//ѭ���ҵ���i��λ�ã�������pΪ��
	{
		p = p->next;	//���Ͻ���������ȥ
		j++;	//�Լ�ѭ��
	}

	if (!p || j > i)	//����������ʱ
	{
		return error;
	}

	s = (DuLinkList)malloc(sizeof(DualNode));	//Ϊ�½ڵ�s�����ڴ�ռ�
	s->data = e;	//��Ҫ��������ݸ����ڵ�s��������

	s->next = p;
	s->prior = p->prior;
	p->prior->next = s;
	p->prior = s;

	return ok;
}

Status DualDelete(DuLinkList *L, int i, Elemtype e)
{
	int j = 1;
	DuLinkList p;	//����һ��ѭ�����ӽڵ�p����ʱ�ڵ�q
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