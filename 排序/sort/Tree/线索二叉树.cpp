//�������������ڶ�����ͨ�������ṹ�У�Ҷ�ӽڵ��ָ�����ǿ�ȱ�ģ����洢�κζ�������һ����Դ���˷�
//���Բ��ò�ͬ�Ķ�����������ʽ���������Ҷ�ӽڵ�Ŀ�ȱָ�롣
//���ȡ���������ʽ�������Դ����������Դ������

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
#define LINK 0 //ָ��
#define THREAD 1  //����
using namespace std;
//���������������ݽṹ
typedef  struct BTNode {
	int data;
	struct BTNode *lChild;
	struct BTNode *rChild;
	int LTag, RTag;
}BiTNode;
//���򴴽����������ݹ�ʵ��
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
		printf("����%d���ӽ��", ch);
		CreateBiTree(&((*T)->lChild));
		printf("����%d���ӽ��", ch);
		CreateBiTree(&((*T)->rChild));
	}
	return;
}
//���������������������
void InTreading(BiTNode **p);
BiTNode *pre;                        //����ָ��P��ǰһ��ָ�룬ֻ������ȫ�ֱ���
void InOrderThreading(BiTNode **Thrt, BiTNode **T) {
	//�������������T,��������������Thrtָ��ͷ���
	*Thrt = (BiTNode*)malloc(sizeof(BiTNode));
	(*Thrt)->LTag = LINK;               //����ͷ���,LTagΪָ�룬ָ��ոմ����õĶ�����
	(*Thrt)->RTag = THREAD;              //RTagΪ����
	(*Thrt)->rChild = (*Thrt);             //�Һ��ӻ�ָ
	if (!T)
		(*Thrt)->lChild = (*Thrt);       //��������Ϊ�գ���ָ���ָ
	else {
		(*Thrt)->lChild = (*T);
		pre = (*Thrt);
		InTreading(&(*T));              //���������������������
		pre->rChild = (*Thrt);          //���һ������������������һ�����ӵ���������ָ�������������
		pre->RTag = THREAD;
		(*Thrt)->rChild = pre;        //���˾��ÿ��п���
	}
}
void InTreading(BiTNode **p) {
	if (*p) {
		InTreading(&(*p)->lChild);  //������������
		if (!(*p)->lChild) {             //ǰ������
			(*p)->LTag = THREAD;
			(*p)->lChild = pre;
		}
		if (!pre->rChild) {            //�������
			pre->RTag = THREAD;
			pre->rChild = (*p);
		}
		pre = (*p);                      //����preָ��P��ǰ��
		InTreading(&(*p)->rChild);  //������������
									/*ע����������Ĵ������д����ܵ�����
									��Ϊ��������ǰ������һ��pre,��������������֮ǰ�ð�pre�ó�p*/
	}
}
//�����������ı���������������ǵݹ�
void InOrderTraverse(BiTNode *T) {
	BiTNode *p = T->lChild;             //pָ����ڵ�
	while (p != T) {  //�������������ʱ��p==T
		while (p->LTag == LINK)
			p = p->lChild;          //�����ߵ���ͷ
		printf("%d", p->data);     //������������Ϊ�յĽ��
		while (p->RTag == THREAD&&p->rChild != T) {
			p = p->rChild;
			printf("%d", p->data);       //���ʺ�̽��,��˫��
		}
		p = p->rChild;
	}
}

//���������������������
void PreTreading(BiTNode **p);
BiTNode *pre1;                        //����ָ��P��ǰһ��ָ�룬ֻ������ȫ�ֱ���
void PreOrderThreading(BiTNode **Thrt, BiTNode **T) {
	//�������������T,��������������Thrtָ��ͷ���
	*Thrt = (BiTNode*)malloc(sizeof(BiTNode));
	(*Thrt)->LTag = LINK;               //����ͷ���,LTagΪָ�룬ָ��ոմ����õĶ�����
	(*Thrt)->RTag = THREAD;              //RTagΪ����
	(*Thrt)->rChild = (*Thrt);             //�Һ��ӻ�ָ
	if (!T)
		(*Thrt)->lChild = (*Thrt);       //��������Ϊ�գ���ָ���ָ
	else {
		(*Thrt)->lChild = (*T);
		pre1 = (*Thrt);
		PreTreading(&(*T));              //���������������������
		pre1->rChild = (*Thrt);          //���һ������������������һ�����ӵ���������ָ�������������
		pre1->RTag = THREAD;
		(*Thrt)->rChild = pre1;        //���˾��ÿ��п���
	}
}
void PreTreading(BiTNode **p) {
	if (*p) {
		if (!(*p)->lChild) {             //ǰ������
			(*p)->LTag = THREAD;
			(*p)->lChild = pre1;
		}
		if (!pre1->rChild) {            //�������
			pre1->RTag = THREAD;
			pre1->rChild = (*p);
		}
		pre1 = (*p);                      //����preָ��P��ǰ��
		if ((*p)->LTag != THREAD)
			PreTreading(&(*p)->lChild);  //������������
		if ((*p)->RTag != THREAD)
			PreTreading(&(*p)->rChild);  //������������
	}
}
//�����������ı���������������ǵݹ�
void PreOrderTraverse(BiTNode *T) {
	BiTNode *p = T->lChild;             //pָ����ڵ�
	while (p != T) {  //�������������ʱ��p==T
		printf("%d", p->data);
		if (p->LTag == LINK) {
			p = p->lChild;
		}
		else if (p->LTag == THREAD) {
			p = p->rChild;
		}
	}
}

//���������������������
void PostTreading(BiTNode **p);
BiTNode *pre2;                        //����ָ��P��ǰһ��ָ�룬ֻ������ȫ�ֱ���
void PostOrderThreading(BiTNode **Thrt, BiTNode **T) {
	//�������������T,��������������Thrtָ��ͷ���
	*Thrt = (BiTNode*)malloc(sizeof(BiTNode));
	(*Thrt)->LTag = LINK;               //����ͷ���,LTagΪָ�룬ָ��ոմ����õĶ�����
	(*Thrt)->RTag = THREAD;              //RTagΪ����
	(*Thrt)->rChild = (*Thrt);             //�Һ��ӻ�ָ
	if (!T)
		(*Thrt)->lChild = (*Thrt);       //��������Ϊ�գ���ָ���ָ
	else {
		(*Thrt)->lChild = (*T);
		pre2 = (*Thrt);
		PostTreading(&(*T));              //���������������������
										  //������Ҫ�����һ���ڵ�������
										  //        pre2->rChild=(*Thrt);          //���һ������������������һ�����ӵ���������ָ�������������
										  //        pre2->RTag=THREAD;
										  //        (*Thrt)->rChild=pre2;        //���˾��ÿ��п���
	}
}
void PostTreading(BiTNode **p) {
	if (*p) {
		PostTreading(&(*p)->lChild);  //������������
		PostTreading(&(*p)->rChild);  //������������
		if (!(*p)->lChild) {             //ǰ������
			(*p)->LTag = THREAD;
			(*p)->lChild = pre2;
		}
		if (!pre2->rChild) {            //�������
			pre2->RTag = THREAD;
			pre2->rChild = (*p);
		}
		pre2 = (*p);                      //����preָ��P��ǰ��
	}
}
//�����������ı���������������ǵݹ飬�õ�ջ�ķ������л��ݣ����˸о��Ƚϸ���
void PostOrderTraverse(BiTNode *T) {
	BiTNode *p = T->lChild, *q;             //pָ����ڵ㣬q��¼��һ�γ�ջ��Ԫ��
	stack<BiTNode*> Sq;
	if (!p) return;             //TΪ����
	Sq.push(p);             //���ڵ���ջ
	while (!Sq.empty()) {
		if (p->rChild == q) {   //�����һ����ջ�ڵ����ջ���ڵ����ָ��(ͼ�ж�Ӧ5��7���龰)
			printf("%d", p->data);           //��ӡ��ջ
			q = Sq.top();
			Sq.pop();
			if (!Sq.empty())  p = Sq.top();
			continue;
		}
		while (p->LTag == LINK&&p->lChild != q) {    //��������ӣ�����������У��������������ֹ����ѭ������1��2�������
			p = p->lChild;
			Sq.push(p);
		}
		if (p->RTag == LINK) {   //������Һ��ӣ��Һ��������
			p = p->rChild;
			Sq.push(p);
		}
		else if (p->RTag == THREAD) {  //������Һ��ӣ����ջ��ӡ
			printf("%d", p->data);
			q = Sq.top();
			Sq.pop();
			p = p->rChild;
			if (p != T->lChild)         //�жϽ��������������p���Һ�����ָ����ڵ㣬����ջ����������ѭ������3��1�������
				Sq.push(p);
		}
	}
}

int main()
{
	BiTNode *T1, *T2, *T3;
	BiTNode *tree1, *tree2, *tree3;

	printf("������ڵ�:");
	CreateBiTree(&T1);
	InOrderThreading(&tree1, &T1);
	printf("\n");
	printf("����������Ϊ��");
	InOrderTraverse(tree1);
	printf("\n");

	printf("������ڵ�:");
	CreateBiTree(&T2);
	PreOrderThreading(&tree2, &T2);
	printf("\n");
	printf("����������Ϊ��");
	PreOrderTraverse(tree2);
	printf("\n");

	printf("������ڵ�:");
	CreateBiTree(&T3);
	PostOrderThreading(&tree3, &T3);
	printf("\n");
	printf("����������Ϊ��");
	PostOrderTraverse(tree3);
	printf("\n");

	return 0;
}
//�������� p125ҳͼ6.4  1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1
