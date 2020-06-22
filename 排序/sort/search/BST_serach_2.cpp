/*!
* @file     二叉排序树查找算法.cpp
* @brief:
1、二叉排序树的创建
2、二叉排序树的插入
3、二叉排序树的查找
4、二叉排序树的删除（递归一个、删除结点一个 ）del两个函数；
*/

#include<iostream>

using namespace std;

typedef struct BitNode
{
	int data;//数据域
	struct BitNode *lchild, *rchild;//指针域
}*PBSTREE;
PBSTREE creat_BST(int *, int n);//创建二叉排序树
int insert_BST(PBSTREE &PT, int key);//插入操作
bool search_BST(PBSTREE, int key);//查找key值
PBSTREE search_BST2(PBSTREE &PT, int key);//非递归查找key（还在写）
bool delete_BST(PBSTREE &PT, int val);//在二叉排序树中删除val；
bool Delete(PBSTREE &PT);//在二叉排序树中删除PT结点；
void In_traverse(PBSTREE PT);//中序遍历；
int main()
{
	int n;
	cout << "请输入数组的大小n:" << endl;
	cin >> n;
	int *a = new int[n];
	cout << "请输入数组的内容：" << endl;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << "您输入的数组为：" << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	PBSTREE PT = (PBSTREE)malloc(sizeof(BitNode));

	PT = creat_BST(a, n);
	cout << "构造的二叉排序树如下：" << endl;
	In_traverse(PT);
	int key;
	cout << "请输入key：" << endl;
	cin >> key;
	if (search_BST(PT, key))
	{
		cout << "成功找到key" << key << endl;
	}
	else
	{
		cout << key << "不存在于数组中" << endl;
	}
	int val;//要删除的数据结点
	cout << "请输入要删除的数据：" << endl;
	cin >> val;

	if (delete_BST(PT, val))
	{
		cout << val << "在二叉排序树上删除成功" << endl;
		In_traverse(PT);
	}
	else
	{
		cout << "删除失败" << endl;
	}

	//PBSTREE PS;//非递归查找；
	//PS = search_BST2(PT, key);
	//if ((PS->data==key))
	//	cout << "成功找到key" << key << endl;
	//else if (PS->data == key)
	//{
	//	cout << key << "不存在于数组中" << endl;
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
int insert_BST(PBSTREE &PT, int key)//这里用引用，不然传输的PT会变；
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
PBSTREE creat_BST(int *a, int n)//根据数组创建二叉排序树
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
bool search_BST(PBSTREE PT, int key)//key值得查找
{
	if (NULL == PT)//当pt为空时候，查找失败；
		return false;

	else if (key == PT->data)//PT的数据与key值相等  查找成功；
		return true;
	else if (key < PT->data)//key小于pt->data；递归到左孩子继续查找；
		search_BST(PT->lchild, key);
	else if (key>PT->data)//key大于pt->data；递归到右孩子继续查找；
		search_BST(PT->rchild, key);
	else   //找不到key值  则查找失败；
		return false;
}
//PBSTREE search_BST2(PBSTREE &PT, int key)//非递归查找暂时有错误
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
	if (NULL == PT->lchild)//左子树为空，只需要重接它的右子树
	{
		Pq = PT;
		PT = PT->rchild;
		free(Pq);
	}
	else if (PT->rchild == NULL)//右子树为空，只需要重接它的左子树
	{
		Pq = PT;
		PT = PT->lchild;
		free(Pq);
	}
	else//左右子树都不为空
	{
		Pq = PT;
		Ps = PT->lchild;
		while (Ps->rchild)//左子树的向右到尽头，找PT的直接前驱节点
		{
			Pq = Ps;
			Ps = Ps->rchild;
		}
		PT->data = Ps->data;

		if (Pq != PT)
			Pq->rchild = Ps->lchild;//重接pq的右子树
		else
			Pq->lchild = Ps->lchild;//重接pq的左子树
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