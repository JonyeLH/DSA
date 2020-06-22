*file:biTree.c* /
#include <stdlib.h>
#include <iostream>
#include "biTree.h"
using namespace std;
#define N  10


//���ң����ص�һ������data�����key�Ľڵ㣬�����ڷ���NULL
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
//���ض���������С�ڵ�,��������NULL
BiTreeNode *minImum(BiTree *biTree) {
	BiTreeNode *curNode = *biTree;
	while (curNode != NULL && curNode->left != NULL) {
		curNode = curNode->left;
	}
	return curNode;
}
//���ض����������ڵ�,��������NULL
BiTreeNode *maxImum(BiTree *biTree) {
	BiTreeNode *curNode = *biTree;
	while (curNode != NULL && curNode->right != NULL) {
		curNode = curNode->right;
	}
	return curNode;
}

//���ؽڵ�x�ĺ�̽ڵ�,�����ں�̣��ڵ�xΪ���ڵ㣩����NULL
BiTreeNode *successor(BiTreeNode *x) {
	if (x == NULL) return NULL;
	//���������������̽ڵ�Ϊ������������С�Ľڵ�
	if (x != NULL && x->right != NULL) {
		return minImum(&(x->right));
	}
	while (x->parent != NULL && x->parent->right == x) {
		x = x->parent;
	}
	return x->parent; //����汾Ϊ x�� �˴�Ӧ�÷��ظ����
}
//���ؽڵ�x��ǰ���ڵ㣬������ǰ�����ڵ�xΪ��С�ڵ㣩����NULL
BiTreeNode *predecessor(BiTreeNode *x) {
	if (x == NULL) return NULL;
	//���������������̽ڵ�Ϊ�������������Ľڵ�
	if (x != NULL && x->left != NULL) {
		return maxImum(&(x->left));
	}
	while (x->parent != NULL && x->parent->left == x) {
		x = x->parent;
	}
	return x->parent; //����汾Ϊ x�� �˴�Ӧ�÷��ظ����

}

void insertNode(BiTree *biTree, DataType data) {
	//�����ڵ�
	BiTreeNode *targetNode;

	targetNode = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	//û���㹻�ڴ�
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
	//���������½ڵ���Ϊ����
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
//ɾ��һ��ֵΪdata�Ľڵ�
void deleteNode(BiTree *biTree, DataType data) {
	//���Ҵ�ɾ���Ľڵ�
	BiTreeNode *targetNode, *x, *y;

	targetNode = search(biTree, data);
	if (targetNode == NULL) return;
	//�ҳ�������ɾ���ڵ㣬���Ŀ��ڵ����ֻ��һ������������Ϊ����ɾ���Ľڵ�
	//�������̽ڵ㣨���ֻ��һ������������Ϊʲô��Ϊ����ɾ���Ľڵ㣬Ȼ�󽫺�̽ڵ��ֵ����Ŀ��ڵ�
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

	//���y�Ǹ��ڵ�, ����ڵ��Ϊx
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
	//�ͷ�yռ�еĿռ�
	free(y);
}
//�������������
void inorderTraversal(BiTree *biTree, void(*visitor)(BiTreeNode *node)) {
	BiTreeNode *curNode;

	curNode = *biTree;
	if (curNode != NULL) {
		//����������
		inorderTraversal(&(curNode->left), visitor);
		//���ʽڵ�
		visitor(curNode);
		//����������
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
////�ݹ���Ҷ���������T�Ƿ���ڹؼ���key
////ָ��fָ��T��˫�ף���ʼֵΪNULL
////�����ҳɹ���ָ��pָ���Ԫ�ؽڵ㣬����true
////����ָ��ָ�����·���Ϸ��ʵ����һ���ڵ㣬������false
//status searchBST(Bitree T, int key, Bitree f, Bitree *P)
//{
//	if (!T)//����ʧ��
//	{
//		*p = f;
//		return false;
//	}
//	else if (key == T->data)//���ҳɹ�
//	{
//		*p = T;
//		return true;
//	}
//	else if (key < T->data)
//	{
//		return searchBST(T->lchild, key, T, p);//���������ϼ�������
//	}
//	else
//	{
//		return searchBST(T->rchild, key, T, p);//���������ϼ�������
//	}
//}
//
////������������T�����ڹؼ���key���򷵻�true�����򷵻�false
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
//			*T = s;//����ڵ�Ϊ�µĽڵ�
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
////ɾ��
//status DeleteBST(Bitree *T, int key)
//{
//	if (!*T)//����ʧ��
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

