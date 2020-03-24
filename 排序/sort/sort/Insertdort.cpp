//#include<iostream>
//#include<math.h>
//#include<algorithm>
//using namespace std;
//
//void Insertesort(int k[], int n)
//{
//	int i, j, temp;
//	for (i = 1; i < n ; i++)//插入排序要从i=1开始，
//	{
//		if (k[i] < k[i - 1])//如果出现后面的数比前面的小
//		{
//			temp = k[i];
//
//			for (j = i - 1; k[j] > temp; j--)//则将这个数从后往前依次比较
//			{
//				k[j + 1] = k[j];//如果前面的数更大，就把大的数向后移动
//			}
//
//			k[j + 1] = temp;//最后将最小值赋值条件结束的位置
//		}
//	}
//}
//
//int main()
//{
//	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
//
//	Insertesort(a, 10);
//
//	cout << "输出结果是：";
//	for (i = 0; i < 10; i++) 
//	{
//		cout << a[i];
//	}
//	system("pause");
//	return 0;
//}