*file:biTree.c* /
#include <stdlib.h>
#include <iostream>
#include "biTree.h"
using namespace std;
#define N  10


//查找：返回第一个等于data域等于key的节点，不存在返回NULL
BiTreeNode *search(BiTree *biTree, DataType key) {
	BiTreeNode *curNode = *biTree;
	while (curNode != NULL && curNode->data != key) {
		if (key < curNode->data) {
			curNode = curNode->left;
		}
		else {
			curNode = curNode->right;
		}
	}
	return curNode;
}
//返回二叉树的最小节点,空树返回NULL
BiTreeNode *minImum(BiTree *biTree) {
	BiTreeNode *curNode = *biTree;
	while (curNode != NULL && curNode->left != NULL) {
		curNode = curNode->left;
	}
	return curNode;
}
//返回二叉树的最大节点,空树返回NULL
BiTreeNode *maxImum(BiTree *biTree) {
	BiTreeNode *curNode = *biTree;
	while (curNode != NULL && curNode->right != NULL) {
		curNode = curNode->right;
	}
	return curNode;
}

//返回节点x的后继节点,不存在后继（节点x为最大节点）返回NULL
BiTreeNode *successor(BiTreeNode *x) {
	if (x == NULL) return NULL;
	//存在右子树，则后继节点为其右子树中最小的节点
	if (x != NULL && x->right != NULL) {
		return minImum(&(x->right));
	}
	while (x->parent != NULL && x->parent->right == x) {
		x = x->parent;
	}
	return x->parent; //错误版本为 x， 此处应该返回父结点
}
//返回节点x的前驱节点，不存在前驱（节点x为最小节点）返回NULL
BiTreeNode *predecessor(BiTreeNode *x) {
	if (x == NULL) return NULL;
	//存在左子树，则后继节点为其左子树中最大的节点
	if (x != NULL && x->left != NULL) {
		return maxImum(&(x->left));
	}
	while (x->parent != NULL && x->parent->left == x) {
		x = x->parent;
	}
	return x->parent; //错误版本为 x， 此处应该返回父结点

}

void insertNode(BiTree *biTree, DataType data) {
	//创建节点
	BiTreeNode *targetNode;

	targetNode = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	//没有足够内存
	if (targetNode == NULL) return;
	targetNode->data = data;
	targetNode->parent = NULL;
	targetNode->left = NULL;
	targetNode->right = NULL;

	BiTreeNode *p, *y;
	p = *biTree;
	y = NULL;
	while (p != NULL) {
		y = p;
		if (targetNode->data < p->data) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	//空树，将新节点置为树根
	if (y == NULL) {
		*biTree = targetNode;
	}
	else {
		if (targetNode->data < y->data) {
			y->left = targetNode;
		}
		else {
			y->right = targetNode;
		}
	}
	targetNode->parent = y;
}
//删除一个值为data的节点
void deleteNode(BiTree *biTree, DataType data) {
	//查找待删除的节点
	BiTreeNode *targetNode, *x, *y;

	targetNode = search(biTree, data);
	if (targetNode == NULL) return;
	//找出真正的删除节点，如果目标节点最多只有一个子树，则其为真正删除的节点
	//否则其后继节点（最多只有一个子树，想想为什么）为真正删除的节点，然后将后继节点的值赋给目标节点
	if (targetNode->left == NULL || targetNode->right == NULL) {
		y = targetNode;
	}
	else {
		y = successor(targetNode);
	}

	if (y->left != NULL) {
		x = y->left;
	}
	else {
		x = y->right;
	}

	if (x != NULL) {
		x->parent = y->parent;
	}

	//如果y是根节点, 则根节点变为x
	if (y->parent == NULL) {
		*biTree = x;
	}
	else {
		if (y->parent->right == y) {
			y->parent->right = x;
		}
		else {
			y->parent->left = x;
		}
	}

	if (y != targetNode) {
		targetNode->data = y->data;
	}
	//释放y占有的空间
	free(y);
}
//中序遍历二叉树
void inorderTraversal(BiTree *biTree, void(*visitor)(BiTreeNode *node)) {
	BiTreeNode *curNode;

	curNode = *biTree;
	if (curNode != NULL) {
		//遍历左子树
		inorderTraversal(&(curNode->left), visitor);
		//访问节点
		visitor(curNode);
		//遍历右子树
		inorderTraversal(&(curNode->right), visitor);
	}
}

void printNode(BiTreeNode *node);

int main(int argc, char *argv[]) {
	BiTreeNode *root;
	int i;

	root = NULL;
	int data[N] = { 10, 23, 11, 98, 111, 87, 34, 11, 33, 8 };
	for (i = 0; i < N; i++) {
		insertNode(&root, data[i]);
	}
	printf("before delete:\n");
	inorderTraversal(&root, printNode);
	printf("\n");
	deleteNode(&root, 11);
	deleteNode(&root, 8);
	printf("after delete:\n");
	inorderTraversal(&root, printNode);
	printf("\n");

	//BiTreeNode *j = search(&root, 11);
	//cout << &(*j)<< endl;

	system("pause");
	return 0;
	//exit(0);
}

void printNode(BiTreeNode *node) {
	printf("%d\t", node->data);
}














//#include<iostream>
//#include<math.h>
//#include<algorithm>
//#include<string>
//
//using namespace std;
//
//typedef int status;
//typedef int elemtype;
//
//typedef struct BiTNode
//{
//	int  data;
//	struct BiTNode *lchild, *rchild;
//}BiTNode,*Bitree;
//
////递归查找二叉排序树T是否存在关键字key
////指针f指向T的双亲，初始值为NULL
////若查找成功，指针p指向该元素节点，返回true
////否则指针指向查找路径上访问的最后一个节点，并返回false
//status searchBST(Bitree T, int key, Bitree f, Bitree *P)
//{
//	if (!T)//查找失败
//	{
//		*p = f;
//		return false;
//	}
//	else if (key == T->data)//查找成功
//	{
//		*p = T;
//		return true;
//	}
//	else if (key < T->data)
//	{
//		return searchBST(T->lchild, key, T, p);//在左子树上继续查找
//	}
//	else
//	{
//		return searchBST(T->rchild, key, T, p);//在右子树上继续查找
//	}
//}
//
////当二叉排序树T不存在关键字key，则返回true，否则返回false
//status InsertBST(Bitree *T, int key)
//{
//	Bitree p, s;
//	if (!searchBST(*T, key, NULL, &p))
//	{
//		s = (Bitree)malloc(sizeof(BiTNode));
//		s->data = key;
//		s->lchild = s->rchild = NULL;
//		if (!p)
//		{
//			*T = s;//插入节点为新的节点
//		}
//		else if (key < p->data)
//		{
//			p->lchild = s;
//		}
//		else
//		{
//			p->rchild = s;
//		}
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
////删除
//status DeleteBST(Bitree *T, int key)
//{
//	if (!*T)//查找失败
//	{
//		return false;
//	}
//	else
//	{
//		if (key == (*T)->data)
//		{
//			return Delate(T);
//		}
//		if (key < (*T)->data)
//		{
//			return DeleteBST(&(*T)->lchild, key);
//		}
//		if (key > (*T)->data)
//		{
//			return DeleteBST(&(*T)->rchild, key);
//		}
//	}
//}
//
//status Delete(Bitree *p)
//{
//	Bitree q, s;
//	if ((*p)->rchild == NULL)
//	{
//		q = (*p);
//		*p = (*p)->lchild;
//		free(q);
//	}
//	else if ((*p)->lchild == NULL)
//	{
//		q = (*p);
//		*p = (*p)->rchild;
//		free(q);
//	}
//	else
//	{
//		q = *p;
//		s = (*p)->lchild;
//		while (s->rchild)
//		{
//			q = s;
//			s = s->rchild;
//		}
//		(*p)->data = s->data;
//
//		if (q != *p)
//		{
//			q->rchild = s->lchild;
//		}
//		else
//		{
//			q->lchild = s->lchild;
//		}
//
//		free(s);
//	}
//	return true;
//}

