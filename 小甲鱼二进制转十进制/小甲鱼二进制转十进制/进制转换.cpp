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
//	//�ж�ջ���Ƿ���������ҽ�������
//	if (s->top - s->base >= s->stactsize)
//	{
//		s->base = (Elemtype *)realloc(s->base, (s->stactsize + STACKINCREMENT) * sizeof(Elemtype));
//		if (!s->base)
//		{
//			exit(0);
//		}
//	}
//	//����ѹջ
//	*(s->top) = e;
//	s->top++;
//}
//
//void pop(sqstack *s, Elemtype *e)
//{
//	//�ж��Ƿ�����
//	if (s->top = s->base)
//	{
//		return;
//	}
//	//�׳�
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
//	cout << "�������������������#���ű�ʾ����\n";
//	cin >> c;
//
//
//	//printf("�������������������#���ű�ʾ����\n");
//	//scanf("%c", &c);
//	while (c != '#')
//	{
//		push(&S, c);
//		cin >> c;
//		//scanf("%c", &c);
//	}
//
//	getchar();	//��\n\���ַ���10���ӻ�����ȥ��
//	len = stacklen(S);
//
//	cout << "ջ�ĵ�ǰ������:" << len;
//
//	//printf("ջ�ĵ�ǰ�����ǣ�&d\n", len);
//
//	for (i = 0; i < len; i++) 
//	{
//		pop(&S, &c);
//		sum = sum + (c -48) * pow(2, i);
//	}
//
//	cout << "ת��Ϊ��ʮ������Ϊ��" << sum;
//	//printf("ת��Ϊ��ʮ������Ϊ��&d\n", sum);
//
//	system("pause");
//	return (S.top - S.base);
//}