//线索二叉树：在定义普通二叉树结构中，叶子节点的指针域是空缺的，不存储任何东西，是一种资源的浪费
//所以采用不同的二叉树遍历方式，充分利用叶子节点的空缺指针。
//如采取中序遍历方式，将可以大幅度提升资源利用率

//typedef enmu { Link,Thread } PointerTag;
//typedef struct BiThrNode
//{
//	elemtype data;
//	struct BiThrNode *lchild, *rchild;
//	//PointerTag Ltag;
//	//PointerTag Rtag;
//	int Ltag, Rtag;
//}BiThrNode,*BiThrTree;
//
//BiTree pre;
//void InTreading(BiThrTree p)
//{
//	if (p)
//	{
//		InTreading(p->lchild);
//		if (!p->lchild)
//		{
//		p->Ltag=
//		}
//	}
//}

#include <stdio.h>
#include <stdlib.h>
#include<stack>
#include<stack>
#define LINK 0 //指针
#define THREAD 1  //线索
using namespace std;
//线索二叉树的数据结构
typedef  struct BTNode {
	int data;
	struct BTNode *lChild;
	struct BTNode *rChild;
	int LTag, RTag;
}BiTNode;
//先序创建二叉树，递归实现
void CreateBiTree(BiTNode **T) {
	int ch;
	scanf("%d", &ch);
	if (ch == -1) {
		*T = NULL;
		return;
	}
	else {
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		(*T)->LTag = 0;
		(*T)->RTag = 0;
		printf("输入%d左子结点", ch);
		CreateBiTree(&((*T)->lChild));
		printf("输入%d右子结点", ch);
		CreateBiTree(&((*T)->rChild));
	}
	return;
}
//二叉树线索化，中序遍历
void InTreading(BiTNode **p);
BiTNode *pre;                        //用于指向P的前一个指针，只能用作全局变量
void InOrderThreading(BiTNode **Thrt, BiTNode **T) {
	//中序遍历二叉树T,并将其线索化，Thrt指向头结点
	*Thrt = (BiTNode*)malloc(sizeof(BiTNode));
	(*Thrt)->LTag = LINK;               //建立头结点,LTag为指针，指向刚刚创建好的二叉树
	(*Thrt)->RTag = THREAD;              //RTag为线索
	(*Thrt)->rChild = (*Thrt);             //右孩子回指
	if (!T)
		(*Thrt)->lChild = (*Thrt);       //若二叉树为空，左指针回指
	else {
		(*Thrt)->lChild = (*T);
		pre = (*Thrt);
		InTreading(&(*T));              //中序遍历进行中序线索化
		pre->rChild = (*Thrt);          //最后一个结点线索化，将最后一个孩子的右子树回指，代表遍历结束
		pre->RTag = THREAD;
		(*Thrt)->rChild = pre;        //个人觉得可有可无
	}
}
void InTreading(BiTNode **p) {
	if (*p) {
		InTreading(&(*p)->lChild);  //左子树线索化
		if (!(*p)->lChild) {             //前驱线索
			(*p)->LTag = THREAD;
			(*p)->lChild = pre;
		}
		if (!pre->rChild) {            //后继线索
			pre->RTag = THREAD;
			pre->rChild = (*p);
		}
		pre = (*p);                      //保持pre指向P的前驱
		InTreading(&(*p)->rChild);  //右子树线索化
									/*注意中序遍历的次序，其中次序不能调换，
									因为左子树的前驱是上一个pre,在右子树线索化之前得把pre置成p*/
	}
}
//线索二叉树的遍历（中序遍历）非递归
void InOrderTraverse(BiTNode *T) {
	BiTNode *p = T->lChild;             //p指向根节点
	while (p != T) {  //空树或遍历结束时，p==T
		while (p->LTag == LINK)
			p = p->lChild;          //向左走到尽头
		printf("%d", p->data);     //访问其左子树为空的结点
		while (p->RTag == THREAD&&p->rChild != T) {
			p = p->rChild;
			printf("%d", p->data);       //访问后继结点,即双亲
		}
		p = p->rChild;
	}
}

//二叉树线索化，先序遍历
void PreTreading(BiTNode **p);
BiTNode *pre1;                        //用于指向P的前一个指针，只能用作全局变量
void PreOrderThreading(BiTNode **Thrt, BiTNode **T) {
	//先序遍历二叉树T,并将其线索化，Thrt指向头结点
	*Thrt = (BiTNode*)malloc(sizeof(BiTNode));
	(*Thrt)->LTag = LINK;               //建立头结点,LTag为指针，指向刚刚创建好的二叉树
	(*Thrt)->RTag = THREAD;              //RTag为线索
	(*Thrt)->rChild = (*Thrt);             //右孩子回指
	if (!T)
		(*Thrt)->lChild = (*Thrt);       //若二叉树为空，左指针回指
	else {
		(*Thrt)->lChild = (*T);
		pre1 = (*Thrt);
		PreTreading(&(*T));              //先序遍历进行中序线索化
		pre1->rChild = (*Thrt);          //最后一个结点线索化，将最后一个孩子的右子树回指，代表遍历结束
		pre1->RTag = THREAD;
		(*Thrt)->rChild = pre1;        //个人觉得可有可无
	}
}
void PreTreading(BiTNode **p) {
	if (*p) {
		if (!(*p)->lChild) {             //前驱线索
			(*p)->LTag = THREAD;
			(*p)->lChild = pre1;
		}
		if (!pre1->rChild) {            //后继线索
			pre1->RTag = THREAD;
			pre1->rChild = (*p);
		}
		pre1 = (*p);                      //保持pre指向P的前驱
		if ((*p)->LTag != THREAD)
			PreTreading(&(*p)->lChild);  //左子树线索化
		if ((*p)->RTag != THREAD)
			PreTreading(&(*p)->rChild);  //右子树线索化
	}
}
//线索二叉树的遍历（先序遍历）非递归
void PreOrderTraverse(BiTNode *T) {
	BiTNode *p = T->lChild;             //p指向根节点
	while (p != T) {  //空树或遍历结束时，p==T
		printf("%d", p->data);
		if (p->LTag == LINK) {
			p = p->lChild;
		}
		else if (p->LTag == THREAD) {
			p = p->rChild;
		}
	}
}

//二叉树线索化，后序遍历
void PostTreading(BiTNode **p);
BiTNode *pre2;                        //用于指向P的前一个指针，只能用作全局变量
void PostOrderThreading(BiTNode **Thrt, BiTNode **T) {
	//后序遍历二叉树T,并将其线索化，Thrt指向头结点
	*Thrt = (BiTNode*)malloc(sizeof(BiTNode));
	(*Thrt)->LTag = LINK;               //建立头结点,LTag为指针，指向刚刚创建好的二叉树
	(*Thrt)->RTag = THREAD;              //RTag为线索
	(*Thrt)->rChild = (*Thrt);             //右孩子回指
	if (!T)
		(*Thrt)->lChild = (*Thrt);       //若二叉树为空，左指针回指
	else {
		(*Thrt)->lChild = (*T);
		pre2 = (*Thrt);
		PostTreading(&(*T));              //后序遍历进行中序线索化
										  //后序不需要对最后一个节点线索化
										  //        pre2->rChild=(*Thrt);          //最后一个结点线索化，将最后一个孩子的右子树回指，代表遍历结束
										  //        pre2->RTag=THREAD;
										  //        (*Thrt)->rChild=pre2;        //个人觉得可有可无
	}
}
void PostTreading(BiTNode **p) {
	if (*p) {
		PostTreading(&(*p)->lChild);  //左子树线索化
		PostTreading(&(*p)->rChild);  //右子树线索化
		if (!(*p)->lChild) {             //前驱线索
			(*p)->LTag = THREAD;
			(*p)->lChild = pre2;
		}
		if (!pre2->rChild) {            //后继线索
			pre2->RTag = THREAD;
			pre2->rChild = (*p);
		}
		pre2 = (*p);                      //保持pre指向P的前驱
	}
}
//线索二叉树的遍历（后序遍历）非递归，用到栈的方法进行回溯，个人感觉比较复杂
void PostOrderTraverse(BiTNode *T) {
	BiTNode *p = T->lChild, *q;             //p指向根节点，q记录上一次出栈的元素
	stack<BiTNode*> Sq;
	if (!p) return;             //T为空树
	Sq.push(p);             //根节点入栈
	while (!Sq.empty()) {
		if (p->rChild == q) {   //如果上一个出栈节点等于栈顶节点的右指针(图中对应5和7的情景)
			printf("%d", p->data);           //打印出栈
			q = Sq.top();
			Sq.pop();
			if (!Sq.empty())  p = Sq.top();
			continue;
		}
		while (p->LTag == LINK&&p->lChild != q) {    //如果有左孩子，则左孩子入队列，后面这个条件防止无限循环（如1和2的情况）
			p = p->lChild;
			Sq.push(p);
		}
		if (p->RTag == LINK) {   //如果有右孩子，右孩子入队列
			p = p->rChild;
			Sq.push(p);
		}
		else if (p->RTag == THREAD) {  //如果无右孩子，则出栈打印
			printf("%d", p->data);
			q = Sq.top();
			Sq.pop();
			p = p->rChild;
			if (p != T->lChild)         //判断结束的条件，如果p的右孩子所指向根节点，则不入栈，避免无线循环（如3和1的情况）
				Sq.push(p);
		}
	}
}

int main()
{
	BiTNode *T1, *T2, *T3;
	BiTNode *tree1, *tree2, *tree3;

	printf("输入根节点:");
	CreateBiTree(&T1);
	InOrderThreading(&tree1, &T1);
	printf("\n");
	printf("中序遍历结果为：");
	InOrderTraverse(tree1);
	printf("\n");

	printf("输入根节点:");
	CreateBiTree(&T2);
	PreOrderThreading(&tree2, &T2);
	printf("\n");
	printf("先序遍历结果为：");
	PreOrderTraverse(tree2);
	printf("\n");

	printf("输入根节点:");
	CreateBiTree(&T3);
	PostOrderThreading(&tree3, &T3);
	printf("\n");
	printf("后序遍历结果为：");
	PostOrderTraverse(tree3);
	printf("\n");

	return 0;
}
//测试数据 p125页图6.4  1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1
