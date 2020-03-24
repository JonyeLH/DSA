//#include<iostream>
//#include<math.h>
//#include<algorithm>
//#define MAX_LENGTH_INSERT_SORT 7	//设定的临界值，如果数据量大于这个值，则使用快速排序，否则使用插入排序
//
//using namespace std;
//
//void swap(int k[], int low, int high)
//{
//	int temp;
//	temp = k[low];
//	k[low] = k[high];
//	k[high] = temp;
//}
//
//void Isort(int k[], int n)
//{
//	int i, j, temp;
//	for (i = 1; i < n; i++)
//	{
//		if(k[i] < k[i - 1])
//		{
//			temp = k[i];
//
//			for (j = i - 1; k[j] > temp; j--)
//			{
//				k[j+1] = k[j];
//			}
//			k[j + 1] = temp;
//		}
//	}
//}
//
//void Insertsort(int k[], int low, int high)
//{
//	Isort(k + low, high - low + 1);
//}
//
//int partition(int k[], int low, int high)
//{
//	int point;
//	point = k[low];
//	while (low < high)
//	{
//		while (low < high && k[high] >= point)//比较k[high] 是否大于 point
//		{
//			high--;
//		}
//		swap(k, low, high);//出了while循环，则表示不满足上面的条件，需要调换位置
//
//		while (low < high && k[low] <= point)//比较k[low] 是否小于 point
//		{
//			low++;
//		}
//		swap(k, low, high);//出了while循环，则表示不满足上面的条件，需要调换位置
//	}
//	return low;//返回中间的点
//}
//
//void Qsort(int k[], int low, int high)
//{
//	int point;
//
//	if ( (high- low)> MAX_LENGTH_INSERT_SORT)//如果数据量大于7，则使用快速排序
//	{
//		point = partition(k,low,high);//返回得到中间点作为point
//		Qsort(k, low, point - 1);//然后对point的左边进行递归调用
//		Qsort(k, point + 1, high);//然后对point的右边进行递归调用
//	}
//	else//否则使用插入排序
//	{
//		Insertsort(k, low, high);
//	}
//}
//
//void Quicksort(int k[], int n)
//{
//	Qsort(k, 0, n - 1);
//}
//
//int main()
//{
//	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
//
//	Quicksort(a, 10);
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