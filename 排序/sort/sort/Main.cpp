#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include "Shellsort.h"
#include "Heapsort.h"
#include "Bubblesort.h"
#include "Mergesort.h"
#include "Seletesort.h"
#include "Insertsort.h"
#include "Quicksort.h"
#include "Quicksort1.h"
#include "Quicksort2.h"
#include "Quicksort3.h"
#include "Quicksort4.h"
using namespace std;

int main()
{
	int i, a[10] = { -1,5,2,6,0,3,9,1,7,4 };

	Heapsort(a, 9);

	int i, a[10] = { 1, 0, 2 ,3 ,4 ,5 ,6, 7 ,8 ,9 };

	Bubblesort(a, 10);

	int i, a[10] = { 5,2,6,0,3,9,1,7,4,8 };

	Shellsort(a, 10);

	Seletesort(a, 10);

	Mergesort(a, 10);

	Insertesort(a, 10);

	Quicksort(a, 10);
	Quicksort1(a, 10);
	Quicksort2(a, 10);
	Quicksort3(a, 10);
	Quicksort4(a, 10);


	cout << "输出结果是：";
	for (i = 0; i < 10; i++)
	{
		cout << a[i];
	}

	system("pause");
	return 0;

}