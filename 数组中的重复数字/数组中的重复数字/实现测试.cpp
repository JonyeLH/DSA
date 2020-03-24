#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	//		  Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		//if(numbers[] == NULL || length <= 0 ) 
		//{
		//return false;
		//}
		for (int i = 0; i<length - 1; i++)
		{
			while (numbers[i] != i)
			{
				if (numbers[i] == numbers[numbers[i]])
				{
					duplication[0] = numbers[i];
					return true;
				}
				swap(numbers, i, numbers[i]);
			}
		}
		return false;
	}


private:
	void swap(int numbers[], int i, int j)
	{
		int t = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = t;
	}
};

int main()
{

}