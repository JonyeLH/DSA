//#include<iostream>
//#include<math.h>
//#include<algorithm>
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
////�Ż������ٲ���Ҫ�Ľ�������
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
//		k[low] = k[high];//��������㣬��ֱ�ӻ�
//
//		while (low < high && k[low] <= point)//�Ƚ�k[low] �Ƿ�С�� point
//		{
//			low++;
//		}
//		k[high] = k[low];//��������㣬��ֱ�ӻ�
//	}
//
//	k[low] = point;
//	return low;//�����м�ĵ�
//}
//void Qsort(int k[], int low, int high)
//{
//	int point;
//
//	if (low < high)
//	{
//		point = partition(k,low,high);//���صõ��м����Ϊpoint
//		Qsort(k, low, point - 1);//Ȼ���point����߽��еݹ����
//		Qsort(k, point + 1, high);//Ȼ���point���ұ߽��еݹ����
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