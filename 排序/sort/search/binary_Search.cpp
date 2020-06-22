/*************************************************************************
���ֲ���Ҳ���۰���ң����ŵ����ٶȿ죬ȱ����Ҫ�����ݱ��������������С�
�ø���ֵk�����м���Ĺؼ��ֱȽϣ��м�������α�ֳ������ӱ����������ҳɹ���
������ȣ��ٸ���k����м���ؼ��ֵıȽϽ��ȷ����һ�������ĸ��ӱ������ݹ���У�ֱ�����ҵ�����ҽ������ֱ���û�������Ľ�㡣
ʱ�临�Ӷ�ΪO(log2n)
���ֲ��������ھ�̬���ң���������Ƶ�������ɾ�����������ݼ�
���ݼ�ʹ������洢������ʹ������
************************************************************************/

#include<stdio.h>
#include<iostream>
#include<time.h>
//ѭ����ʽ�Ķ��ֲ���
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

//�ݹ���ʽ�Ķ��ֲ���
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
	printf("�ó������е�ʱ���ǣ�%f\n", duration);

	system("pause");
	return 0;
}
