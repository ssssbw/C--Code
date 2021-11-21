/*
1.(必做题) 设计并实现稀疏矩阵运算器。
(1) 以三元组顺序表存储稀疏矩阵，实现两个矩阵的相加、相减与转置。
(2) 根据屏幕菜单的选择，可以进行稀疏矩阵的相加、相减与转置，且能进行输入数据出错的处理，
例如参与相加运算的两个矩阵行数和列数不同，等等。
(3) 矩阵的输入、输出均为矩阵形式。
*/

#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 256

typedef int Status;
typedef struct
{
    int i;
    int j;
    int v;
}Matrix;

typedef struct
{
    int Rows;
    int Cols;
    int Nums;
    Matrix arr[100];
}SpMatrix;

int inputMatrix(SpMatrix &m);
int outputMatrix(SpMatrix m);
int matrixAddition(SpMatrix M, SpMatrix N, SpMatrix& Q);
int matrixSubtraction(SpMatrix M, SpMatrix N, SpMatrix& Q);
int matrixTranspostion(SpMatrix A, SpMatrix& B);

Status inputMatrix(SpMatrix& M)    //矩阵的创建
{
	printf("行数:");
	scanf("%d", &M.Rows);
	printf("列数:");
	scanf("%d", &M.Cols);
	printf("非零元个数:");
	scanf("%d", &M.Nums);
	printf("按行优先依次输入元素的行值、列值、数值:\n");
	int i = 0;
	while (i < M.Nums)
	{
		scanf("%d%d%d", &M.arr[i].i, &M.arr[i].j, &M.arr[i].v);
		i++;
	}
	return OK;
}

Status outputMatrix(SpMatrix M)    //矩阵的输出
{
	if (M.Rows == 0) return ERROR;
	int cnt = 0;
	for (int i = 0; i < M.Rows; i++)
	{
		for (int j = 0; j < M.Cols; j++)
		{
			if (cnt < M.Nums && M.arr[cnt].i == i && M.arr[cnt].j == j)
			{
				printf("%d  ", M.arr[cnt].v);
				cnt++;
			}
			printf("0  ");
		}
		printf("\n");
	}
	return OK;
}

Status matrixAddition(SpMatrix M, SpMatrix N, SpMatrix& Q)    //矩阵相加
{
	if (M.Cols != N.Cols || M.Rows != N.Rows) return ERROR;
	Q.Cols = M.Cols;
	Q.Rows = M.Rows;
	int mi = 0;
	int ni = 0;
	int i = 0;
	while (mi != M.Nums && ni != N.Nums)
	{
		if (M.arr[mi].i == N.arr[ni].i && M.arr[mi].j == N.arr[ni].j)
		{
			Q.arr[i].i = M.arr[mi].i;
			Q.arr[i].j = M.arr[mi].j;
			Q.arr[i].v = M.arr[mi].v + N.arr[ni].v;
			i++;
			mi++;
			ni++;
		}
		if (M.arr[mi].i < N.arr[ni].i)
		{
			Q.arr[i].i = M.arr[mi].i;
			Q.arr[i].j = M.arr[mi].j;
			Q.arr[i].v = M.arr[mi].v;
			i++;
			mi++;
		}
		if (M.arr[mi].i == N.arr[ni].i && M.arr[mi].j < N.arr[ni].j)
		{
			Q.arr[i].i = M.arr[mi].i;
			Q.arr[i].j = M.arr[mi].j;
			Q.arr[i].v = M.arr[mi].v;
			i++;
			mi++;
		}
		else
		{
			Q.arr[i].i = N.arr[ni].i;
			Q.arr[i].j = N.arr[ni].j;
			Q.arr[i].v = N.arr[ni].v;
			i++;
			ni++;
		}
	}
	while (mi < M.Nums)
	{
		Q.arr[i].i = M.arr[mi].i;
		Q.arr[i].i = M.arr[mi].j;
		Q.arr[i].v = M.arr[mi].v;
		i++;
		mi++;
	}
	while (ni < N.Nums)
	{
		Q.arr[i].i = N.arr[ni].i;
		Q.arr[i].j = N.arr[ni].j;
		Q.arr[i].v = N.arr[ni].v;
		i++;
		ni++;
	}
	Q.Nums = i;
	return OK;
}

Status matrixSubtraction(SpMatrix M, SpMatrix N, SpMatrix& Q)    //矩阵相减
{
		if (M.Cols != N.Cols || M.Rows != N.Rows) return ERROR;
		Q.Cols = M.Cols;
		Q.Rows = M.Rows;
		int mi = 0;
		int ni = 0;
		int i = 0;
		while (mi != M.Nums && ni != N.Nums)
		{
			if (M.arr[mi].i == N.arr[ni].i && M.arr[mi].j == N.arr[ni].j)
			{
				Q.arr[i].i = M.arr[mi].i;
				Q.arr[i].j = M.arr[mi].j;
				Q.arr[i].v = M.arr[mi].v - N.arr[ni].v;
				i++;
				mi++;
				ni++;
			}
			if (M.arr[mi].i < N.arr[ni].i)
			{
				Q.arr[i].i = M.arr[mi].i;
				Q.arr[i].j = M.arr[mi].j;
				Q.arr[i].v = M.arr[mi].v;
				i++;
				mi++;
			}
			if (M.arr[mi].i == N.arr[ni].i && M.arr[mi].j < N.arr[ni].j)
			{
				Q.arr[i].i = M.arr[mi].i;
				Q.arr[i].j = M.arr[mi].j;
				Q.arr[i].v = M.arr[mi].v;
				i++;
				mi++;
			}
			else
			{
				Q.arr[i].i = N.arr[ni].i;
				Q.arr[i].j = N.arr[ni].j;
				Q.arr[i].v = -N.arr[ni].v;
				i++;
				ni++;
			}
		}
		while (mi < M.Nums)
		{
			Q.arr[i].i = M.arr[mi].i;
			Q.arr[i].i = M.arr[mi].j;
			Q.arr[i].v = M.arr[mi].v;
			i++;
			mi++;
		}
		while (ni < N.Nums)
		{
			Q.arr[i].i = N.arr[ni].i;
			Q.arr[i].j = N.arr[ni].j;
			Q.arr[i].v = -N.arr[ni].v;
			i++;
			ni++;
		}
		Q.Nums = i;
		return OK;
}

Status matrixTranspostion(SpMatrix A, SpMatrix& B)
{
	B.Rows = A.Cols;
	B.Cols = A.Rows;
	B.Nums = A.Nums;

	int rowStart[MAXSIZE];
	int rowNum[MAXSIZE];
	int k = 0;
	int p = 0;
	if (A.Nums > 0)
	{
		//第一步：统计A中每列非零元素个数
		for (k = 0; k < A.Cols; k++)    rowNum[k] = 0;    //rowNums数组的初始化
		for (p = 0; p < A.Nums; p++)    rowNum[A.arr[p].j]++;    //统计A中每列（即B中每行）非零元素个数
		//第二步：计算B中每行三元组的起始位置
		rowStart[0] = 0;
		for (k = 1; k < A.Cols; k++)
			rowStart[k] = rowStart[k - 1] + rowNum[k - 1];
		for (p = 0; p < A.Nums; p++)
		{
			int q = rowStart[A.arr[p].j];
			B.arr[q].i = A.arr[p].j;
			B.arr[q].j = A.arr[p].i;
			B.arr[q].v = A.arr[p].v;
			rowStart[A.arr[p].j]++;
		}
	}
	return OK;
}

int main()
{
    int select;
    SpMatrix m ,n ,q;
    SpMatrix a, b;
    while (true)
    {
        cout << "**************************" << endl;
        cout << "* 1. 输入稀疏矩阵(三元组形式)" << endl;
        cout << "* 2. 矩阵相加" << endl;
        cout << "* 3. 矩阵相减" << endl;
        cout << "* 4.矩阵转置" << endl;
        cout << "* 0.程序结束" << endl;
        cout << "**************************" << endl;

        cin >> select;
        switch(select)
        {
            case 1: inputMatrix(m);inputMatrix(n);break;
            case 2: matrixAddition(m, n, q);outputMatrix(q);break;
            case 3: matrixSubtraction(m, n, q);outputMatrix(q);
            case 4: inputMatrix(a);matrixTranspostion(a,b);outputMatrix(b);break;
            case 0:default: exit(0);    
        }
    }
    return 0;
}