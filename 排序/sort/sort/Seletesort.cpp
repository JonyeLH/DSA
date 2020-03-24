//#include<iostream>
//#include<math.h>
//#include<algorithm>
//using namespace std;
//
//void Seletesort(int k[], int n)
//{
//	int i, j, temp, min, count1 = 0, count2 = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		min = i;//设定第一个数是最小值
//		for (j = i + 1; j < n; j++)
//		{
//			count1++;
//			if (k[j] < k[min])//通过后面的数与设定的最小值比较
//			{
//				min = j;//若是后面的数存在小于最小值，则将后面数的下标赋给min下标
//			}
//		}
//		if (min != i)//然后判断以替换的min（其实是j）是否与当前的i相等，做出是否交换位置，缺少可能会这个判断会增加移动次数
//		{
//			//把k[j]（k[min]）与原来设定的最小值k[i]换位置
//			count2++;
//			temp = k[min];
//			k[min] = k[i];
//			k[i] = temp;
//		}
//
//	}
//	cout << "共执行了" << count1 << "次比较和" << count2 << "次移动" << endl;
//}
//
//int main()
//{
//	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
//
//	Seletesort(a, 10);
//
//	cout << "输出结果是：";
//	for (i = 0; i < 10; i++) 
//	{
//		cout << a[i];
//	}
//	system("pause");
//	return 0;
//}