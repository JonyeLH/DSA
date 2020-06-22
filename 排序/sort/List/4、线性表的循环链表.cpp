#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define ok	1
#define error 0

typedef int Elemtype;
typedef int Status;

//定义链表
typedef struct CLinkList
{
	Elemtype data;
	struct CLinkList* Next;
}Node;
//typedef struct Node* LinkList;	

void ds_init(Node **pNode)
{
	int item;
	Node *temp;
	Node *target;

	//printf("输入节点的值，输入0完成初始化\n");
	cout << "输入节点的值，输入0完成初始化\n";

	while (1)
	{
		cin >> item;
		fflush(stdin);

		if (item == 0)
		{
			return;
		}
		if ((*pNode) == NULL)
		{
			*pNode = (Node *)malloc(sizeof(struct CLinkList));
			if (!(*pNode))
				exit(0);
			(*pNode)->data = item;
			(*pNode)->Next = *pNode;
		}
		else
		{
			for (target = (*pNode); target->Next != (*pNode); target = target->Next);
			temp = (Node *)malloc(sizeof(struct CLinkList));

			if (!item)
				exit(0);

			temp->data = item;
			temp->Next = *pNode;
			target->Next = temp;
		}
	}
}

//循环链表的插入
void ds_Insert(Node **pNode, int i)
{
	Node *temp;
	Node *target;
	Node *p;
	int item;
	int j = 1;

	cout << "要插入的值：";
	cin >> item;

	if (i == 1)
	{
		//新插入的节点作为一个节点
		temp = (Node *)malloc(sizeof(struct CLinkList));
		if (!item)
			exit(0);
		temp->data = item;

		//找到最后的一个节点
		for (target = (*pNode); target->Next != (*pNode); target = target->Next);

		temp->Next = *pNode;
		target->Next = temp;
		*pNode = temp;
	}
	else
	{
		target = *pNode;
		for (; i < (i - 1); ++j)
		{
			target = target->Next;
		}
		temp = (Node *)malloc(sizeof(struct CLinkList));

		if (!item)
			exit(0);

		temp->data = item;
		p = target->Next;
		target->Next = temp;
		temp->Next = p;
	}
}

//删除
void da_Delete(Node **pNode, int i)
{
	Node *temp;
	Node *target;
	int j = 1;


	if (i == 1)
	{
		//找到最后的一个节点
		for (target = (*pNode); target->Next != (*pNode); target = target->Next);

		temp = *pNode;
		*pNode = (*pNode)->Next;
		target->Next = *pNode;
		free(temp);
	}
	else
	{
		target = *pNode;

		for (; i < (i - 1); ++j)
		{
			target = target->Next;
		}

		temp = target->Next;
		target->Next = temp->Next;
		free(temp);
	}
}

//查找
int da_Search(Node *pNode, int elem)
{
	Node *target;
	int i = 1;

	for (target = pNode; target->data != elem && target->Next != pNode; ++i)
	{
		target = target->Next;
	}

	if (target->Next = pNode)	//表中不存在该元素
		return 0;

	else
		return 1;
}

//判断单链表中是否有环
