#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

////�����϶����ð������
//void Bubblesort(int k[], int n)
//{
//	int i, j, temp,count1=0,count2=0;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			count1++;
//			if (k[i] > k[j])//��һ��forѭ��������ڶ���forѭ�����Ƚϴ�С����ð�������岻����ð����Ҫ�������Ƚ�
//			{
//				count2++;
//				temp = k[j];
//				k[j] = k[i];
//				k[i] = temp;
//			}
//		}
//	}
//	cout << "��ִ����" << count1<< "�αȽϺ�" << count2 << "���ƶ�" << endl;
//}

////��ȷ��ð�������㷨
//void Bubblesort(int k[], int n)
//{
//	int i, j, temp, count1 = 0, count2 = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = n-1; j >i; j--)//�Ӻ���ǰ
//		{
//			count1++;
//			if (k[j-1] > k[j])//�������������������Ƚ�
//			{
//				count2++;
//				temp = k[j-1];
//				k[j-1] = k[j];
//				k[j] = temp;
//			}
//		}
//	}
//	cout << "��ִ����" << count1 << "�αȽϺ�" << count2 << "���ƶ�" << endl;
//}

//ð������ĸĽ�,���ھֲ����򣬴������򣬼��ٲ���Ҫ���ƶ�����
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
	cout << "��ִ����" << count1 << "�αȽϺ�" << count2 << "���ƶ�" << endl;
}
//int main()
//{
//	int i, a[10] = { 1, 0, 2 ,3 ,4 ,5 ,6, 7 ,8 ,9 };
//
//	Bubblesort(a, 10);
//
//	cout << "�������ǣ�";
//	for (i = 0; i < 10; i++) 
//	{
//		cout << a[i];
//	}
//	system("pause");
//	return 0;
//}