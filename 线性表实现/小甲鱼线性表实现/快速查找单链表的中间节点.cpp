//���ٲ��ҵ�������м�ڵ�
//ʹ�ÿ���ָ��ķ�����������������ͷ�ڵ㿪ʼ��ָ�룬��ָ����ƶ��ٶ�����ָ�������
//����ָ��ָ��β�ڵ�ʱ����ָ��պ������м�ڵ�

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

	while (search->Next != NULL)	//���жϿ�ָ���Next�Ƿ���������յ�
	{
		//����search���ƶ��ٶ���mid������
		if (search->Next->Next != NULL)	//���жϿ�ָ���Next��Next�Ƿ���������յ�
		{
			search = search->Next->Next;
			mid = mid->Next;
		}
		else
		{
			search = search->Next;
		}
	}

	*e = mid->data;	//ȡ���м�ڵ����ݣ�����mid�ڵ������

	return ok;
}
