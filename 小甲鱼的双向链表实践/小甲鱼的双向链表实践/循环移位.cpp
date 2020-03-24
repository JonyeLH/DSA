#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

#define OK		1
#define error	0

typedef char ElemType;	//在这可以修改链表里的元素类型
typedef int Status;

typedef struct DualNode
{
	ElemType data;
	struct DualNode *prior;
	struct DualNode *next;

}DualNode, *DuLinklist;

Status initLink(DuLinklist *L)
{
	DualNode *p, *q;
	int i;

	*L = (DuLinklist)malloc(sizeof(DualNode));
	if (!(*L))
	{
		return error;
	}

	(*L)->next = (*L)->prior = NULL;
	p = (*L);

	for (i = 0; i < 26; i++)
	{
		q = (DualNode *)malloc(sizeof(DualNode));
		if (!q)
		{
			return error;
		}

		q->data = 'A' + i;
		q->prior = p;
		q->next = p->next;
		p->next = q;

		p = q;
	}
	p->next = (*L)->next;
	(*L)->next -> prior = p;

	return OK;
}

void Ceesar(DuLinklist *L, int i)
{
	if (i > 0)
	{
		do
		{
			(*L) = (*L)->next;
		} while (--i);
	}

	if (i < 0)
	{
		do 
		{
			(*L) = (*L)->next;
		} while (++i);
	}
}

int main()
{
	DuLinklist L;
	int i, n=0;

	initLink(&L);
	cout << "请输入一个整数：" ;
	cin >> n ;
	//scanf("%d", &n);
	Ceesar(&L, n);

	for (i = 0; i < 26; i++)
	{
		L = L->next;
		cout << L->data ;
		//printf("%c", L->data);
	}

	system("pause");
	return 0;
}