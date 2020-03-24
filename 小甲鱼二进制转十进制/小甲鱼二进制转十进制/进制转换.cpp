//#include <iostream>
//#include <math.h>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//#define STACK_INIT_SIZE		20
//#define STACKINCREMENT		10
//
//typedef char Elemtype;
//typedef struct
//{
//	Elemtype *base;
//	Elemtype *top;
//	int stactsize;
//}sqstack;
//
//void Initstact(sqstack *s)
//{
//	s->base = (Elemtype *)malloc(STACK_INIT_SIZE * sizeof(Elemtype));
//	if (!s->base)
//	{
//		exit(0);
//	}
//
//	s->top = s->base;
//	s->stactsize = STACK_INIT_SIZE;
//}
//
//void push(sqstack *s, Elemtype e)
//{
//	//判断栈顶是否溢出，并且进行扩容
//	if (s->top - s->base >= s->stactsize)
//	{
//		s->base = (Elemtype *)realloc(s->base, (s->stactsize + STACKINCREMENT) * sizeof(Elemtype));
//		if (!s->base)
//		{
//			exit(0);
//		}
//	}
//	//数据压栈
//	*(s->top) = e;
//	s->top++;
//}
//
//void pop(sqstack *s, Elemtype *e)
//{
//	//判断是否下溢
//	if (s->top = s->base)
//	{
//		return;
//	}
//	//抛出
//	*e = *--(s->top);
//}
//
//int stacklen(sqstack s)
//{
//	return (s.top - s.base);
//}
//
//int main()
//{
//	Elemtype  c;
//	sqstack S;
//	int i, len, sum = 0;
//	Initstact(&S);
//
//
//
//	cout << "请输入二进制数，输入#符号表示结束\n";
//	cin >> c;
//
//
//	//printf("请输入二进制数，输入#符号表示结束\n");
//	//scanf("%c", &c);
//	while (c != '#')
//	{
//		push(&S, c);
//		cin >> c;
//		//scanf("%c", &c);
//	}
//
//	getchar();	//把\n\的字符“10”从缓冲区去掉
//	len = stacklen(S);
//
//	cout << "栈的当前容量是:" << len;
//
//	//printf("栈的当前容量是：&d\n", len);
//
//	for (i = 0; i < len; i++) 
//	{
//		pop(&S, &c);
//		sum = sum + (c -48) * pow(2, i);
//	}
//
//	cout << "转换为的十进制数为：" << sum;
//	//printf("转换为的十进制数为：&d\n", sum);
//
//	system("pause");
//	return (S.top - S.base);
//}