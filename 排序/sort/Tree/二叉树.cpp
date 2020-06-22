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


//双亲表示法
//节点结构
typedef struct PTNode
{
	elemtype data;	//节点数据
	int parent;	//双亲位置
}PTNode;

//树结构
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];	//节点数组
	int r, n;	//根的位置和节点数
}PTree;



//双亲_孩子表示法
typedef struct CTNode
{
	int child;	//孩子节点的下标
	struct CTNode *next;	//指向下一个孩子节点的指针
}*ChildPtr;

//表头结构
typedef struct
{
	elemtype data;	//存放在树中的节点数据
	int parent;	//存放双亲的下标
	ChildPtr firstchild;	//指向第一个孩子链表的头指针
}CTBox;

//树结构
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];	//节点数组
	int r, n;	//根的位置和节点数
};




//二叉树的链表表示
typedef struct BiTNode
{
	elemtype data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//二叉树的创建
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


//二叉树的前序遍历递归算法
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	cout << T->data << endl;	//显示节点数据
	PreOrderTraverse(T->lchild);	//递归前序遍历左子树
	PreOrderTraverse(T->rchild);	//递归前序遍历右子树
}


//二叉树的中序遍历递归算法
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);	//就是把左孩子的递归提前了而已
	cout << T->data << endl;
	InOrderTraverse(T->rchild);
}


//二叉树的后序遍历递归算法
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);	//就是先递归左孩子
	PostOrderTraverse(T->rchild);	//然后再递归右孩子
	cout << T->data << endl;	//再输出数据
}



