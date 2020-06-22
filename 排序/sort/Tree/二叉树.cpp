#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;

#define MAX_TREE_SIZE 100

typedef int status;
typedef int elemtype;


//˫�ױ�ʾ��
//�ڵ�ṹ
typedef struct PTNode
{
	elemtype data;	//�ڵ�����
	int parent;	//˫��λ��
}PTNode;

//���ṹ
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];	//�ڵ�����
	int r, n;	//����λ�úͽڵ���
}PTree;



//˫��_���ӱ�ʾ��
typedef struct CTNode
{
	int child;	//���ӽڵ���±�
	struct CTNode *next;	//ָ����һ�����ӽڵ��ָ��
}*ChildPtr;

//��ͷ�ṹ
typedef struct
{
	elemtype data;	//��������еĽڵ�����
	int parent;	//���˫�׵��±�
	ChildPtr firstchild;	//ָ���һ�����������ͷָ��
}CTBox;

//���ṹ
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];	//�ڵ�����
	int r, n;	//����λ�úͽڵ���
};




//�������������ʾ
typedef struct BiTNode
{
	elemtype data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//�������Ĵ���
void CreateBiTree(BiTree *T)
{
	elemtype ch;
	cin >> ch;
	if (' ' == ch)
		*T == NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTree));
		if (!*T)
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}


//��������ǰ������ݹ��㷨
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	cout << T->data << endl;	//��ʾ�ڵ�����
	PreOrderTraverse(T->lchild);	//�ݹ�ǰ�����������
	PreOrderTraverse(T->rchild);	//�ݹ�ǰ�����������
}


//����������������ݹ��㷨
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);	//���ǰ����ӵĵݹ���ǰ�˶���
	cout << T->data << endl;
	InOrderTraverse(T->rchild);
}


//�������ĺ�������ݹ��㷨
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);	//�����ȵݹ�����
	PostOrderTraverse(T->rchild);	//Ȼ���ٵݹ��Һ���
	cout << T->data << endl;	//���������
}



