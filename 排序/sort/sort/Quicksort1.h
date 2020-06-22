#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

void swap(int k[], int low, int high)
{
	int temp;
	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

//�Ż�����ֹ���õĵ�һ��pointֵ����ȡ�м�ֵm��Ϊpoint
int partition(int k[], int low, int high)
{
	int point;

	int m = low + (high - low) / 2;
	if (k[low] > k[high])
	{
		swap(k, low, high);
	}
	if (k[m] > k[high])
	{
		swap(k, m, high);
	}
	if (k[m] > k[low])
	{
		swap(k, m, low);
	}

	point = k[low];
	while (low < high)
	{
		while (low < high && k[high] >= point)//�Ƚ�k[high] �Ƿ���� point
		{
			high--;
		}
		swap(k, low, high);//����whileѭ�������ʾ�������������������Ҫ����λ��

		while (low < high && k[low] <= point)//�Ƚ�k[low] �Ƿ�С�� point
		{
			low++;
		}
		swap(k, low, high);//����whileѭ�������ʾ�������������������Ҫ����λ��
	}
	return low;//�����м�ĵ�
}
void Qsort(int k[], int low, int high)
{
	int point;

	if (low < high)
	{
		point = partition(k, low, high);//���صõ��м����Ϊpoint
		Qsort(k, low, point - 1);//Ȼ���point����߽��еݹ����
		Qsort(k, point + 1, high);//Ȼ���point���ұ߽��еݹ����
	}
}

void Quicksort1(int k[], int n)
{
	Qsort(k, 0, n - 1);
}

//int main()
//{
//	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
//
//	Quicksort1(a, 10);
//
//	cout << "�������ǣ�";
//	for (i = 0; i < 10; i++)
//	{
//		cout << a[i];
//	}
//
//	system("pause");
//	return 0;
//}