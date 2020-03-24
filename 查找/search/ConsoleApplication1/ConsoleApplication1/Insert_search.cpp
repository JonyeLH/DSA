////基本思想：基于二分查找算法，将查找点的选择改进为自适应选择，可以提高查找效率。当然，差值查找也属于有序查找。
////二分查找：mid=(low+high)/2, 即mid=low+1/2*(high-low);
////插入查找：mid=low+(key-a[low])/(a[high]-a[low])*(high-low)，
////根据关键字在整个有序表中所处的位置，让mid值的变化更靠近关键字key，这样也就间接地减少了比较次数。
//
////复杂度分析：查找成功或者失败的时间复杂度均为O(log2(log2n))。
////适用类型：表长较大，而关键字分布又比较均匀的查找表，性能比二分更好
//
#include<iostream>

int insertSearch(int *sortedSeq, int seqLength, int keyData);

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int location;
	int target = 4;
	location = insertSearch(array, 9, target);
	printf("%d\n", location);

	system("pause");
	return 0;
}

int insertSearch(int *sortedSeq, int seqLength, int keyData)
{
	int low = 0, mid, high = seqLength - 1;

	while (low <= high)
	{
		mid = low + (keyData - sortedSeq[low]) / (sortedSeq[high] - sortedSeq[low]);
		if (keyData < sortedSeq[mid])
		{
			high = mid - 1;//是mid-1，因为mid已经比较过了
		}
		else if (keyData > sortedSeq[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
//下面的代码运行有错
//#include<iostream>
//#include<math.h>
//#include<algorithm>
//#include<string>
//#include<time.h>
//
//using namespace std;
////插值查找，类似字典里查找每个单词，按照字母大致在字典的那个位置段，进行比例查找
//int Insert_search(int str[], int n, int key)
//{
//	int mid,low = 0, high = n - 1;
//	while (low <= high)
//	{
//		mid = low + (key - str[high] / str[low] - str[low])*(high - low);//这里确定mid与二分查找不同，其余都一致
//		if (str[mid] == key)
//		{
//			return mid;
//		}
//		if (str[mid] < key)
//		{
//			low = mid + 1;
//		}
//		else
//		{
//			high = mid - 1;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	clock_t start, stop;
//	double duration;
//	start = clock();
//
//	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = Insert_search(a, 10, 9);
//	printf("%d\n", i);
//
//	stop = clock();
//	duration = ((double)(stop - start)) / CLK_TCK;
//	printf("该程序运行的时间是：%f\n", duration);
//
//	system("pause");
//	return 0;
//}


