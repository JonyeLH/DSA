#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

#define  ok		1	//定义一些字符代表的意义
#define	error	0	
#define MAXSIZE	20	//定义线性表的最大存储容量

typedef int Elemtype;	//定义线性表的元素Elemtype及其数据结构
typedef int Status;		//这里的Status相当于就是int类型数据结构

//线性表的顺序存储方式
typedef struct
{
	Elemtype data[MAXSIZE];	//顺序存储的第一要素，存储的数据data，也就是数组的data。第二要素，线性表的最大存储容量：定义的数组最大长度MAXSIZE
	int length;	//第三要素，当前线性表的长度，实际的元素容量
}SqList;	//数组封装成线性表的别名为SqList


//顺序存储方式的GetElem函数的实现，获得线性表L的第i个位置元素并且返回
Status GetElem(SqList L, int i, Elemtype *e)
{
	if (L.length == 0 || i<1 || i>L.length)	//排除一些错误的条件
	{
		return error;
	}
	*e = L.data[i - 1];	//然后将线性表的第i-1个元素赋给*e

	return ok;
}


//顺序存储方式的ListInsert函数的实现，在线性表*L中的第i个位置插入新的元素e
Status ListLnsert(SqList *L, int i, Elemtype e)
{
	int k;	//定义计数器

	if (L->length == MAXSIZE)	//排除线性表已经满了情况
	{
		return error;
	}
	if (i<1 || i>L->length+1)	//排除当i不在范围内的情况
	{
		return error;
	}

	if (i <= L->length)		//满足条件时
	{
		for (k = L->length - 1; k >= i - 1; k--)	//将要插入位置的后面的元素向后移动一位
		{
			L->data[k+1] = L->data[k];	//从后往前将线性表中的元素向后移动
		}
	}

	L->data[i-1] = e;	//将新元素e插入
	L->length++;	//将线性表的长度加一

	return ok;
}

//顺序存储方式的ListDelete函数的实现，在线性表*L中的第i个位置的元素删除e
Status ListLnsert(SqList *L, int i, Elemtype *e)
{
	int k;	//定义计数器

	if (L->length == 0)	//排除线性表为0的情况
	{
		return error;
	}
	if (i<1 || i>L->length)	//排除当i不在范围内的情况
	{
		return error;
	}

	*e = L->data[i - 1];	//将第i-1个元素赋给*e，这个*e就会归入地址池中释放

	if (i < L->length)		//然后将后面的元素向前移动一位，把空出来的位置填充
	{
		for (k = i; k < L->length ;  k++)	
		{
			L->data[k - 1] = L->data[k];	
		}
	}

	L->length--;	//将线性表的长度减一

	return ok;
}


