//希尔排序是在插入排序的基础上改进
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

//通过增大两两比较的间隙来实现
void Shellsort(int k[], int n)
{
	int i, j, temp;
	int gap = n;	

	do
	{
		gap = gap / 3 + 1;//自行设置比较间距的大小
		for (i = gap ; i < n; i++)
		{
			if (k[i] < k[i-gap])//扩大比较间隔i-gap
			{
				temp = k[i];

				for (j = i - gap ; k[j] > temp; j-=gap)
				{
					k[j + gap] = k[j];
				}
				k[j + gap] = temp;
			}
		}
	} while (gap > 1);//循环退出条件
}

//int main()
//{
//	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
//
//	Shellsort(a, 10);
//
//	cout << "输出结果是：";
//	for (i = 0; i < 10; i++) 
//	{
//		cout << a[i];
//	}
//	system("pause");
//	return 0;
//}