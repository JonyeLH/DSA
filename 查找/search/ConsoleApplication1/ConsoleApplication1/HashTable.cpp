#include "stdio.h"    
#include "stdlib.h"   

#define HASHSIZE 10 // 定义散列表长度 
#define NULLKEY -32768 

typedef struct
{
	int *elem; // 数据元素存储地址，动态分配数组 
	int count; //  当前数据元素个数 
}HashTable;

int m = 0;

int Init(HashTable *H)
{
	int i;

	m = HASHSIZE;
	H->elem = (int *)malloc(m * sizeof(int)); //分配内存
	H->count = m;
	for (i = 0; i<m; i++)
	{
		H->elem[i] = NULLKEY;
	}
	return 1;
}


int Hash(int k)
{
	return k % m;//除留余数法
}


void Insert(HashTable *H, int k)
{
	int addr = Hash(k);
	while (H->elem[addr] != NULLKEY)
	{
		addr = (addr + 1) % m;//开放定址法
	}
	H->elem[addr] = k;
}

int Search(HashTable *H, int k)
{
	int addr = Hash(k); //求哈希地址


	while (H->elem[addr] != k)//开放定址法解决冲突
	{
		addr = (addr + 1) % m;

		if (H->elem[addr] == NULLKEY || addr == Hash(k))
			return -1;
	}
	return addr;
}

void Result(HashTable *H)//散列表元素显示
{
	int i;
	for (i = 0; i<H->count; i++)
	{
		printf("%d ", H->elem[i]);
	}
	printf("\n");
}

void main()
{
	int i, j, addr;
	HashTable H;
	int arr[HASHSIZE] = { NULL };

	Init(&H);

	printf("输入关键字集合:");
	for (i = 0; i<HASHSIZE; i++)
	{
		scanf_s("%d", &arr[i]);
		Insert(&H, arr[i]);
	}
	Result(&H);

	printf("输入需要查找的元素：");
	scanf_s("%d", &j);
	addr = Search(&H, j);
	if (addr == -1)
		printf("元素不存在\n");
	else
		printf("%d元素在表中的位置是:%d\n", j, addr);

}