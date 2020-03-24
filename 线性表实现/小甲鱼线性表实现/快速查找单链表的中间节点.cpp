//快速查找单链表的中间节点
//使用快慢指针的方法：设置两个都从头节点开始的指针，快指针的移动速度是慢指针的两倍
//当快指针指向尾节点时，慢指针刚好落在中间节点

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
	Elemtype data;	
	struct Node* Next;
}Node;
typedef struct Node* LinkList;

Status GetMidNode(LinkList L, Elemtype *e)
{
	LinkList search, mid;
	mid = search = L;

	while (search->Next != NULL)	//先判断快指针的Next是否到了链表的终点
	{
		//定义search的移动速度是mid的两倍
		if (search->Next->Next != NULL)	//再判断快指针的Next的Next是否到了链表的终点
		{
			search = search->Next->Next;
			mid = mid->Next;
		}
		else
		{
			search = search->Next;
		}
	}

	*e = mid->data;	//取出中间节点数据，就是mid节点的数据

	return ok;
}
