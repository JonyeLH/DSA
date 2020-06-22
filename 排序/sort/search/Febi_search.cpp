#include <stdio.h>
#include <iostream>
#define MAXSIZE 20
using namespace std;

void fibonacci(int *f)   //使用递推关系生成斐波那契数列
{
	int i;

	f[0] = 1;
	f[1] = 1;

	for (i = 2; i < MAXSIZE; ++i)
	{
		f[i] = f[i - 2] + f[i - 1];

	}
}//f[i]  1 1 2 3 5 8 13 21 34 55 89
 // i    0 1 2 3 4 5 6  7  8  9  10 

 // *a 是待查找数组的头指针，key 待查找的数字，n 是待查找数组中元素的个数
 //int a[] = { 1, 5, 15, 22, 25, 31, 39, 42, 47, 49, 59, 68, 88 };
 //若 key=39 n=13
int fibonacci_search(int *a, int key, int n)
{
	int low = 0;
	int high = n - 1;//high=13-1  下标从0开始
	int mid = 0;
	int k = 0;
	int F[MAXSIZE];
	int i;

	fibonacci(F);

	//计算n位于斐波那契数列的位置 
	while (n > F[k] - 1)
	{
		++k;
	}

	//如果数组的长度小于对应的斐波那契数列中元素的值，那么将他用最大值拓展
	// 补充的元素值为最后一个元素的值
	//将a的元素扩展到(某斐波那契数 - 1)，即F[k]-1 
	for (i = n; i < F[k] - 1; ++i)
	{
		a[i] = a[high];
	}

	while (low <= high)
	{     // low：起始位置 0
		  // 前半部分有f[k-1]个元素，由于下标从0开始
		  // 则-1 获取 黄金分割位置元素的下标

		mid = low + F[k - 1] - 1;//计算当前分割的下标 
		if (a[mid] > key)//a[5]=31
		{
			// 查找前半部分，高位指针移动
			high = mid - 1;
			// （全部元素） = （前半部分）+（后半部分）
			// f[k] = f[k-1] + f[k-2]
			// 因为前半部分有f[k-1]个元素，所以 k = k-1    
			k = k - 1;
		}
		else if (a[mid] < key)//a[5]=31<39
		{
			// 查找后半部分，高位指针移动
			low = mid + 1;
			// （全部元素） = （前半部分）+（后半部分）
			// f[k] = f[k-1] + f[k-2]
			// 因为后半部分有f[k-2]个元素，所以 k = k-2
			k = k - 2;
		}
		else
		{
			if (mid <= high)
			{
				//若相当则说明mid即为查找到的位置 
				return mid;
			}
			else
			{
				//若mid>n则说明是扩展的数值，返回n
				return high;
			}
		}
	}

	return -1;
}

int main()
{

	int a[MAXSIZE] = { 1, 5, 15, 22, 25, 31, 39, 42, 47, 49, 59, 68, 88 };
	int key;
	int pos;

	printf("请输入要查找的数字:");

	cin >> key;
	//scanf("%d", &key);

	pos = fibonacci_search(a, key, 13);

	if (pos != -1)
	{
		printf("\n查找成功，关键字 %d 所在的位置是: %d\n\n", key, pos);
	}
	else
	{
		cout << "未在数组中找到元素:" << key << endl;
	}

	system("pause");
	return 0;
}