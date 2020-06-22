
//顺序查找
//基本思想：顺序查找也称为线形查找，属于无序查找算法。
//从数据结构线形表的一端开始，顺序扫描，依次将扫描到的结点关键字与给定值k相比较，
//若相等则表示查找成功；若扫描结束仍没有找到关键字等于k的结点，表示查找失败。
//顺序查找的时间复杂度为O(n)

#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<time.h>

using namespace std;
//简单的查找数组a中key的值，长度为n
int sq_search(int *a, int n, int key)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return 0;
}

//这个方法的复杂度是O(2n)，下面的方法的复杂度是O(n)，但是同样存在着一个问题，就是它对于里面具有多个相同的数的情况是没有考虑在内的
int sq_searchForBetter(int *a, int n, int key)
{
	int i = n;
	a[0] = key;
	while (a[i] != key)
	{
		i--;
	}
	return i;
}

int main()
{
	clock_t start, stop;
	double duration;
	start = clock();

	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i = sq_search(a, 10, 8);
	printf("%d\n", i);

	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK;
	printf("该程序运行的时间是：%f\n", duration);

	system("pause");
	return 0;
}