#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

#define ok	1
#define error 0

typedef int Elemtype;
typedef int Status;

typedef struct Node
{
	Elemtype data;	//��ʽ�洢������Ҫ�أ���һ���������data��ֵ��
	struct Node* Next;	//�ڶ�Ҫ�أ�ָ����һ���ڵ��Nextָ��
}Node;	//�������������Node
typedef struct Node* LinkList;	//Node*�Ľڵ����LinkList


//���Ա���ʽ�洢��GetElem����ʵ�֣��������ĵ�i������
//�ں���������β���ʲô��ʽ�ģ���ô�ں����ڲ��Ĳ���Ҳ�����Ӧ�ģ�������Ľڵ㴫����L��������*L���������ʹ�ö���L��ͬ����Ĳ�����*e����������ʹ��*e
Status GetElem(LinkList L, int i, Elemtype *e)	
{
	int j;	//������
	LinkList p;	//���ɽڵ�p

	p = L->Next;	//�ڵ�pΪ��ʼ����L��Next
	j = 1;	//���Ա��Ǵ�1��ʼ����

	while (p && j < i)//ѭ���ҵ���i��λ�ã�������pΪ��
	{
		p = p->Next;	//���Ͻ���������ȥ
		++j;	//�Լ�ѭ��
	}

	if (!p || j > i)	//����������ʱ
	{
		return error;
	}

	*e = p->data;	//ȡ����iλ�õ�����
	return ok;
}


//���Ա���ʽ�洢��ListInsert����ʵ�֣�������ĵ�i��λ�ò�������e
Status ListInsert(LinkList *L, int i, Elemtype e)
{
	int j=1;	//������
	LinkList p, s;	//����ѭ�����ӽڵ�p������ڵ�s
	p = *L;	//�ڵ�pΪ��ʼ����

	while (p && j < i)//ѭ���ҵ���i��λ�ã�������pΪ��
	{
		p = p->Next;	//���Ͻ���������ȥ
		j++;	//�Լ�ѭ��
	}

	if (!p || j > i)	//����������ʱ
	{
		return error;
	}

	s = (LinkList)malloc(sizeof(Node));	//Ϊ�½ڵ�s�����ڴ�ռ�
	s->data = e;	//��Ҫ��������ݸ����ڵ�s��������

	//���������Ĳ���������ܻ�λ�ã�����s->Next����ָ��s����
	s->Next = p->Next;	//��λ��i�Ľڵ�p��Next����Ҫ����ڵ�s��Next
	p->Next = s;	//�ڰ�iλ�õ�p�ڵ��Nextָ��s�ڵ㣬��ɲ������

	return ok;
}


//���Ա���ʽ�洢��ListDelete����ʵ�֣�ɾ������ĵ�i��λ�õ�����e
Status ListDelete(LinkList *L, int i, Elemtype *e)
{
	int j = 1;
	LinkList p, q;	//����һ��ѭ�����ӽڵ�p����ʱ�ڵ�q
	p = *L;

	while (p->Next && j < i)
	{
		p = p->Next;
		++j;
	}

	if (!p->Next || j > i)
	{
		return error;
	}

	//����һ��ʹ����ʱ�ڵ�q
	q = p->Next;	//��ʱ�ڵ�q�洢ԭ��p�ڵ��Next���൱����ʱ�ڵ�q����Ҫɾ���Ľڵ�
	p->Next = q->Next;	//�ٰ�q->Next��ԭ��p�ڵ��Next��Next���������ڵ�p�ڵ��Next

	*e = q->data;	//��Ҫɾ�������ݸ���*e
	free(q);	//�ͷŽڵ�q�����ɾ������

	//��������һ����λ
	*e = p->Next->data;	//��Ҫɾ�������ݸ���*e
	p->Next = p->Next->Next;	//�ٰ�ԭ��p�ڵ��Next��Next�������ڵ�p�ڵ��Next
	free(p->Next);	//�ͷ�Ҫɾ���Ľڵ�

	return ok;
}

//ͷ�巨����������
void CreateListHead(LinkList *L, int n)	//�����n��ʾ������ٸ��ڵ�
{
	LinkList p;
	int i ;

	//srand(time(0));//��ʼ�����������

	*L = (LinkList)malloc(sizeof(Node));	//�����ͳ�ʼ������*L��ͷ�ڵ�
	(*L)->Next = NULL;	//ͷ�ڵ��ָ��ΪNull������ һ����ͷ�ڵ�

	for (i = 0; i < n; i++)	//ѭ������n���ڵ�
	{
		p = (LinkList)malloc(sizeof(Node));	//Ϊ����ڵ������ڴ�ռ�
		p->data = rand() % 100 + 1;	//���������λ����p�ڵ��������
		p->Next = (*L)->Next;	//��ԭ���ڵ��Next��������ڵ�p��Next�����ԭ����Ľڵ���ƣ��½ڵ����ǰ����
		(*L)->Next = p;	//��p�ڵ㸳ֵ��ԭ����*L��ͷ�ڵ㣩next�����ͷ�巨��
	}
}


//β�巨����������
void CreateListTail(LinkList *L, int n)
{
	LinkList p,r;
	int i;

	//srand(time(0));//��ʼ�����������
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;

	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));	
		p->data = rand() % 100 + 1;	
		r->Next = p;	//������p�ڵ㸳���ڵ�r��Next
		r = p;	//��β�ڵ����һ���ڵ��ƶ������β�巨
	}
}

//�����������ɾ��
Status ClearList(LinkList *L)
{
	LinkList p, q;
	
	p = (*L)->Next;

	while (p)
	{
		q = p->Next;
		free(p);
		p = q;
	}
	(*L)->Next = NULL;//�������Ϊ�ձ�NULL
	return ok;
}