//��̬������ʹ�������������������ַ���Ҳ�����α�ʵ�ַ�
//��һ��λ�õ��±�Ϊ0�����α�ָ��û��Ԫ�صĵ�һ���±꣨���������Ԫ�أ���������Ԫ�أ�
//���һ��λ�õ��α�ָ���һ���������ݵ�Ԫ���±�
//���һ���������ݵ�Ԫ�ص��α�ָ��0

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
	Elemtype data;	//����
	int cur;	//�α�
}Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)	//��ʼ��
{
	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		space[i].cur = i + 1;	//�α겻�ϵ�ָ����һλ��
	}
	space[MAXSIZE - 1].cur = 0;	//�����α�ָ���һλ�����ݵ�λ�ã����������ǳ�ʼ����������Ϊ��ָ��0
	return ok;
}


//��̬�����ListInsert�������ھ�̬����L�е�i��Ԫ��֮ǰ������Ԫ��e
Status ListInsert(StaticLinkList L, int i, Elemtype e)
{
	int l, j, k;
	k = MAXSIZE - 1;	//kΪ���һ��λ�õ��±�ֵ
	if (i<1 || i>ListLength(L) + 1)	//�ų�һЩ�������
	{
		return error;
	}

	j = Malloc_SLL(L);	//��ȡҪ����ֵ�Ŀ��з����±꣬�Ѹ��µ�һ��λ�õ��α�
	if (j)
	{
		L[j].data = e;	//��Ҫ����Ԫ�ص����ݣ��������з�����ֵ��
		for (l = 0; l < i - 1; l++)	//ѭ��Ҫ����λ��ǰ��Ԫ��
		{
			k = L[k].cur;	//�����Ԫ�ص��α꣨1������k
		}

		L[j].cur = L[k].cur;	//����һ��Ԫ�ص��α꣬����������λ�õ��α�
		L[k].cur = j;		//��һ��Ԫ�ص��α꣬�����Ϊ������λ�õ��±�

		return ok;	//��ɲ������
	}
	return error;	//����Ϊ����
}

//��̬�����ListDelete������ɾ����̬����L�е�i��Ԫ��
Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	k = MAXSIZE - 1;
	if (i<1 || i>ListLength(L) + 1)
	{
		return error;
	}

	//���ѭ���ܹ��õ���i��Ԫ�ص�ǰһ��Ԫ�ص��±�
	for (j = 1; j < i - 1; j++)
	{
		k = L[k].cur;
	}

	j = L[k].cur;	//���i���±�
	L[k].cur = L[j].cur;	//���±�i���α꣬����iǰһλ���α꣬�Ա��i��Ԫ��ɾ����ǰһ��Ԫ�غ�i�����Ԫ�ضԽ���

	Free_SLL(L, j);
	return ok;
}


//��ȡ���з������±꣬����Malloc_SLL��׼��������Ԫ��
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;	//�ѵ�һ��λ�õ��α����i
	if (space[0].cur)	//ֻҪ���鲻Ϊ0
	{
		space[0].cur = space[i].cur;	//�򽫿���Ԫ�ص��α꣬�����˵�һ��λ�õ��αꡣ
	}
	return i;
}

//����L�е�Ԫ�ظ���
int ListLength(StaticLinkList L)
{
	int j = 0;	//������
	int i = L[MAXSIZE - 1].cur;

	while (i)	//ѭ��ֱ�����һ��Ԫ�أ����һ��Ԫ�ص��α�Ϊ0
	{
		i = L[i].cur;
		j++;	//ͳ�Ƹ���
	}
	return j;

}

//���±�Ϊk�Ŀռ�ڵ���յ���������
void Free_SLL(StaticLinkList space, int i)
{
	space[i].cur = space[0].cur;	//����k�����α�ͱ��ýڵ��������Ա����Ļ���
	space[0].cur = i;	//����k�����±긳����һ��λ�õ��α꣬��k�Ŀռ���뱸�ýڵ�
}