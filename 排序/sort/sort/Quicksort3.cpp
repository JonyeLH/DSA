//#include<iostream>
//#include<math.h>
//#include<algorithm>
//#define MAX_LENGTH_INSERT_SORT 7	//�趨���ٽ�ֵ������������������ֵ����ʹ�ÿ������򣬷���ʹ�ò�������
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
//		while (low < high && k[high] >= point)//�Ƚ�k[high] �Ƿ���� point
//		{
//			high--;
//		}
//		swap(k, low, high);//����whileѭ�������ʾ�������������������Ҫ����λ��
//
//		while (low < high && k[low] <= point)//�Ƚ�k[low] �Ƿ�С�� point
//		{
//			low++;
//		}
//		swap(k, low, high);//����whileѭ�������ʾ�������������������Ҫ����λ��
//	}
//	return low;//�����м�ĵ�
//}
//
//void Qsort(int k[], int low, int high)
//{
//	int point;
//
//	if ( (high- low)> MAX_LENGTH_INSERT_SORT)//�������������7����ʹ�ÿ�������
//	{
//		point = partition(k,low,high);//���صõ��м����Ϊpoint
//		Qsort(k, low, point - 1);//Ȼ���point����߽��еݹ����
//		Qsort(k, point + 1, high);//Ȼ���point���ұ߽��еݹ����
//	}
//	else//����ʹ�ò�������
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
//	cout << "�������ǣ�";
//	for (i = 0; i < 10; i++)
//	{
//		cout << a[i];
//	}
//
//	system("pause");
//	return 0;
//}