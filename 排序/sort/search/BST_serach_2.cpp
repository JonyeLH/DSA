/*!
* @file     ���������������㷨.cpp
* @brief:
1�������������Ĵ���
2�������������Ĳ���
3�������������Ĳ���
4��������������ɾ�����ݹ�һ����ɾ�����һ�� ��del����������
*/

#include<iostream>

using namespace std;

typedef struct BitNode
{
	int data;//������
	struct BitNode *lchild, *rchild;//ָ����
}*PBSTREE;
PBSTREE creat_BST(int *, int n);//��������������
int insert_BST(PBSTREE &PT, int key);//�������
bool search_BST(PBSTREE, int key);//����keyֵ
PBSTREE search_BST2(PBSTREE &PT, int key);//�ǵݹ����key������д��
bool delete_BST(PBSTREE &PT, int val);//�ڶ�����������ɾ��val��
bool Delete(PBSTREE &PT);//�ڶ�����������ɾ��PT��㣻
void In_traverse(PBSTREE PT);//���������
int main()
{
	int n;
	cout << "����������Ĵ�Сn:" << endl;
	cin >> n;
	int *a = new int[n];
	cout << "��������������ݣ�" << endl;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << "�����������Ϊ��" << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	PBSTREE PT = (PBSTREE)malloc(sizeof(BitNode));

	PT = creat_BST(a, n);
	cout << "����Ķ������������£�" << endl;
	In_traverse(PT);
	int key;
	cout << "������key��" << endl;
	cin >> key;
	if (search_BST(PT, key))
	{
		cout << "�ɹ��ҵ�key" << key << endl;
	}
	else
	{
		cout << key << "��������������" << endl;
	}
	int val;//Ҫɾ�������ݽ��
	cout << "������Ҫɾ�������ݣ�" << endl;
	cin >> val;

	if (delete_BST(PT, val))
	{
		cout << val << "�ڶ�����������ɾ���ɹ�" << endl;
		In_traverse(PT);
	}
	else
	{
		cout << "ɾ��ʧ��" << endl;
	}

	//PBSTREE PS;//�ǵݹ���ң�
	//PS = search_BST2(PT, key);
	//if ((PS->data==key))
	//	cout << "�ɹ��ҵ�key" << key << endl;
	//else if (PS->data == key)
	//{
	//	cout << key << "��������������" << endl;
	//}

}
void In_traverse(PBSTREE PT)
{
	if (PT != NULL)
	{
		In_traverse(PT->lchild);
		cout << PT->data << endl;
		In_traverse(PT->rchild);
	}
}
int insert_BST(PBSTREE &PT, int key)//���������ã���Ȼ�����PT��䣻
{
	if (NULL == PT)
	{
		PT = (PBSTREE)malloc(sizeof(BitNode));
		PT->data = key;
		PT->lchild = PT->rchild = NULL;
		return 0;

	}
	else if (PT->data == key)
		return 0;
	else if (PT->data < key)
		return insert_BST(PT->rchild, key);
	else if (key < PT->data)
		return insert_BST(PT->lchild, key);

}
PBSTREE creat_BST(int *a, int n)//�������鴴������������
{
	PBSTREE PT = NULL;
	int i = 0;
	while (i<n)
	{
		insert_BST(PT, a[i]);
		++i;
	}
	return PT;

}
bool search_BST(PBSTREE PT, int key)//keyֵ�ò���
{
	if (NULL == PT)//��ptΪ��ʱ�򣬲���ʧ�ܣ�
		return false;

	else if (key == PT->data)//PT��������keyֵ���  ���ҳɹ���
		return true;
	else if (key < PT->data)//keyС��pt->data���ݹ鵽���Ӽ������ң�
		search_BST(PT->lchild, key);
	else if (key>PT->data)//key����pt->data���ݹ鵽�Һ��Ӽ������ң�
		search_BST(PT->rchild, key);
	else   //�Ҳ���keyֵ  �����ʧ�ܣ�
		return false;
}
//PBSTREE search_BST2(PBSTREE &PT, int key)//�ǵݹ������ʱ�д���
//{
//	while (PT!=NULL && PT->data!=key)
//	{
//		if (key < PT->data)
//			PT = PT->lchild;
//		if (key > PT->data)
//			PT = PT->rchild;
//
//	}
//	return PT;
//	
//
//}
bool Delete(PBSTREE &PT)
{
	PBSTREE Pq, Ps;
	if (NULL == PT->lchild)//������Ϊ�գ�ֻ��Ҫ�ؽ�����������
	{
		Pq = PT;
		PT = PT->rchild;
		free(Pq);
	}
	else if (PT->rchild == NULL)//������Ϊ�գ�ֻ��Ҫ�ؽ�����������
	{
		Pq = PT;
		PT = PT->lchild;
		free(Pq);
	}
	else//������������Ϊ��
	{
		Pq = PT;
		Ps = PT->lchild;
		while (Ps->rchild)//�����������ҵ���ͷ����PT��ֱ��ǰ���ڵ�
		{
			Pq = Ps;
			Ps = Ps->rchild;
		}
		PT->data = Ps->data;

		if (Pq != PT)
			Pq->rchild = Ps->lchild;//�ؽ�pq��������
		else
			Pq->lchild = Ps->lchild;//�ؽ�pq��������
		free(Ps);
	}
	return true;

}
bool delete_BST(PBSTREE &PT, int key)
{
	if (!PT)
		return false;
	else
	{
		if (key == PT->data)
			return Delete(PT);
		else if (key < PT->data)
			return delete_BST(PT->lchild, key);

		else if (key>PT->data)
			return delete_BST(PT->rchild, key);
	}
}