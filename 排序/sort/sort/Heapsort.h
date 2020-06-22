#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

void swap(int k[], int i, int j)
{
	int temp;
	temp = k[i];
	k[i] = k[j];
	k[j] = temp;	
}

void HeapAdjust(int k[], int s, int n)//s设定为双亲节点
{
	int i,temp;
	temp = k[s];

	for (i = 2 * s; i <= n; i *= 2)
	{
		if (i<n && k[i] < k[i + 1])//左孩子大于右孩子
		{
			i++;//i指向最大孩子的下标
		}
		if (temp > k[i])//比较双亲与最大孩子
		{
			break;//是的话不用调整
		}

		//否则的话，就将最大的孩子赋给双亲节点，下标也互换
		k[s] = k[i];
		s = i;
	}
	//最后将双亲节点换到孩子的位置
	k[s] = temp;
}

void Heapsort(int k[], int n)
{
	int i;

	for (i = n / 2; i > 0; i--)//从下往上，从右往左排序的大顶堆，i初始应该设定为完全二叉树的最左下的双亲节点
	{
		HeapAdjust(k, i, n);
	}

	for (i = n; i > 1; i--)//从下往上调整
	{
		swap(k, 1, i);//将顶点最大的数与最后的元素互换
		HeapAdjust(k, 1, i-1);//再次调整堆的大小和位置
	}
}

//int main()
//{
//	int i, a[10] = { -1,5,2,6,0,3,9,1,7,4 };
//
//	Heapsort(a, 9);
//
//	cout << "输出结果是：";
//	for (i = 1; i < 10; i++)
//	{
//		cout << a[i];
//	}
//	system("pause");
//	return 0;
//}