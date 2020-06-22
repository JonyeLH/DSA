//静态链表：是使用数组描述的链表，这种方法也叫做游标实现法
//第一个位置的下标为0，且游标指向没有元素的第一个下标（备用链表的元素，带操作的元素）
//最后一个位置的游标指向第一个含有数据的元素下标
//最后一个含有数据的元素的游标指向0

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

#define ok	1
#define error 0
#define MAXSIZE 1000

typedef int Elemtype;
typedef int Status;

typedef struct
{
	Elemtype data;	//数据
	int cur;	//游标
}Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)	//初始化
{
	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		space[i].cur = i + 1;	//游标不断地指向下一位的
	}
	space[MAXSIZE - 1].cur = 0;	//最后的游标指向第一位有数据的位置，但是这里是初始化，链表里为空指向0
	return ok;
}


//静态链表的ListInsert操作，在静态链表L中第i个元素之前插入新元素e
Status ListInsert(StaticLinkList L, int i, Elemtype e)
{
	int l, j, k;
	k = MAXSIZE - 1;	//k为最后一个位置的下标值
	if (i<1 || i>ListLength(L) + 1)	//排除一些错误情况
	{
		return error;
	}

	j = Malloc_SLL(L);	//获取要插入值的空闲分量下标，已更新第一个位置的游标
	if (j)
	{
		L[j].data = e;	//将要插入元素的数据，赋给空闲分量的值域
		for (l = 0; l < i - 1; l++)	//循环要插入位置前的元素
		{
			k = L[k].cur;	//将最后元素的游标（1）赋给k
		}

		L[j].cur = L[k].cur;	//将第一个元素的游标，赋给带插入位置的游标
		L[k].cur = j;		//第一个元素的游标，则更新为待插入位置的下标

		return ok;	//完成插入操作
	}
	return error;	//否则为错误
}

//静态链表的ListDelete操作，删除静态链表L中第i个元素
Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	k = MAXSIZE - 1;
	if (i<1 || i>ListLength(L) + 1)
	{
		return error;
	}

	//这个循环能够得到第i个元素的前一个元素的下标
	for (j = 1; j < i - 1; j++)
	{
		k = L[k].cur;
	}

	j = L[k].cur;	//获得i的下标
	L[k].cur = L[j].cur;	//将下标i的游标，赋给i前一位的游标，以便第i个元素删除后，前一个元素和i后面的元素对接上

	Free_SLL(L, j);
	return ok;
}


//获取空闲分量的下标，函数Malloc_SLL，准备插入新元素
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;	//把第一个位置的游标给了i
	if (space[0].cur)	//只要数组不为0
	{
		space[0].cur = space[i].cur;	//则将空闲元素的游标，赋给了第一个位置的游标。
	}
	return i;
}

//返回L中的元素个数
int ListLength(StaticLinkList L)
{
	int j = 0;	//计数器
	int i = L[MAXSIZE - 1].cur;

	while (i)	//循环直到最后一个元素，最后一个元素的游标为0
	{
		i = L[i].cur;
		j++;	//统计个数
	}
	return j;

}

//将下标为k的空间节点回收到备用链表
void Free_SLL(StaticLinkList space, int i)
{
	space[i].cur = space[0].cur;	//将第k个的游标和备用节点相连，以便后面的回收
	space[0].cur = i;	//将第k个的下标赋给第一个位置的游标，让k的空间归入备用节点
}