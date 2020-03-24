//#include<iostream>
//#include<math.h>
//#include<algorithm>
//
//#define MAXSIZE 10
//using namespace std;
//
////归并排序的递归实现
//void Merging(int *list1, int list1_size, int *list2, int list2_size)
//{
//	int i, j, k, m;//参数i和j分别用于list1和list2子数组的遍历，k用于临时数组的存储，m用于最后合并数组的存储
//	i = j = k = 0;
//	int temp[MAXSIZE];
//
//	while (i < list1_size && j < list2_size)//在范围内
//	{
//		if (list1[i] < list2[j])//若list1的数小于list2的数
//		{
//			temp[k++] = list1[i++];//将list1的数存放在临时数组中
//		}
//		else//反之亦然
//		{
//			temp[k++] = list2[j++];
//		}
//	}
//
//	while (i < list1_size)//比较完之后若list1还有数存在，且一定是较大数
//	{
//		temp[k++] = list1[i++];
//	}
//	while (j < list2_size)//同理，比较完之后若list2还有数存在，且一定是较大数
//	{
//		temp[k++] = list2[j++];
//	}
//
//	for (m = 0; m < (list1_size + list2_size); m++)//最后完成将所有临时数组的数据存放在list1中
//	{
//		list1[m] = temp[m];
//	}
//}
//
//void Mergesort(int k[], int n)
//{
//	if (n > 1)
//	{
//		//将数组分为两部分
//		int *list1 = k;
//		int list1_size = n / 2;
//		int *list2 = k + n / 2;
//		int list2_size = n - list1_size;
//	
//		//递归划分数组成两个子数组
//		Mergesort(list1, list1_size);
//		Mergesort(list2, list2_size);
//
//		//合并子数组
//		Merging(list1, list1_size, list2, list2_size);
//	}
//}
//
//////归并排序的迭代实现   执行有问题
////void Mergesort(int k[], int n)
////{
////	int i, left_min, left_max, right_min, right_max;
////	int *temp = (int *)malloc(n * sizeof(int));
////
////	for (i = 1; i < n; i *= 2)
////	{
////		for (left_min = 0; left_min < n - i; left_min = right_max)
////		{
////			right_min = left_max = left_min + i;
////			right_max = left_max + i;
////
////			if (right_max > n)
////			{
////				right_max = n;
////			}
////
////			int next = 0;
////
////			while (left_min < left_max && right_min < right_max)
////			{
////				if (k[left_min] < k[right_min])
////				{
////					temp[next++] = k[left_min++];
////				}
////				else
////				{
////					temp[next++] = k[right_min++];
////				}
////			}
////			while (left_min < left_max)
////			{
//// 				k[--right_min] = k[--left_min];
////			}
////			while (next > 0)
////			{
////				k[--right_min] = temp[--next];
////			}
////		}
////	}
////}
//
//int main()
//{
//	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
//	
//	Mergesort(a, 10);
//	
//	cout << "输出结果是：";
//	for (i = 0; i < 10; i++)
//	{
//		cout << a[i];
//	}
//
//	system("pause");
//	return 0;
//}