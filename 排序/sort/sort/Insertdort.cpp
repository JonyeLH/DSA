//#include<iostream>
//#include<math.h>
//#include<algorithm>
//using namespace std;
//
//void Insertesort(int k[], int n)
//{
//	int i, j, temp;
//	for (i = 1; i < n ; i++)//��������Ҫ��i=1��ʼ��
//	{
//		if (k[i] < k[i - 1])//������ֺ��������ǰ���С
//		{
//			temp = k[i];
//
//			for (j = i - 1; k[j] > temp; j--)//��������Ӻ���ǰ���αȽ�
//			{
//				k[j + 1] = k[j];//���ǰ��������󣬾ͰѴ��������ƶ�
//			}
//
//			k[j + 1] = temp;//�����Сֵ��ֵ����������λ��
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
//	cout << "�������ǣ�";
//	for (i = 0; i < 10; i++) 
//	{
//		cout << a[i];
//	}
//	system("pause");
//	return 0;
//}