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
	Elemtype data;	//链式存储的两个要素，第一：存放数据data的值域
	struct Node* Next;	//第二要素：指向下一个节点的Next指针
}Node;	//生成链表的名称Node
typedef struct Node* LinkList;	//Node*的节点别名LinkList


//线性表链式存储的GetElem函数实现，获得链表的第i个数据
//在函数传入的形参是什么形式的，那么在函数内部的参数也是相对应的，如这里的节点传入是L（而不是*L），则后面使用都是L，同理传入的参数是*e，后面则是使用*e
Status GetElem(LinkList L, int i, Elemtype *e)	
{
	int j;	//计数器
	LinkList p;	//生成节点p

	p = L->Next;	//节点p为初始链表L的Next
	j = 1;	//线性表是从1开始计数

	while (p && j < i)//循环找到第i个位置，且满足p为真
	{
		p = p->Next;	//不断将链表传接下去
		++j;	//自加循环
	}

	if (!p || j > i)	//不满足条件时
	{
		return error;
	}

	*e = p->data;	//取出第i位置的数据
	return ok;
}


//线性表链式存储的ListInsert函数实现，在链表的第i个位置插入数据e
Status ListInsert(LinkList *L, int i, Elemtype e)
{
	int j=1;	//计数器
	LinkList p, s;	//生成循环链接节点p，插入节点s
	p = *L;	//节点p为初始链表

	while (p && j < i)//循环找到第i个位置，且满足p为真
	{
		p = p->Next;	//不断将链表传接下去
		j++;	//自加循环
	}

	if (!p || j > i)	//不满足条件时
	{
		return error;
	}

	s = (LinkList)malloc(sizeof(Node));	//为新节点s申请内存空间
	s->data = e;	//将要插入的数据赋到节点s的数据域

	//以下两步的插入操作不能换位置，否则s->Next就是指向s自身。
	s->Next = p->Next;	//将位置i的节点p的Next赋给要插入节点s的Next
	p->Next = s;	//在把i位置的p节点的Next指向s节点，完成插入操作

	return ok;
}


//线性表链式存储的ListDelete函数实现，删除链表的第i个位置的数据e
Status ListDelete(LinkList *L, int i, Elemtype *e)
{
	int j = 1;
	LinkList p, q;	//生成一个循环链接节点p，临时节点q
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

	//方法一，使用临时节点q
	q = p->Next;	//临时节点q存储原来p节点的Next，相当于临时节点q就是要删除的节点
	p->Next = q->Next;	//再把q->Next（原来p节点的Next的Next）赋给现在的p节点的Next

	*e = q->data;	//将要删除的数据赋给*e
	free(q);	//释放节点q，完成删除操作

	//方法二，一步到位
	*e = p->Next->data;	//将要删除的数据赋给*e
	p->Next = p->Next->Next;	//再把原来p节点的Next的Next赋给现在的p节点的Next
	free(p->Next);	//释放要删除的节点

	return ok;
}

//头插法创建单链表
void CreateListHead(LinkList *L, int n)	//这里的n表示插入多少个节点
{
	LinkList p;
	int i ;

	//srand(time(0));//初始化随机数种子

	*L = (LinkList)malloc(sizeof(Node));	//声明和初始化链表*L的头节点
	(*L)->Next = NULL;	//头节点的指针为Null，建立 一个带头节点

	for (i = 0; i < n; i++)	//循环插入n个节点
	{
		p = (LinkList)malloc(sizeof(Node));	//为插入节点申请内存空间
		p->data = rand() % 100 + 1;	//随机生成两位数的p节点的数据域
		p->Next = (*L)->Next;	//把原来节点的Next赋给插入节点p的Next，完成原链表的节点后移，新节点的向前插入
		(*L)->Next = p;	//将p节点赋值到原链表*L（头节点）next，完成头插法。
	}
}


//尾插法创建单链表
void CreateListTail(LinkList *L, int n)
{
	LinkList p,r;
	int i;

	//srand(time(0));//初始化随机数种子
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;

	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));	
		p->data = rand() % 100 + 1;	
		r->Next = p;	//把生成p节点赋给节点r的Next
		r = p;	//把尾节点向后一个节点移动，完成尾插法
	}
}

//单链表的正表删除
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
	(*L)->Next = NULL;//最后单链表为空表NULL
	return ok;
}