#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

#define  ok		1	//����һЩ�ַ����������
#define	error	0	
#define MAXSIZE	20	//�������Ա�����洢����

typedef int Elemtype;	//�������Ա��Ԫ��Elemtype�������ݽṹ
typedef int Status;		//�����Status�൱�ھ���int�������ݽṹ

//���Ա��˳��洢��ʽ
typedef struct
{
	Elemtype data[MAXSIZE];	//˳��洢�ĵ�һҪ�أ��洢������data��Ҳ���������data���ڶ�Ҫ�أ����Ա�����洢�����������������󳤶�MAXSIZE
	int length;	//����Ҫ�أ���ǰ���Ա�ĳ��ȣ�ʵ�ʵ�Ԫ������
}SqList;	//�����װ�����Ա�ı���ΪSqList


//˳��洢��ʽ��GetElem������ʵ�֣�������Ա�L�ĵ�i��λ��Ԫ�ز��ҷ���
Status GetElem(SqList L, int i, Elemtype *e)
{
	if (L.length == 0 || i<1 || i>L.length)	//�ų�һЩ���������
	{
		return error;
	}
	*e = L.data[i - 1];	//Ȼ�����Ա�ĵ�i-1��Ԫ�ظ���*e

	return ok;
}


//˳��洢��ʽ��ListInsert������ʵ�֣������Ա�*L�еĵ�i��λ�ò����µ�Ԫ��e
Status ListLnsert(SqList *L, int i, Elemtype e)
{
	int k;	//���������

	if (L->length == MAXSIZE)	//�ų����Ա��Ѿ��������
	{
		return error;
	}
	if (i<1 || i>L->length+1)	//�ų���i���ڷ�Χ�ڵ����
	{
		return error;
	}

	if (i <= L->length)		//��������ʱ
	{
		for (k = L->length - 1; k >= i - 1; k--)	//��Ҫ����λ�õĺ����Ԫ������ƶ�һλ
		{
			L->data[k+1] = L->data[k];	//�Ӻ���ǰ�����Ա��е�Ԫ������ƶ�
		}
	}

	L->data[i-1] = e;	//����Ԫ��e����
	L->length++;	//�����Ա�ĳ��ȼ�һ

	return ok;
}

//˳��洢��ʽ��ListDelete������ʵ�֣������Ա�*L�еĵ�i��λ�õ�Ԫ��ɾ��e
Status ListLnsert(SqList *L, int i, Elemtype *e)
{
	int k;	//���������

	if (L->length == 0)	//�ų����Ա�Ϊ0�����
	{
		return error;
	}
	if (i<1 || i>L->length)	//�ų���i���ڷ�Χ�ڵ����
	{
		return error;
	}

	*e = L->data[i - 1];	//����i-1��Ԫ�ظ���*e�����*e�ͻ�����ַ�����ͷ�

	if (i < L->length)		//Ȼ�󽫺����Ԫ����ǰ�ƶ�һλ���ѿճ�����λ�����
	{
		for (k = i; k < L->length ;  k++)	
		{
			L->data[k - 1] = L->data[k];	
		}
	}

	L->length--;	//�����Ա�ĳ��ȼ�һ

	return ok;
}


