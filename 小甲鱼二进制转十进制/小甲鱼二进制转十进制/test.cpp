#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

typedef int Elemtype;
typedef struct Node
{
	Elemtype e;
	struct Node *next;
}La;


void unionL(List *La, List Lb)
{
	int La_len, Lb_len, i;
	Elemtype e;
	La_len = Listlength(*La);
	Lb_len = Listlength(Lb);

	for (i = 0; i < Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
		{
			ListInsert(La, ++La_len, e);
		}
	}
}