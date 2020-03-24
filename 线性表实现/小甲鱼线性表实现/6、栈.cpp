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
	//���ջ����������
	if (s->top - s->base >= s->stacksize)
	{
		//realloc�Ǳ�ʾ��malloc���ɵĿռ俽�����µĿռ���
		s->base = (Selemtype *)realloc(s->base,(s->stacksize+ STACTINCREMENT)*sizeof(Selemtype));
		if (!s->base)
			exit(0);

		s->top = s->base + s->stacksize;
		s->stacksize = s->stacksize + STACTINCREMENT;
	}

	*(s->top) = e;
	s->top++;
}

//��ջ
void Pop(sqstack *s, Selemtype e)
{
	if (s->top == s->base)
		return;
	e = *--(s->top);
}

//���ջ
void ClearStack(sqstack *s)
{
	s->top = s->base;
}

//����ջ
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

//����ջ�ĵ�ǰ����
int StackLen(sqstack s)
{
	return(s.top - s.base);
}



//˳��洢�ļ򵥰棬û��ջ��
//ջ��˳��洢ʵ��
typedef struct
{
	Selemtype data[MAXSIZE];
	int top;
}Sqstack;

//��ջ
Status push(Sqstack *s, Selemtype e)
{
	if (s->top > MAXSIZE)
		return error;
	s->top++;
	s->data[s->top] = e;
	return ok;
}

//��ջ
Status pop(Sqstack *s, Selemtype *e)
{
	if (s->top == -1)
		return error;
	*e = s->data[s->top];
	s->top--;
	return ok;
}

//��ջ����ռ�,������ջ������������һ�µģ�Ϊ�˽�ʡ�ռ�
//����ʹһ��ջ��ջ��Ϊ�����ͷ�ˣ���������
//��һ��ջ����ջ��Ϊ�����β�ˣ���ǰ����
//������ջ��ջ������ʱ������ָ��֮�����1����top1+=top2.��ʱ����ռ�ľ�
//������һ��ջ������һ��ջ���̵����
typedef struct
{
	Selemtype data[MAXSIZE];
	int top1;
	int top2;
}SqDoublestack;

Status Push(SqDoublestack *s, Selemtype e, int stacknumber)//stacknumber�ж���ջ1����ջ2
{
	if (s->top1 + 1 == s->top2)//����ջ��������ջ����������push��
		return error;
	if (stacknumber == 1)
	{
		s->data[++s->top1] = e;//ջ��1����ƶ���������ֵ
	}
	else if (stacknumber == 2)
	{
		s->data[--s->top2] = e;//ջ��2��ǰ�ƶ���������ֵ
	}
	return ok;
}

Status Pop(SqDoublestack *s, Selemtype *e, int stacknumber)
{
	if (stacknumber == 1)
	{
		if (s->top1 == -1)//ջ1�Ѿ�Ϊ��ջ
			return error;
		*e = s->data[s->top1--];//��ջ��1Ԫ��ȡ��
	}
	else if (stacknumber == 2)
	{
		if (s->top2 == MAXSIZE)//ջ2�Ѿ�Ϊ��ջ
			return error;
		*e = s->data[s->top2++];//��ջ��2Ԫ��ȡ��
	}
	return ok;
}




//ջ����ʽ�洢�ṹ
typedef struct StackNode
{
	Selemtype data;	//���ջ������
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;	//topָ��
	int count;	//ջԪ�ؼ�����
};

//��ջ
Status Push(LinkStack *s, Selemtype e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
	return ok;
}

//��ջ
Status Pop(LinkStack *s, Selemtype *e)
{
	LinkStackPtr p;
	//if (StackEmpty(*s))//�пգ���Ҫ��дStackEmpty��������
	//	return error;
	*e = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return ok;
}


//������ʽ
int main()
{
	sqstack s;
	char c;
	double d, e=0;
	char str[MAXBUFFER];
	int i = 0;

	initStack(&s);

	cout << "�밴�沨�����ʽ������������ݣ�������������ÿո����,��#��Ϊ������־"<<endl;
	cin >> c;

	while (c!='#')
	{
		while (isdigit(c) || c=='.')	//���ڹ�������
		{
			str[i++] = c;
			str[i] = '\n';
			if (i >= 10)
			{
				cout << "������������ݹ���";
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
					cout << "��������Ϊ��";
					return -1;
				}
				break;
		}
		cin >> c;
	}
	Pop(&s, d);
	cout << "���յļ�����Ϊ��" << d << endl;


	system("pause");
	return 0;
}

//��׺���ʽ��ִ���д��޷���������ж�������
int main()
{
	sqstack s;
	char c, e=0;

	initStack( &s );

	cout << "��������׺���ʽ����#��Ϊ������־��" << endl;
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
			cout << "���������ʽ����" << endl;
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
