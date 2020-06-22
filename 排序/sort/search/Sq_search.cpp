
//˳�����
//����˼�룺˳�����Ҳ��Ϊ���β��ң�������������㷨��
//�����ݽṹ���α��һ�˿�ʼ��˳��ɨ�裬���ν�ɨ�赽�Ľ��ؼ��������ֵk��Ƚϣ�
//��������ʾ���ҳɹ�����ɨ�������û���ҵ��ؼ��ֵ���k�Ľ�㣬��ʾ����ʧ�ܡ�
//˳����ҵ�ʱ�临�Ӷ�ΪO(n)

#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<time.h>

using namespace std;
//�򵥵Ĳ�������a��key��ֵ������Ϊn
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

//��������ĸ��Ӷ���O(2n)������ķ����ĸ��Ӷ���O(n)������ͬ��������һ�����⣬����������������ж����ͬ�����������û�п������ڵ�
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
	printf("�ó������е�ʱ���ǣ�%f\n", duration);

	system("pause");
	return 0;
}