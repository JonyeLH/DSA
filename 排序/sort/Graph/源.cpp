#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX_VERTEX_NUM 4
#define MAX_NAME 2

typedef int Infortype;
typedef int VertexType;
typedef enum { DG, DN, AG, AN } GraphKind; //ͼ������{����ͼ��������������ͼ��������}

typedef struct _ArcNode
{
	int adjvex;        //�û�ָ��Ķ����λ��
	struct _ArcNode *nextarc;  //ָ����һ������ָ��
	Infortype *info;           //�û��������Ϣ
}ArcNode;

typedef struct _VNode
{
	VertexType data;             //������Ϣ
	ArcNode *firstarc;           //ָ���һ�������ö���ĺ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct _ALGraph
{
	AdjList vertices;
	int vexnum, arcnum;  //���ĵ�ǰ�������ͻ���
	int kind;
}ALGraph;

//�ڽӱ�洢Graph��
class Graph
{
private:
	ALGraph G;
public:
	//�󶥵���ͼ�е�λ��
	int LocateVex(ALGraph G, VertexType u);
	//����û�������Ϣ������ͼ
	void CreateGraph(ALGraph &G);
	//����ͼG
	void DestroyGraph(ALGraph &G);
	//���������v�Ķ���ֵ
	VertexType GetVex(ALGraph G, int v);
	//��v����ֵvalue
	void PutVex(ALGraph &G, VertexType v, VertexType value);
	//����v�ĵ�һ���ڽӶ�������
	int FirstAdjVex(ALGraph G, VertexType v);
	//����v�ģ������w�ģ���һ���ڽӶ�������
	int NextAdjVex(ALGraph G, VertexType v, VertexType w);
	//��ͼG�������¶���v
	void InsertVex(ALGraph &G, VertexType v);
	//ɾ��ͼG����v������صĻ�
	void DeleteVex(ALGraph &G, VertexType v);
	//��G�����ӻ�<v,w>
	void InsertArc(ALGraph &G, VertexType v, VertexType w);
	//��ͼG��ɾ����<v,w>
	void DeleteArc(ALGraph &G, VertexType v, VertexType w);
	//�ӵ�v����������ݹ�������ȱ���ͼG
	void DFS(ALGraph g, int v);
	//�ӵ�1���������������ȱ���ͼG
	void DFSTraverse(ALGraph G);
	//�ӵ�1���������������ȱ���ͼG
	void BFSTraverse(ALGraph G);
	//���ͼG
	void Display(ALGraph G);
};

/**
*  ��ʼ������ͼG���ڣ�u��G�ж�������ͬ����
*  �����������G�д��ڶ���u���򷵻ظö�����ͼ�е�λ��
*  ���򷵻�-1
*/
int Graph::LocateVex(ALGraph G, VertexType u)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
		//if( strcmp( u, G.vertices[i].data ) == 0 )
		if (u == G.vertices[i].data)
			return i;
	return -1;
}

/**
*
*  �����ڽӱ�洢�ṹ������û�������Ϣ��ͼG
*  (��һ����������4��ͼ)
*/
void Graph::CreateGraph(ALGraph &G)
{
	int i, j, k;
	int w;                      //Ȩֵ
	VertexType va = NULL, vb = NULL;
	ArcNode *p;
	cout << "������ͼ������(����ͼ:0, ������:1, ����ͼ:2, ������3 ): " << endl;
	cin >> G.kind;
	cout << "������ͼ�Ķ�����������: " << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "������" << G.vexnum << "�������ֵ(" << MAX_NAME << "���ַ�):" << endl;
	for (i = 0; i <G.vexnum; i++)      //���춥������
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	if (G.kind == 1 || G.kind == 3)    //��
		cout << "��˳������ÿ����(��)��Ȩֵ����β�ͻ�ͷ(�Կո���Ϊ���):" << endl;
	else                                //ͼ
		cout << "��˳������ÿ�����ߵĻ�β�ͻ�ͷ(�Կո���Ϊ���):" << endl;
	for (k = 0; k < G.arcnum; k++)     //�����������
	{
		if (G.kind == 1 || G.kind == 3)  //��
			cin >> w >> va >> vb;
		else                             //ͼ
			cin >> va >> vb;
		i = LocateVex(G, va);          //��ͷ
		j = LocateVex(G, vb);          //��β
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = j;
		if (G.kind == 1 || G.kind == 3)
		{
			p->info = (int *)malloc(sizeof(int));
			*(p->info) = w;
		}
		else
			p->info = NULL;
		p->nextarc = G.vertices[i].firstarc;  //���ڱ�ͷ
		G.vertices[i].firstarc = p;
		if (G.kind >= 2)                        //����ͼ�����������ڶ�������
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = i;
			if (G.kind == 3)               //����ͼ
			{
				p->info = (int *)malloc(sizeof(int));
				*(p->info) = w;
			}
			else
				p->info = NULL;            //����ͼ
			p->nextarc = G.vertices[j].firstarc;  //���ڱ�ͷ
			G.vertices[j].firstarc = p;
		}
	}
}

/**
*  ��ʼ������ͼG����
*  �������������ͼG
*
*/
void Graph::DestroyGraph(ALGraph &G)
{
	int i;
	ArcNode *p, *q;
	G.vexnum = 0;
	G.arcnum = 0;
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			q = p->nextarc;
			if (G.kind % 2)
				free(p->info);
			free(p);
			p = q;
		}
	}
}

/**
*  ��ʼ������ͼG���ڣ�v��G��ĳ����������
*  ���������������vֵ
*
*/
VertexType Graph::GetVex(ALGraph G, int v)
{
	if (v >= G.vexnum || v < 0)
		exit(1);
	return G.vertices[v].data;
}

/**
*  ��ʼ������ͼG���ڣ�v��G��ĳ������
*  �����������v����ֵvalue
*
*/
void Graph::PutVex(ALGraph &G, VertexType v, VertexType value)
{
	int i;
	i = LocateVex(G, v);
	if (i > -1)
		G.vertices[i].data = value;
}

/**
*  ��ʼ������ͼG���ڣ�v��G��ĳ������
*  �������������v�ĵ�һ���ڽӶ�������
*  ��������G��û���ڽӶ��㣬�򷵻�-1
*/
int Graph::FirstAdjVex(ALGraph G, VertexType v)
{
	ArcNode *p;
	int v1;
	v1 = LocateVex(G, v);
	p = G.vertices[v1].firstarc;
	if (p)
		return p->adjvex;
	else
		return -1;
}

/**
*  ��ʼ������ͼG���ڣ�v��G��ĳ�����㣬w��v���ڽӶ���
*  �������������v��(�����w��)��һ���ڽӶ������š�
*  ��w��v�����һ���ڽӵ㣬�򷵻�-1
*/
int Graph::NextAdjVex(ALGraph G, VertexType v, VertexType w)
{
	ArcNode *p;
	int v1, w1;
	v1 = LocateVex(G, v);     //v1Ϊ����v��ͼG�е����
	w1 = LocateVex(G, w);     //w1Ϊ����w��ͼG�е����
	p = G.vertices[v1].firstarc;
	while (p  && p->adjvex != w1)  //ָ��p��������ָ����㲻��w
		p = p->nextarc;
	if (!p || p->nextarc)      //û�ҵ�w��w�����һ���ڽӶ���
		return -1;
	else
		return p->nextarc->adjvex;
}

/**
*  ��ʼ������ͼG���ڣ�u��ͼ�ж�������ͬ����
*  �����������ͼG�������¶���v(�������붨����صĻ�������InsertArchive()ȥ��)
*
*/
void Graph::InsertVex(ALGraph &G, VertexType v)
{
	G.vertices[G.vexnum].data = v;   //�����¶�������
	G.vertices[G.vexnum].firstarc = NULL;
	G.vexnum++;                              //ͼG�Ķ�������1
}

/**
*  ��ʼ������ͼG���ڣ�v��G��ĳ������
*  ���������ɾ��G�ж���v������صĻ�
*
*/
void Graph::DeleteVex(ALGraph &G, VertexType v)
{
	int i, j;
	ArcNode *p, *q;
	j = LocateVex(G, v);         //j�Ƕ���v�����
	if (j < 0)                    //v����ͼG�Ķ���
		return;
	p = G.vertices[j].firstarc;    //ɾ����vΪ���ȵĻ����
	while (p)
	{
		q = p;
		p = p->nextarc;
		if (G.kind % 2)          //��
			free(q->info);
		free(q);
		G.arcnum--;               //���������1
	}
	G.arcnum--;                   //��������1
	for (i = j; i < G.vexnum; i++)        //����v����Ķ���ǰ��
		G.vertices[i] = G.vertices[i + 1];
	for (i = 0; i < G.vexnum; i++)     //ɾ����vΪ��ȵĻ�����ұ�Ҫ���޸ı���Ķ���λ��
	{
		p = G.vertices[i].firstarc;    //ָ���1�������
		while (p)                     //�л�
		{
			if (p->adjvex == j)
			{
				if (p == G.vertices[i].firstarc)   //��ɾ����ǵ�1�����
				{
					G.vertices[i].firstarc = p->nextarc;
					if (G.kind % 2)
						free(p->info);
					free(p);
					p = G.vertices[i].firstarc;
					if (G.kind < 2)
						G.arcnum--;
				}
				else
				{
					q->nextarc = p->nextarc;
					if (G.kind % 2)
						free(p->info);
					free(p);
					p = p->nextarc;
					if (G.kind < 2)              //����
						G.arcnum--;               //���������1
				}
			}
			else
			{
				if (p->adjvex > j)
					p->adjvex--;                //�޸ı���Ķ���λ��ֵ
				q = p;
				p = p->nextarc;
			}
		}
	}
}

/**
*  ��ʼ������ͼG���ڣ�v��w��G��������������������G������<v,w>��
*  ��G������ģ�������Գƻ�<w,v>
*
*/
void Graph::InsertArc(ALGraph &G, VertexType v, VertexType w)
{
	ArcNode *p;
	int w1, i, j;
	i = LocateVex(G, v);    //��β��ߵ����
	j = LocateVex(G, w);   //��ͷ��ߵ����
	if (i < 0 || j < 0)
		return;
	G.arcnum++;
	if (G.kind % 2)
	{
		cout << "�����뻡(��)" << v << "->" << w << "��Ȩֵ��" << endl;
		cin >> w1;
	}
	p = (ArcNode *)malloc(sizeof(ArcNode));
	p->adjvex = j;
	if (G.kind % 2)
	{
		p->info = (int *)malloc(sizeof(int));
		*(p->info) = w1;
	}
	else
		p->info = NULL;
	p->nextarc = G.vertices[i].firstarc;    //���ڱ�ͷ
	G.vertices[i].firstarc = p;             //����������һ������
	if (G.kind >= 2)
	{
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = i;
		if (G.kind == 3)
		{
			p->info = (int*)malloc(sizeof(int));
			*(p->info) = w1;
		}
		else
			p->info = NULL;
		p->nextarc = G.vertices[j].firstarc;  //���ڱ�ͷ
		G.vertices[j].firstarc = p;
	}
}

/**
*  ��ʼ������ͼG���ڣ�v��w��G����������
*  �����������G��ɾ����<v,w>,��G������ģ���ɾ���Գƻ�<w,v>
*
*/
void Graph::DeleteArc(ALGraph &G, VertexType v, VertexType w)
{
	ArcNode *p, *q;
	int i, j;
	i = LocateVex(G, v);          //i�Ƕ���(��β)�����
	j = LocateVex(G, w);          //j�Ƕ���(��ͷ)�����
	if (i < 0 || j < 0 || i == j)
		return;
	p = G.vertices[i].firstarc;     //pָ�򶥵�v�ĵ�һ����β
	while (p && p->adjvex != j)    //p��������ָ֮�����Ǵ�ɾ��<v,w>
	{                               //pָ����һ����
		q = p;
		p = p->nextarc;
	}
	if (p && p->adjvex == j)       //�ҵ���<v,w>
	{
		if (p == G.vertices[i].firstarc)   //p��ָ��1����
			G.vertices[i].firstarc = p->nextarc;  //ָ����һ����
		else
			q->nextarc = p->nextarc;  //ָ����һ����
		if (G.kind % 2)
			free(p->info);         //�ͷŴ˽ڵ�
		free(p);                   //���������1
		G.arcnum--;
	}
	if (G.kind >= 2)               //����ɾ���Գƻ�<w,v>
	{
		p = G.vertices[j].firstarc;
		while (p && p->adjvex != i)
		{
			q = p;
			p = p->nextarc;
		}
		if (p && p->adjvex == i)
		{
			if (p == G.vertices[j].firstarc)
				G.vertices[j].firstarc = p->nextarc;
			else
				q->nextarc = p->nextarc;
			if (G.kind == 3)
				free(p->info);
			free(p);
		}
	}
}

/**
*  �������������ڽӱ�G
*
*/
void Graph::Display(ALGraph G)
{
	int i;
	ArcNode *p;
	switch (G.kind)
	{
	case DG:
		cout << "����ͼ" << endl;
		break;
	case DN:
		cout << "������" << endl;
		break;
	case AG:
		cout << "����ͼ" << endl;
		break;
	case AN:
		cout << "������" << endl;
		break;
	}
	cout << G.vexnum << "�����㣺" << endl;
	for (i = 0; i < G.vexnum; i++)
		cout << G.vertices[i].data;
	cout << endl << G.arcnum << "����(��): " << endl;
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			if (G.kind <= 1)
			{
				cout << G.vertices[i].data << "->" << G.vertices[p->adjvex].data;
				if (G.kind == DN)
					cout << ": " << *(p->info);
			}
			else
			{
				if (i < p->adjvex)
				{
					cout << G.vertices[i].data << "->" << G.vertices[p->adjvex].data;
					if (G.kind == DN)
						cout << ": " << *(p->info);
				}
			}
			p = p->nextarc;
		}
		cout << endl;
	}
}

/**
*  �������ӵ�v����������ݹ�������ȱ���ͼG
*  ��Ҫ����һ��������Ϊ��־
*/
bool g_Bvisited[MAX_VERTEX_NUM];

void Graph::DFS(ALGraph G, int v)
{
	VertexType w1, v1;
	int w;
	g_Bvisited[v] = true;
	cout << G.vertices[v].data << endl;
	v1 = GetVex(G, v);
	for (w = FirstAdjVex(G, v1); w >= 0;
	w = NextAdjVex(G, v1, w1 = GetVex(G, w)))
		if (!g_Bvisited[w])
			DFS(G, w);
}

int main(void)
{

	Graph g;
	ALGraph G;

	g.CreateGraph(G);
	g.Display(G);
	return 0;
}
