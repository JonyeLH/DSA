/*************************************************************************
二分查找也称折半查找，其优点是速度快，缺点是要求数据必须是有序列序列。
用给定值k先与中间结点的关键字比较，中间结点把线形表分成两个子表，若相等则查找成功；
若不相等，再根据k与该中间结点关键字的比较结果确定下一步查找哪个子表，这样递归进行，直到查找到或查找结束发现表中没有这样的结点。
时间复杂度为O(log2n)
二分查找适用于静态查找，不适用于频繁插入和删除操作的数据集
数据集使用数组存储，不能使用链表
************************************************************************/

#include<stdio.h>
#include<iostream>
#include<time.h>
//循环形式的二分查找
int binarySearchByLoop(int a[], int n, int key)
{
	int low = 0;
	int high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (a[mid] == key)
		{
			return mid;
		}
		else if (a[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

//递归形式的二分查找
int binarySearch(int a[], int left, int right, int key)
{
	if (left > right)
		return -1;

	int mid = (left + right) / 2;
	if (a[mid] > key)
	{
		return binarySearch(a, left, mid - 1, key);
	}
	else if (a[mid] < key)
	{
		return binarySearch(a, mid + 1, right, key);
	}
	else
	{
		return mid;
	}
}

int main()
{
	clock_t start, stop;
	double duration;
	start = clock();

	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int j = binarySearchByLoop(a, 10, 6);
	printf("%d\n", j);

	int i = binarySearch(a, 0, 9, 9);
	printf("%d\n", i);

	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK;
	printf("该程序运行的时间是：%f\n", duration);

	system("pause");
	return 0;
}
