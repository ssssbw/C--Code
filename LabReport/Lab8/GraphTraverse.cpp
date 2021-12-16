#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

#define MAX_VERTEX_NUM 20	 //图的邻接表存储表示
typedef int InfoType;
typedef char VertexType;

bool visitedBFS[MAX_VERTEX_NUM] = {false}; //用于广度优先遍历的访问标记数组
bool visitedDFS[MAX_VERTEX_NUM] = {false}; //用于深度优先遍历的访问标记数组

typedef struct ArcNode
{
    int adjVex;	           //该弧所指向的顶点的位置
    struct ArcNode *nextArc;	 //指向下一条弧的指针
    InfoType info;	       //该弧权
}ArcNode;

typedef struct VNode 
{
    VertexType data;       	//顶点信息
    ArcNode *firstArc;	   //指向第一条依附该顶点弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct 
{
    AdjList vertices;
    int vexNum, arcNum; 	   //图的当前顶点数和弧数
    int kind; 	             //图的种类标志
}ALGraph;

void createGraph(ALGraph &graph)
{
    ArcNode *arc;
    cout << "请输入顶点数和边数: ";
    scanf("%d %d", &graph.vexNum, &graph.arcNum);
    cout << "请输入图的种类(0: 无向图, 1: 有向图): ";
    scanf("%d", &graph.kind);
    cout << "请输入点的信息: ";

    for (int i = 0; i < graph.vexNum; i++)
    {
        cin >> graph.vertices[i].data;
        graph.vertices[i].firstArc = NULL;
    }

    cout << "请输入边的信息: " << endl;
    for(int k = 0; k < graph.arcNum; k++)
    {
        int i, j, w;
        cin >> i >> j >> w;
        arc = (ArcNode *)malloc(sizeof(ArcNode));
        arc->adjVex = j;
        arc->info = w;
        arc->nextArc = graph.vertices[i].firstArc;
        graph.vertices[i].firstArc = arc;
        if(graph.kind == 0)
        {
            arc = (ArcNode *)malloc(sizeof(ArcNode));
            arc->adjVex = i;
            arc->info = w;
            arc->nextArc = graph.vertices[j].firstArc;
            graph.vertices[j].firstArc = arc; 
        }
    }
}

void DFS(ALGraph graph, int v)
{
    ArcNode *p;
    visitedDFS[v] = true;
    cout << graph.vertices[v].data << " ";
    p = graph.vertices[v].firstArc;
    while(p)
    {
        if(!visitedDFS[p->adjVex])
        {
            DFS(graph, p->adjVex);
        }
        p = p->nextArc;
    }
}

void BFS(ALGraph graph, int v)
{
    queue<int> q;
    int i;
    visitedBFS[v] = true;
    cout << graph.vertices[v].data << " ";
    ArcNode *p;
    q.push(v);
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        p = graph.vertices[i].firstArc;
        while(p)
        {
            if(!visitedBFS[p->adjVex])
            {
                cout << graph.vertices[p->adjVex].data << " ";
                visitedBFS[p->adjVex] = true;
                q.push(p->adjVex);
            }
            p = p->nextArc;
        }
    }
}

void PrintfGraphAdjList(ALGraph G)
{
    for(int i = 0; i < G.vexNum; i++)
    {
        ArcNode *p = G.vertices[i].firstArc;
        cout << G.vertices[i].data << '\t';
        while(p)
        {
            cout << p->adjVex << ' ' << p->info << '\t';
            p = p->nextArc;
        }
        cout << endl;
    }
}

int main()
{
    ALGraph graph1, graph2;
    createGraph(graph1);
    PrintfGraphAdjList(graph1);
    cout << "有向图的广度优先搜索: ";
    BFS(graph1, 0);

    cout << endl;
    createGraph(graph2);
    PrintfGraphAdjList(graph2);
    cout << "无向图的深度优先搜索: ";
    DFS(graph2, 0);
    return 0;
}