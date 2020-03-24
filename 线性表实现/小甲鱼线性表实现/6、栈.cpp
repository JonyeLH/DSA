#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

#define ok	1
#define error 0
#define MAXSIZE 20
//#define stacksize 10
#define STACT_INIT_SIZE 100
#define STACTINCREMENT 10
#define MAXBUFFER	10

typedef int Selemtype;
typedef int Status;

typedef struct
{
	Selemtype *base;
	Selemtype *top;
	int stacksize;
}sqstack;

void initStack(sqstack *s)
{
	s->base = (Selemtype *)malloc(STACT_INIT_SIZE * sizeof(Selemtype));
	if (!s->base)
		exit(0);
	s->top = s->base;
	s->stacksize = STACT_INIT_SIZE;
}

//push
void Push(sqstack *s, Selemtype e)
{
	//如果栈满，则扩容
	if (s->top - s->base >= s->stacksize)
	{
		//realloc是表示将malloc生成的空间拷贝到新的空间里
		s->base = (Selemtype *)realloc(s->base,(s->stacksize+ STACTINCREMENT)*sizeof(Selemtype));
		if (!s->base)
			exit(0);

		s->top = s->base + s->stacksize;
		s->stacksize = s->stacksize + STACTINCREMENT;
	}

	*(s->top) = e;
	s->top++;
}

//出栈
void Pop(sqstack *s, Selemtype e)
{
	if (s->top == s->base)
		return;
	e = *--(s->top);
}

//清空栈
void ClearStack(sqstack *s)
{
	s->top = s->base;
}

//销毁栈
void DestroyStack(sqstack *s)
{
	int i, len;
	len = s->stacksize;
	for (i = 0; i < len; i++)
	{
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->stacksize = 0;
}

//计算栈的当前容量
int StackLen(sqstack s)
{
	return(s.top - s.base);
}



//顺序存储的简单版，没有栈底
//栈的顺序存储实现
typedef struct
{
	Selemtype data[MAXSIZE];
	int top;
}Sqstack;

//入栈
Status push(Sqstack *s, Selemtype e)
{
	if (s->top > MAXSIZE)
		return error;
	s->top++;
	s->data[s->top] = e;
	return ok;
}

//出栈
Status pop(Sqstack *s, Selemtype *e)
{
	if (s->top == -1)
		return error;
	*e = s->data[s->top];
	s->top--;
	return ok;
}

//两栈共享空间,当两个栈的数据类型是一致的，为了节省空间
//可以使一个栈的栈底为数组的头端，往后生长
//另一个栈则是栈底为数组的尾端，往前生长
//当两个栈的栈顶相遇时，两个指针之间相差1，即top1+=top2.这时数组空间耗尽
//多用于一个栈增长，一个栈缩短的情况
typedef struct
{
	Selemtype data[MAXSIZE];
	int top1;
	int top2;
}SqDoublestack;

Status Push(SqDoublestack *s, Selemtype e, int stacknumber)//stacknumber判断是栈1还是栈2
{
	if (s->top1 + 1 == s->top2)//两个栈顶相遇，栈已满，不能push了
		return error;
	if (stacknumber == 1)
	{
		s->data[++s->top1] = e;//栈顶1向后移动，并插入值
	}
	else if (stacknumber == 2)
	{
		s->data[--s->top2] = e;//栈顶2向前移动，并插入值
	}
	return ok;
}

Status Pop(SqDoublestack *s, Selemtype *e, int stacknumber)
{
	if (stacknumber == 1)
	{
		if (s->top1 == -1)//栈1已经为空栈
			return error;
		*e = s->data[s->top1--];//将栈顶1元素取出
	}
	else if (stacknumber == 2)
	{
		if (s->top2 == MAXSIZE)//栈2已经为空栈
			return error;
		*e = s->data[s->top2++];//将栈顶2元素取出
	}
	return ok;
}




//栈的链式存储结构
typedef struct StackNode
{
	Selemtype data;	//存放栈的数据
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;	//top指针
	int count;	//栈元素计数器
};

//进栈
Status Push(LinkStack *s, Selemtype e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
	return ok;
}

//出栈
Status Pop(LinkStack *s, Selemtype *e)
{
	LinkStackPtr p;
	//if (StackEmpty(*s))//判空，需要编写StackEmpty（）函数
	//	return error;
	*e = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return ok;
}


//后序表达式
int main()
{
	sqstack s;
	char c;
	double d, e=0;
	char str[MAXBUFFER];
	int i = 0;

	initStack(&s);

	cout << "请按逆波兰表达式输入待计算数据，数据与运算符用空格隔开,以#作为结束标志"<<endl;
	cin >> c;

	while (c!='#')
	{
		while (isdigit(c) || c=='.')	//用于过滤数字
		{
			str[i++] = c;
			str[i] = '\n';
			if (i >= 10)
			{
				cout << "错误：输入的数据过大";
				return -1;
			}
			cin >> c;
			if (c == ' ')
			{
				d = atof(str);
				Push(&s, d);
				i = 0;
				break;
			}
		}
		switch (c)
		{
			case '+':
				Pop(&s, e);
				Pop(&s, d);
				Push(&s, d + e);
				break;
			case '-':
				Pop(&s, e);
				Pop(&s, d);
				Push(&s, d - e);
				break;
			case '*':
				Pop(&s, e);
				Pop(&s, d);
				Push(&s, d * e);
				break;
			case '/':
				Pop(&s, e);
				Pop(&s, d);
				if (e != 0)
				{
					Push(&s, d / e);
				}
				else
				{
					cout << "除数不能为零";
					return -1;
				}
				break;
		}
		cin >> c;
	}
	Pop(&s, d);
	cout << "最终的计算结果为：" << d << endl;


	system("pause");
	return 0;
}

//中缀表达式，执行有错，无法进入各个判断条件中
int main()
{
	sqstack s;
	char c, e=0;

	initStack( &s );

	cout << "请输入中缀表达式，以#作为结束标志：" << endl;
	cin >> c;

	while (c != '#')
	{
		while (c >= '0' && c <= '0')
		{
			cout << c << endl;
			cin >> c;
			if (c<'0' || c>'9')
			{
				cout << " ";
			}
		}
		if ( ')' == c)
		{
			Pop(&s, e);
			while ( '(' != e)
			{
				cout << e << endl;
				Pop(&s, e);
			}
		}
		else if ( '+' == c || '-' == c)
		{
			if (!StackLen(s))
			{
				Push(&s, c);
			}
			else
			{
				do
				{
					Pop(&s, e);
					if ('(' == e)
					{
						Push(&s, e);
					}
					else
					{
						cout << e << endl;
					}
				} while (StackLen(s) && '(' != e);
				Push(&s, c);
			}
		}
		else if ('*' == c || '/' == c || '(' == c)
		{
			Push(&s, c);
		}
		else if ('#' == c)
		{
			break;
		}
		else
		{
			cout << "出错：输入格式错误" << endl;
			system("pause");
			return -1;
		}

		cin >> c;
	}

	while (StackLen(s))
	{
		Pop(&s, e);
		cout << e << endl;
	}

	//system("pause");
	return 0;
}
