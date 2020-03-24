//#include <stdio.h>???
//
//#include <stdlib.h>??
//
//#include <math.h>?
//
//#include <time.h>
//
//#include <iostream>
//
//#define MAXVEX 6 // ��󶥵���
//
//#define INF 65535
//
//
//
//typedef int Status; //Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
//
//typedef char VertexType; //��������?
//
//typedef int EdgeType; // ���ϵ�Ȩֵ����
//
//typedef struct MGraph
//{
//	VertexType vexs[MAXVEX]; //�����
//	EdgeType arc[MAXVEX][MAXVEX];//�ڽӾ��󣬿ɿ����߱�
//	int numNodes, numEdges; // ͼ�е�ǰ�Ķ������ͱ���
//}MGraph;
//
//
//
// ����������ͼ���ڽӾ����ʾ
//void CreateMGraph(MGraph *G)
//
//{
//	int i, j, k, w;
//	printf("���붥�����ͱ���:\n");
//	scanf("%d,%d", &G->numNodes, &G->numEdges); // ���붥�����ͱ���
//
//	for (i = 0; i <G->numNodes; i++) // ���붥����Ϣ,���������
//		scanf("%c", &G->vexs[i]);
//
//	for (i = 0; i <G->numNodes; i++)
//		for (j = 0; j <G->numNodes; j++)
//			G->arc[i][j] = INF;	//�ڽӾ����ʼ��
//
//	for (k = 0; k <G->numEdges; k++) // ����numEdges���ߣ������ڽӾ���
//	{
//		printf("�����(vi,vj)�ϵ��±�i���±�j��Ȩw:\n");
//		scanf("%d,%d,%d", &i, &j, &w); // �����(vi,vj)�ϵ�Ȩw
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j]; //��Ϊ������ͼ������Գ�
//	}
//}
//
//
//
//int main(void)
//
//{
//
//	MGraph G;
//
//	CreateMGraph(&G);
//
//	return 0;
//
//}
//
//
//
//#include<stdio.h>
//
//#include<iostream.h>
//
//
//
//#define MAXVEX 100 //��󶥵���
//
//typedef char VertexType; //��������Ӧ���û�����
//
//typedef int EdgeType; //���ϵ�Ȩֵ����Ӧ���û�����
//
//
//
//typedef struct EdgeNode//�߱���
//
//{
//
//	int adjvex;//�ڽӵ���,�洢�ö����Ӧ���±�
//
//	EdgeType weight;//���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ
//
//	struct EdgeNode *next; //����,ָ����һ���ڽӵ�
//
//} EdgeNode;
//
//
//
//typedef struct VextexNode//�������
//
//{
//
//	VertexType data;//������,�洢������Ϣ
//
//	EdgeNode *firstedge;//�߱�ͷָ��
//
//} VextexNode, AdjList[MAXVEX];
//
//
//
//typedef struct
//
//{
//
//	AdjList adjList;
//
//	int numNodes, numEdges; // ͼ�е�ǰ�������ͱ���
//
//} GraphAdjList;
//
//
//
//
//
//voidCreateALGraph(GraphAdjList *Gp)
//
//{
//
//	int i, j, k;
//
//	EdgeNode *pe;
//
//	printf("���붥�����ͱ���(�ո�ָ���:");
//
//	scanf("%d%d", &Gp->numNodes, &Gp->numEdges);
//
//
//
//	for (i = 0; i < Gp->numNodes; i++)
//
//	{
//
//		printf("���붥����Ϣ:");
//
//		scanf("%c", &Gp->adjList[i].data);
//
//		Gp->adjList[i].firstedge = NULL;//���߱���Ϊ�ձ�
//
//	}
//
//
//
//	for (k = 0; k < Gp->numEdges; k++)//�����߱�
//
//	{
//
//		printf("�����(vi,vj)�Ķ������i,j���ո�ָ�:");
//
//		scanf("%d%d", &i, &j);
//
//		pe = (EdgeNode*)malloc(sizeof(EdgeNode));
//
//		pe->adjvex = j;//�ڽ����Ϊj
//
//					   ��pe��ָ��ָ��ǰ������ָ��Ľ��
//
//		pe->next = Gp->adjList[i].firstedge;
//
//		Gp->adjList[i].firstedge = pe;//����ǰ�����ָ��ָ��pe
//
//
//
//		pe = (EdgeNode*)malloc(sizeof(EdgeNode));
//
//		pe->adjvex = i;
//
//		pe->next = Gp->adjList[j].firstedge;
//
//		Gp->adjList[j].firstedge = pe;
//
//
//
//	}
//
//}
//
//
//
//int main(void)
//
//{
//
//	GraphAdjList GL;
//
//	CreateALGraph(&GL);
//
//
//
//	return 0;
//
//}
//
//
//
//
//
//prim�㷨��Kruskal����ʵ�ַ���
//
//
//
//#include<stdio.h>?
//
//int arr[101][101];
//
//int main()
//
//{
//
//	int n, ttt = 0;
//
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//
//	{
//
//		for (int j = 1; j <= n; j++)
//
//		{
//
//			scanf("%d", &arr[i][j]);
//
//		}
//
//	}
//
//	for (int j = 2; j <= n; j++)
//
//	{
//
//		int min = 100000000;
//
//		int index = 0;
//
//		for (int i = 1; i <= n; i++)
//
//		{
//
//			if (arr[1][i] == 0) continue;
//
//			if (arr[1][i]<min)
//
//			{
//
//				min = arr[1][i];
//
//				index = i;
//
//			}
//
//		}
//
//		ttt += arr[1][index];
//
//		for (int i = 1; i <= n; i++)
//
//		{
//
//			arr[1][i] = arr[1][i]<arr[index][i] ? arr[1][i] : arr[index][i];
//
//		}
//
//	}
//
//	printf("%d\n", ttt);
//
//	return 0;
//
//}
//
//
//
//#include <stdio.h>
//
//#include <stdlib.h>
//
//#define MAX_VEX_NUM 50
//
//#define MAX_ARC_NUM 100
//
//#define UN_REACH 1000
//
//
//
//typedef char VertexType;
//
//typedef enum
//
//{
//
//	DG, UDG
//
//}GraphType;
//
//typedef struct
//
//{
//
//	VertexType vexs[MAX_VEX_NUM];
//
//	int arcs[MAX_VEX_NUM][MAX_VEX_NUM];
//
//	int vexnum, arcnum;
//
//	GraphType type;
//
//}MGraph;
//
//
//
//
//
//
//
///**
//
//?* �������Ƶõ�ָ�������ڶ��㼯���е��±�
//
// ?* vex? ����
//
//  ?* return ����ҵ����򷵻��±꣬���򣬷��أ�
//
//   ?*/
//
//int getIndexOfVexs(char vex, MGraph *MG)
//
//{
//
//	int i;
//
//	for (i = 1; i <= MG->vexnum; i++)
//
//	{
//
//		if (MG->vexs[i] == vex)
//
//		{
//
//			return i;
//
//		}
//
//	}
//
//	return 0;
//
//}
//
//
//
///**
//
//?* �����ڽӾ���
//
// ?*/
//
//void create_MG(MGraph *MG)
//
//{
//
//	int i, j, k, weight;
//
//	int v1, v2, type;
//
//	char c1, c2;
//
//	printf("������ͼ����DG��0����ͼ��1�� :");
//
//	scanf("%d", &type);
//
//	if (type == 0)
//
//		MG->type = DG;
//
//	else if (type == 1)
//
//		MG->type = UDG;
//
//	else
//
//	{
//
//		printf("��������ȷ��ͼ������DG��0����ͼ��1��");
//
//		return;
//
//	}
//
//
//
//	printf("������vexmun : ");
//
//	scanf("%d", &MG->vexnum);
//
//	printf("������ arcnum :");
//
//	scanf("%d", &MG->arcnum);
//
//	getchar();
//
//	for (i = 1; i <= MG->vexnum; i++)
//
//	{
//
//		printf("������ %dth vex(char):", i);
//
//		scanf("%c", &MG->vexs[i]);
//
//		getchar();
//
//	}
//
//
//
//	��ʼ���ڽӾ���
//
//	for (i = 1; i <= MG->vexnum; i++)
//
//	{
//
//		for (j = 1; j <= MG->vexnum; j++)
//
//		{
//
//			if (i == j)
//
//				MG->arcs[i][j] = 0;
//
//			else
//
//				MG->arcs[i][j] = UN_REACH;
//
//		}
//
//	}
//
//
//
//	����ߵ���Ϣ�������ڽӾ���
//
//	for (k = 1; k <= MG->arcnum; k++)
//
//	{
//
//		printf("������ %dth arc v1(char) v2(char) weight(int):", k);
//
//
//
//		scanf("%c %c %d", &c1, &c2, &weight);
//
//		v1 = getIndexOfVexs(c1, MG);
//
//		v2 = getIndexOfVexs(c2, MG);
//
//		if (MG->type == 1)
//
//			MG->arcs[v1][v2] = MG->arcs[v2][v1] = weight;
//
//		else
//
//			MG->arcs[v1][v2] = weight;
//
//		getchar();
//
//	}
//
//
//
//
//
//
//
//
//
//}
//
///**
//
//?* ��ӡ�ڽӾ���Ͷ�����Ϣ
//
// ?*/
//
//void print_MG(MGraph MG)
//
//{
//
//	int i, j;
//
//	if (MG.type == DG)
//
//	{
//
//		printf("Graph type: Directgraph");
//
//	}
//
//	else
//
//	{
//
//		printf("Graph type: Undirectgraph");
//
//	}
//
//
//
//	printf("ͼ�Ķ�����: %d,MG.vexnum");
//
//	printf("ͼ����: %d,MG.arcnum");
//
//
//
//	printf("Vertex set:");
//
//	for (i = 1; i <= MG.vexnum; i++)
//
//		printf("%c", MG.vexs[i]);
//
//	printf("�ڽӾ���:");
//
//
//
//	for (i = 1; i <= MG.vexnum; i++)
//
//	{
//
//		j = 1;
//
//		for (; j < MG.vexnum; j++)
//
//		{
//
//			printf("%d", MG.arcs[i][j]);
//
//		}
//
//		printf("%d", MG.arcs[i][j]);
//
//	}
//
//}
//
//
//
//
//
// ����߽ṹ��
//
//typedef struct
//
//{
//
//	int start;
//
//	int end;
//
//	int cost;
//
//}Edge;
//
//
//
//
//
///* *
//
//?* ���ڽӾ���õ��ߵ���Ϣ
//
// ?*
//
//  ?* */
//
//void init_edge(MGraph MG, Edgeedge[])
//
//{
//
//	int i, j;
//
//	int count = 0;
//
//	if (MG.type == 0)
//
//	{
//
//		for (i = 1; i <= MG.vexnum; i++)
//
//		{
//
//			for (j = 1; j <= MG.vexnum; j++)
//
//			{
//
//				if (MG.arcs[i][j] != 0 && MG.arcs[i][j] != UN_REACH)
//
//				{
//
//					edge[count].start = i;
//
//					edge[count].end = j;
//
//					edge[count].cost = MG.arcs[i][j];
//
//					count++;
//
//				}
//
//			}
//
//		}
//
//	}
//
//	else
//
//	{
//
//		for (i = 1; i <= MG.vexnum; i++)
//
//		{
//
//			for (j = i; j <= MG.vexnum; j++)
//
//			{
//
//				if (MG.arcs[i][j] != 0 && MG.arcs[i][j] != UN_REACH)
//
//				{
//
//					edge[count].start = i;
//
//					edge[count].end = j;
//
//					edge[count].cost = MG.arcs[i][j];
//
//					count++;
//
//				}
//
//			}
//
//		}
//
//	}
//
//
//
//}
//
//
//
//
//
//
//
//
//
///* *
//
//?*�����߰�Ȩֵ�Ӵ�С����
//
// ?* */
//
//void sort_edge(Edge edge[], intarcnum)
//
//{
//
//	int i, j;
//
//	Edge temp;
//
//	for (i = 0; i < arcnum - 1; i++)
//
//	{
//
//		for (j = i + 1; j < arcnum; j++)
//
//		{
//
//			if (edge[i].cost > edge[j].cost)
//
//			{
//
//				temp = edge[i];
//
//				edge[i] = edge[j];
//
//				edge[j] = temp;
//
//			}
//
//		}
//
//	}
//
//}
//
//
//
///* *
//
//?* ����ߵ���Ϣ
//
// ?* */
//
//void print_edge(Edgeedge[], int arcnum)
//
//{
//
//	int i = 0;
//
//	while (i < arcnum)
//
//	{
//
//		printf("%d,%d,%d", edge[i].start, edge[i].end, edge[i].cost);
//
//		i++;
//
//	}
//
//}
//
///**
//
//*??? �ҳ�ָ���ڵ����������ͨ�������������ҳ�����ڵ���father�������±ꡣ
//
//**/ int findFather(intfather[], int v)
//
//{
//
//	int t = v;
//
//	while (father[t] != -1)
//
//		t = father[t];
//
//	return t;
//
//}
//
//
//
///* *
//
//?*Kruskal�㷨����С������
//
// ?* */
//
//void Kruskal_MG(MGraph MG, Edgeedge[])
//
//{
//
//	int father[MAX_VEX_NUM];
//
//	int i, count, vf1, vf2;
//
//	 ��ʼ��father����
//
//	for (i = 0; i < MAX_VEX_NUM; i++)
//
//	{
//
//		father[i] = -1;
//
//	}
//
//	i = 0;
//
//	count = 0; // ͳ�Ƽ�����С�����еı���
//
//			    ���������������֮��ı�
//
//	while (i < MG.arcnum && count< MG.arcnum)
//
//	{
//
//		vf1 = findFather(father, edge[i].start);
//
//		vf2 = findFather(father, edge[i].end);
//
//		 ����������ڵ㲻����ͬһ����ͨ�����������ͬһ����ͨ����
//
//		if (vf1 != vf2)
//
//		{
//
//			father[vf2] = vf1;
//
//			count++;
//
//			printf("%c,%c,%d", MG.vexs[edge[i].start], MG.vexs[edge[i].end], edge[i].cost);
//
//		}
//
//		i++;
//
//	}
//
//}
//
///**
//
//?* ������
//
// ?*/
//
//int main(void)
//
//{
//
//	MGraph MG;
//
//	Edge edge[MAX_ARC_NUM];
//
//	create_MG(&MG);
//
//	print_MG(MG);
//
//	init_edge(MG, edge);
//
//	sort_edge(edge, MG.arcnum);
//
//	printf("the result of Kruskal:");
//
//	Kruskal_MG(MG, edge);
//
//
//
//	return EXIT_SUCCESS;
//
//}
