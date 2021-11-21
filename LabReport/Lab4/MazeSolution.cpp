/*
迷宫问题。假设迷宫由m行n列构成，有一个入口和一个出口，入口坐标为（1，1），出口坐标为（m，n），
试设计并验证以下算法：找出一条从入口通往出口的路径，或报告一个“无法通过”的信息。
(1) 用C语言实现顺序存储结构上队列的基本操作，然后利用该队列的基本操作找出迷宫的一条最短路径。
(2) 设计一个二维数组MAZE[m+2][n+2]表示迷宫，数组元素为0表示该位置可以通过，数组元素为1表示该位置不可以通行。
MAZE[1][1]、MAZE[m][n]分别为迷宫的入口和出口。
(3) 输入迷宫的大小m行和n列，动态生成二维数组；由随机数产生0或1，建立迷宫，注意m*n的迷宫需要进行扩展，扩展部分的元素设置为1，
相当于在迷宫周围布上一圈不准通过的墙。
(4) 要求输出模拟迷宫的二维数组；若存在最短路经，则由出口回溯到入口（出队列并利用栈实现），再打印从入口到出口的这条路径，
例如(1,1)，……，(i,j)，……，(m,n)；若没有路径，则打印“No path!”。
(5) 迷宫的任一位置(i,j)上均有八个可以移动的方向，用二维数组Direction存放八个方向上的位置偏移量。
Direction[8][2]={{0,1},{1,1},{0,-1},{-1,-1},{1,1},{0,-1},{-1,-1},{0,1}};
(6) 为避免出现原地踏步的情况为了标志已经通过的位置，采用一个标志数组MARK[m+2][n+2]，初值均为0，在寻找路径的过程中，
若通过了位置(i,j)，则将MARK[i][j]置为1。
(7) 为了记录查找过程中到达位置(i,j)及首次到达(i,j)的前一位置(i_pre,j_pre)，需要记住前一位置(i_pre,j_pre)在队列中的序号pre，
即队列中数据元素应该是一个三元组(i,j,pre)。
(8) 搜索过程简单描述如下：将入口MAZE[1][1]作为第一个出发点，依次在八个方向上搜索可通行的位置，将可通行位置(i,j,pre)入队，
形成第一层新的出发点，然后依次出队，即对第一层中各个位置分别搜索它所在八个方向上的可通行位置，形成第二层新的出发点，…，
如此进行下去，直至达到出口MAZE[m][n]或者迷宫所有位置都搜索完毕为止。
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef struct Coordinate 
{
    int x, y; //方块坐标
    //int pre; //前一位置在队列中的序号
}Point;

int **maze = NULL;
int direction[8][2] = {{0,1},{1,1},{0,-1},{-1,-1},{1,1},{0,-1},{-1,-1},{0,1}};

void printPath(queue<Point> q)
{
    int path_X, path_Y;
    while(!q.empty())
    {
        path_X = q.front().x;
        path_Y = q.front().y;
        q.pop();
        cout << "(" << path_X << "," << path_Y << ") ";
    }
}

bool findPath(int startX, int startY, int endX, int endY)
{
    int x, y, pre;
    Point p; 
    queue<Point> q, resQ;
    int rear = 0, front = 0;
    p.x = startX;
    p.y = startY;
    q.push(p);
    maze[startX][startY] = -1;

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        resQ.push(p);
        x = p.x, y = p.y;
        if(x == endX && y == endY)
        {
            printPath(resQ);
            return true;
        }
        int dir = -1;
        int i, j;
        while(dir < 8)
        {
            dir++;
            switch(dir) //顺时针遍历各节点
            {
                case 0: i = x - 1;     j = y; break;
                case 1: i = x - 1; j = y + 1; break;
                case 2: i = x;     j = y + 1; break;
                case 3: i = x + 1; j = y + 1; break;
                case 4: i = x + 1;     j = y; break;
                case 5: i = x + 1; j = y - 1; break;
                case 6: i = x;     j = y - 1; break;
                case 7: i = x - 1; j = y - 1; break;
            }
            if(maze[i][j] == 0)
            {
                p.x = i; p.y = j;// p.pre = 0;
                q.push(p);
                maze[i][j] = -1;
            }
        }
    }
    return false;
}

int **createRandomMaze(int m, int n)
{
    int **maze;
	srand((unsigned)time(NULL));
    maze = (int**)malloc((m + 2) * sizeof(int *));
    for (int i = 0; i < m + 2; i++)
    {
        maze[i] = (int *)malloc((n + 2) * sizeof(int));
    }
    for(int i = 0; i < m + 2; i++)
    {
        for(int j = 0; j < n + 2; j++)
        {
            if(i == 0 || j == 0 || i == m + 1 || j == n + 1)
                maze[i][j] = 1;
            else
                maze[i][j] = (rand() % 2);
        }
    }
    maze[1][1] = 0;
    maze[m][n] = 0;
    return maze;
}

void outputMaze(int m, int n, int **maze)
{
    for(int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m, n;    
    cout << "请输入迷宫行数: ";
    cin >> m;
    cout << "请输入迷宫列数: ";
    cin >> n;
    maze = createRandomMaze(m, n);
    int mark[m + 2][n + 2] = {0};
    outputMaze(m, n, maze);
    cout << "***********************" << endl;
    if(!findPath(1, 1, m, n))
        cout << "No path found." << endl;
    return 0;
}

