#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//
//��ʹ��vector����ʱ����Ҫ��������ʹ��������sort�ǳ����㣬���Ǽ򵥵���sort(v.begin(), v.end());
//���Ҫ�Զ��������������sort��������������������ͨ���ⲿ�������������������sort��һ�����ܽ᣺
//
//ͷ�ļ���#include <algorithm>
//
//����������compare���Ǹ��Զ���ıȽϺ�����ָ�룬���ֿ������������
//
//��˵�����ǣ�
//�Ƚ�a��b���������������ô�Ͷ��嵱a<b��ʱ�򷵻�true��
//������뽵����ô�Ͷ��嵱a>b��ʱ�򷵻�true��
bool cmp(const int& a, const int& b)
{
	return a > b; //�Ӵ�С����
}

int main()
{
	int a[10] = { 2, 3, 30, 305, 32, 334, 40, 47, 5, 1 };
	vector<int> nums(a, a + 10);//aĬ��������ĵ�һ��Ԫ�أ�����nums(a, a + 10)��ʾ�����ĳ���

	sort(nums.begin(), nums.end(), cmp);//ͨ������sort��������

	for (auto x : nums)
		cout << x <<"\t";
	//cout << endl;

	system("pause");
	return 0;
}