//ϣ���������ڲ�������Ļ����ϸĽ�
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

//ͨ�����������Ƚϵļ�϶��ʵ��
void Shellsort(int k[], int n)
{
	int i, j, temp;
	int gap = n;	

	do
	{
		gap = gap / 3 + 1;//�������ñȽϼ��Ĵ�С
		for (i = gap ; i < n; i++)
		{
			if (k[i] < k[i-gap])//����Ƚϼ��i-gap
			{
				temp = k[i];

				for (j = i - gap ; k[j] > temp; j-=gap)
				{
					k[j + gap] = k[j];
				}
				k[j + gap] = temp;
			}
		}
	} while (gap > 1);//ѭ���˳�����
}

//int main()
//{
//	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };
//
//	Shellsort(a, 10);
//
//	cout << "�������ǣ�";
//	for (i = 0; i < 10; i++) 
//	{
//		cout << a[i];
//	}
//	system("pause");
//	return 0;
//}