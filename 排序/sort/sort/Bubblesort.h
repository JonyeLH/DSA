#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

////不符合定义的冒泡排序
//void Bubblesort(int k[], int n)
//{
//	int i, j, temp,count1=0,count2=0;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			count1++;
//			if (k[i] > k[j])//第一个for循环的数与第二个for循环数比较大小，与冒泡排序定义不符。冒泡是要求两两比较
//			{
//				count2++;
//				temp = k[j];
//				k[j] = k[i];
//				k[i] = temp;
//			}
//		}
//	}
//	cout << "共执行了" << count1<< "次比较和" << count2 << "次移动" << endl;
//}

////正确的冒泡排序算法
//void Bubblesort(int k[], int n)
//{
//	int i, j, temp, count1 = 0, count2 = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = n-1; j >i; j--)//从后向前
//		{
//			count1++;
//			if (k[j-1] > k[j])//这里则是体现了两两比较
//			{
//				count2++;
//				temp = k[j-1];
//				k[j-1] = k[j];
//				k[j] = temp;
//			}
//		}
//	}
//	cout << "共执行了" << count1 << "次比较和" << count2 << "次移动" << endl;
//}

//冒泡排序的改进,对于局部无序，大致有序，减少不必要的移动操作
void Bubblesort(int k[], int n)
{
	int i, j, temp, flag=1, count1=0, count2=0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			count1++;
			flag = 0;
			if (k[j - 1] > k[j])
			{
				count2++;
				temp = k[j - 1];
				k[j - 1] = k[j];
				k[j] = temp;
				flag = 1;
			}
		}
	}
	cout << "共执行了" << count1 << "次比较和" << count2 << "次移动" << endl;
}
//int main()
//{
//	int i, a[10] = { 1, 0, 2 ,3 ,4 ,5 ,6, 7 ,8 ,9 };
//
//	Bubblesort(a, 10);
//
//	cout << "输出结果是：";
//	for (i = 0; i < 10; i++) 
//	{
//		cout << a[i];
//	}
//	system("pause");
//	return 0;
//}