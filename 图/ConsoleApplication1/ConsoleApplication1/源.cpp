#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX_VERTEX_NUM 4
#define MAX_NAME 2

typedef int Infortype;
typedef int VertexType;
typedef enum { DG, DN, AG, AN } GraphKind; //图形种类{有向图，有向网，无向图，无向网}

typedef struct _ArcNode
{
	int adjvex;        //该弧指向的顶点的位置
	struct _ArcNode *nextarc;  //指向下一条弧的指针
	Infortype *info;           //该弧的相关信息
}ArcNode;

typedef struct _VNode
{
	VertexType data;             //顶点信息
	ArcNode *firstarc;           //指向第一条依附该顶点的狐的指针
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct _ALGraph
{
	AdjList vertices;
	int vexnum, arcnum;  //弧的当前顶点数和弧数
	int kind;
}ALGraph;

//邻接表存储Graph类
class Graph
{
private:
	ALGraph G;
public:
	//求顶点在图中的位置
	int LocateVex(ALGraph G, VertexType u);
	//构造没有相关信息的无向图
	void CreateGraph(ALGraph &G);
	//销毁图G
	void DestroyGraph(ALGraph &G);
	//返回序号是v的顶点值
	VertexType GetVex(ALGraph G, int v);
	//对v赋新值value
	void PutVex(ALGraph &G, VertexType v, VertexType value);
	//返回v的第一个邻接顶点的序号
	int FirstAdjVex(ALGraph G, VertexType v);
	//返回v的（相对于w的）下一个邻接顶点的序号
	int NextAdjVex(ALGraph G, VertexType v, VertexType w);
	//在图G中增加新顶点v
	void InsertVex(ALGraph &G, VertexType v);
	//删除图G顶点v及其相关的弧
	void DeleteVex(ALGraph &G, VertexType v);
	//在G中增加弧<v,w>
	void InsertArc(ALGraph &G, VertexType v, VertexType w);
	//在图G中删除弧<v,w>
	void DeleteArc(ALGraph &G, VertexType v, VertexType w);
	//从第v个顶点出发递归深度优先遍历图G
	void DFS(ALGraph g, int v);
	//从第1个顶点出发深度优先遍历图G
	void DFSTraverse(ALGraph G);
	//从第1个顶点出发广度优先遍历图G
	void BFSTraverse(ALGraph G);
	//输出图G
	void Display(ALGraph G);
};

/**
*  初始条件：图G存在，u和G中定点有相同特征
*  操作结果：若G中存在顶点u，则返回该顶点在图中的位置
*  否则返回-1
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
*  采用邻接表存储结构，构造没有相关信息的图G
*  (用一个函数构造4种图)
*/
void Graph::CreateGraph(ALGraph &G)
{
	int i, j, k;
	int w;                      //权值
	VertexType va = NULL, vb = NULL;
	ArcNode *p;
	cout << "请输入图的类型(有向图:0, 有向网:1, 无向图:2, 无向网3 ): " << endl;
	cin >> G.kind;
	cout << "请输入图的顶点数，边数: " << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "请输入" << G.vexnum << "个顶点的值(" << MAX_NAME << "个字符):" << endl;
	for (i = 0; i <G.vexnum; i++)      //构造顶点向量
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	if (G.kind == 1 || G.kind == 3)    //网
		cout << "请顺序输入每条弧(边)的权值，弧尾和弧头(以空格作为间隔):" << endl;
	else                                //图
		cout << "请顺序输入每条弧边的弧尾和弧头(以空格作为间隔):" << endl;
	for (k = 0; k < G.arcnum; k++)     //构造表结点链表
	{
		if (G.kind == 1 || G.kind == 3)  //网
			cin >> w >> va >> vb;
		else                             //图
			cin >> va >> vb;
		i = LocateVex(G, va);          //弧头
		j = LocateVex(G, vb);          //弧尾
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = j;
		if (G.kind == 1 || G.kind == 3)
		{
			p->info = (int *)malloc(sizeof(int));
			*(p->info) = w;
		}
		else
			p->info = NULL;
		p->nextarc = G.vertices[i].firstarc;  //插在表头
		G.vertices[i].firstarc = p;
		if (G.kind >= 2)                        //无向图或网，产生第二个表结点
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = i;
			if (G.kind == 3)               //无向图
			{
				p->info = (int *)malloc(sizeof(int));
				*(p->info) = w;
			}
			else
				p->info = NULL;            //无向图
			p->nextarc = G.vertices[j].firstarc;  //插在表头
			G.vertices[j].firstarc = p;
		}
	}
}

/**
*  初始条件：图G存在
*  操作结果：销毁图G
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
*  初始条件：图G存在，v是G中某个顶点的序号
*  操作结果：若返回v值
*
*/
VertexType Graph::GetVex(ALGraph G, int v)
{
	if (v >= G.vexnum || v < 0)
		exit(1);
	return G.vertices[v].data;
}

/**
*  初始条件：图G存在，v是G中某个顶点
*  操作结果：对v赋新值value
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
*  初始条件：图G存在，v是G中某个顶点
*  操作结果：返回v的第一个邻接顶点的序号
*  若顶点在G中没有邻接顶点，则返回-1
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
*  初始条件：图G存在，v是G中某个顶点，w是v的邻接顶点
*  操作结果：返回v的(相对于w的)下一个邻接顶点的序号。
*  若w是v的最后一个邻接点，则返回-1
*/
int Graph::NextAdjVex(ALGraph G, VertexType v, VertexType w)
{
	ArcNode *p;
	int v1, w1;
	v1 = LocateVex(G, v);     //v1为顶点v在图G中的序号
	w1 = LocateVex(G, w);     //w1为顶点w在图G中的序号
	p = G.vertices[v1].firstarc;
	while (p  && p->adjvex != w1)  //指针p不空且所指针表结点不是w
		p = p->nextarc;
	if (!p || p->nextarc)      //没找到w或w是最后一个邻接顶点
		return -1;
	else
		return p->nextarc->adjvex;
}

/**
*  初始条件：图G存在，u和图中顶点又相同特征
*  操作结果：在图G中增添新顶点v(不增添与定点相关的弧，留待InsertArchive()去做)
*
*/
void Graph::InsertVex(ALGraph &G, VertexType v)
{
	G.vertices[G.vexnum].data = v;   //构造新顶点向量
	G.vertices[G.vexnum].firstarc = NULL;
	G.vexnum++;                              //图G的顶点数加1
}

/**
*  初始条件：图G存在，v是G中某个顶点
*  操作结果：删除G中顶点v及其相关的弧
*
*/
void Graph::DeleteVex(ALGraph &G, VertexType v)
{
	int i, j;
	ArcNode *p, *q;
	j = LocateVex(G, v);         //j是定点v的序号
	if (j < 0)                    //v不是图G的顶点
		return;
	p = G.vertices[j].firstarc;    //删除以v为出度的弧或边
	while (p)
	{
		q = p;
		p = p->nextarc;
		if (G.kind % 2)          //网
			free(q->info);
		free(q);
		G.arcnum--;               //弧或边数减1
	}
	G.arcnum--;                   //顶点数减1
	for (i = j; i < G.vexnum; i++)        //顶点v后面的顶点前移
		G.vertices[i] = G.vertices[i + 1];
	for (i = 0; i < G.vexnum; i++)     //删除以v为入度的弧或边且必要是修改表结点的顶点位置
	{
		p = G.vertices[i].firstarc;    //指向第1条弧或边
		while (p)                     //有弧
		{
			if (p->adjvex == j)
			{
				if (p == G.vertices[i].firstarc)   //待删结点是第1个结点
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
					if (G.kind < 2)              //有向
						G.arcnum--;               //弧或边数减1
				}
			}
			else
			{
				if (p->adjvex > j)
					p->adjvex--;                //修改表结点的顶点位置值
				q = p;
				p = p->nextarc;
			}
		}
	}
}

/**
*  初始条件：图G存在，v和w是G中两个顶点操作结果：在G中增添弧<v,w>，
*  若G是无向的，则还增添对称弧<w,v>
*
*/
void Graph::InsertArc(ALGraph &G, VertexType v, VertexType w)
{
	ArcNode *p;
	int w1, i, j;
	i = LocateVex(G, v);    //弧尾或边的序号
	j = LocateVex(G, w);   //弧头或边的序号
	if (i < 0 || j < 0)
		return;
	G.arcnum++;
	if (G.kind % 2)
	{
		cout << "请输入弧(边)" << v << "->" << w << "的权值：" << endl;
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
	p->nextarc = G.vertices[i].firstarc;    //插在表头
	G.vertices[i].firstarc = p;             //无向，生产另一个表结点
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
		p->nextarc = G.vertices[j].firstarc;  //插在表头
		G.vertices[j].firstarc = p;
	}
}

/**
*  初始条件：图G存在，v和w是G中两个顶点
*  操作结果：在G中删除弧<v,w>,若G是无向的，则还删除对称弧<w,v>
*
*/
void Graph::DeleteArc(ALGraph &G, VertexType v, VertexType w)
{
	ArcNode *p, *q;
	int i, j;
	i = LocateVex(G, v);          //i是定点(弧尾)的序号
	j = LocateVex(G, w);          //j是定点(弧头)的序号
	if (i < 0 || j < 0 || i == j)
		return;
	p = G.vertices[i].firstarc;     //p指向顶点v的第一条弧尾
	while (p && p->adjvex != j)    //p不空且所指之弧不是待删除<v,w>
	{                               //p指向下一条弧
		q = p;
		p = p->nextarc;
	}
	if (p && p->adjvex == j)       //找到弧<v,w>
	{
		if (p == G.vertices[i].firstarc)   //p是指第1条弧
			G.vertices[i].firstarc = p->nextarc;  //指向下一条弧
		else
			q->nextarc = p->nextarc;  //指向下一条弧
		if (G.kind % 2)
			free(p->info);         //释放此节点
		free(p);                   //弧或边数减1
		G.arcnum--;
	}
	if (G.kind >= 2)               //无向，删除对称弧<w,v>
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
*  操作结果：输出邻接表G
*
*/
void Graph::Display(ALGraph G)
{
	int i;
	ArcNode *p;
	switch (G.kind)
	{
	case DG:
		cout << "有向图" << endl;
		break;
	case DN:
		cout << "有向网" << endl;
		break;
	case AG:
		cout << "无向图" << endl;
		break;
	case AN:
		cout << "无向网" << endl;
		break;
	}
	cout << G.vexnum << "个顶点：" << endl;
	for (i = 0; i < G.vexnum; i++)
		cout << G.vertices[i].data;
	cout << endl << G.arcnum << "条弧(边): " << endl;
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
*  遍历，从第v个顶点出发递归深度优先遍历图G
*  需要申请一个数组作为标志
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
