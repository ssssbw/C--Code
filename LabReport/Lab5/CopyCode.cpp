#include <iostream>
#include<malloc.h>
#include<stdio.h>
#define SMAX 1000

using namespace std;

typedef struct
{
    int i,j;          //储存非零元素的行和列信息
    int  v;            //非零元素的值
} SPNode;       //定义三元组类型

typedef struct
{
    int row,col,notZero; //矩阵的行、列和非零元素的个数
    SPNode data[SMAX]; //三元组表
} SPMatrix;

void printMatrix(SPMatrix m);

SPMatrix createMatrix()
{
    cout<<"enter row and col and notZero"<<endl;
    int row,col, notZero;
    cin>>row >>col >>notZero;
    SPMatrix matrix;
    matrix.row = row;
    matrix.col = col;
    matrix.notZero = notZero;


    for(int k = 1; k <= notZero; k++)
    {
        cout <<"enter each row and col and value"<<endl;
        cin >> matrix.data[k].i >>matrix.data[k].j>>matrix.data[k].v;
    }

    cout <<"三元组："<<endl;
    for(int k = 1; k <= notZero; k++)
    {
        cout <<"(("<<matrix.data[k].i<<"," << matrix.data[k].j<<")"<<matrix.data[k].v<<"))"<<endl;
    }
//    printMatrix(matrix);
    return matrix;
}

void printMatrix(SPMatrix m)
{

    int row = m.row;
    int col = m.col;
    int show[row][col]= {0};

    //初始化矩阵
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            show[i][j]=0;
        }
    }

    for(int k=1; k<=m.notZero; k++)
    {
        show[m.data[k].i-1][m.data[k].j-1] = m.data[k].v;
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<show[i][j]<<" ";
        }
        cout<<endl;
    }
}

SPMatrix add(SPMatrix m1,SPMatrix m2)
{

    if(m1.row!=m2.row || m1.col!=m2.col)
    {
        cout<<"wrong"<<endl;
        return m1;
    }

    int flag = 0;
    int num = m1.notZero;
    int m;
    for(int k = 1; k <= num; k++)
    {
        for(m = 1; m <= m2.notZero; m++)
        {
            if(m1.data[k].i == m2.data[m].i && m1.data[k].j == m2.data[m].j)
            {
                m2.data[k].v += m1.data[m].v;
                flag = 1;
                break;
            }

        }
        if(flag ==0) //当前位置m2和m1未重合
        {
            m2.notZero++;
            m2.data[m2.notZero] = m1.data[k];
        }
        flag = 0;
    }

    return m2;
}
SPMatrix sub(SPMatrix m1,SPMatrix m2)
{

    if(m1.row!=m2.row || m1.col!=m2.col)
    {
        cout<<"wrong"<<endl;
        return m1;
    }

    int flag = 0;
    int num = m1.notZero;
    int m;
    for(int k = 1; k <= num; k++)
    {
        for(m = 1; m <= m2.notZero; m++)
        {
            if(m1.data[k].i == m2.data[m].i && m1.data[k].j == m2.data[m].j)
            {
                m2.data[k].v -= m1.data[m].v;
                flag = 1;
                break;
            }

        }
        if(flag ==0) //当前位置m2和m1未重合
        {
            m2.notZero++;
            m2.data[m2.notZero] = m1.data[k];
            m2.data[m2.notZero].v = -m1.data[k].v;
        }
        flag = 0;
    }

    return m2;
}
SPMatrix numMul(SPMatrix m)
{
    int num ;
    cout <<"输入数乘的数："<<endl;
    cin >> num;
    for(int k = 1; k <= num; k++)
    {
        m.data[k].v *= num;
    }

    return m;
}

int isExist(SPMatrix m,SPNode a){
    for(int i=1;i<=m.notZero;i++)
        if(m.data[i].i == a.i &&m.data[i].j == a.j)
            return i;
    return 0;
}
SPMatrix Mul(SPMatrix m1,SPMatrix m2)
{
    if(m1.col != m2.row)
    {
        cout<<"wrong"<<endl;
        return m1;
    }
    SPMatrix result;
    result.row = m1.row;
    result.col = m2.col;
    result.notZero = 0;//初始化
    SPNode data[m1.notZero+m2.notZero];
    int n = 0;

    for(int k = 1; k <= m1.notZero; k++)
    {
        for(int m = 1; m <= m2.notZero; m++)
        {
            if(m1.data[k].j == m2.data[m].i)
            {
                data[n].v = m1.data[k].v*m2.data[m].v;
                data[n].i = m1.data[k].i;
                data[n].j = m2.data[m].j;
                n++;
                continue;
            }

        }
    }
    int flag = 0;
    for(int k =0;k<n;k++){

        flag = isExist(result,data[k]);
        if(flag>0){
            result.data[flag].v+=data[k].v;
        }
        else{
            result.notZero++;
            result.data[result.notZero] = data[k];
        }
    }
    return result;
}


int main()
{
    int num = 0;
    do
    {
        cout<<"***********************************\n";
        cout<<"*              菜单                *\n";
        cout<<"*          1.矩阵相加               *\n";
        cout<<"*          2.矩阵相减               *\n";
        cout<<"*          3.矩阵相乘               *\n";
        cout<<"*          4.矩阵数乘               *\n";
        cout<<"*          6.退出                  *\n";
        cout<<"***********************************\n";
        cin>>num;
        if(1 == num|| 2 == num || 3 == num)
        {
            SPMatrix m1 = createMatrix();
            SPMatrix m2 = createMatrix();
            cout<<"两矩阵为"<<endl;
            printMatrix(m1);
            cout<<endl;
            printMatrix(m2);
            switch(num)
            {
            case 1:
            {
                if(m1.col!=m2.col || m1.row!=m2.row)
                {
                    cout<<"行列不同"<<endl;
                }
                else{
                    cout<<"结果为："<<endl;
                    printMatrix(add(m1,m2));
                }
                break;
            }
            case 2:
            {

                if(m1.col!=m2.col || m1.row!=m2.row)
                {
                    cout<<"参数错误"<<endl;
                }
                else{
                    cout<<"结果为："<<endl;
                    printMatrix(sub(m1,m2));
                }
                break;

            }
            case 3:
            {
                if(m1.col!=m2.row)
                {
                    cout<<"参数错误"<<endl;
                }
                else{
                    cout<<"结果为："<<endl;
                    printMatrix(Mul(m1,m2));
                }
                break;
            }
            default:
                break;
            }
        }
        else if(4 == num)
        {
            int number = 1;
            cout<<"请输入矩阵"<<endl;
            SPMatrix m  = createMatrix();
            cout<<"请输入数值"<<endl;
            cin>>number;
            cout<<"矩阵为："<<endl;
            printMatrix(m);
            printMatrix(numMul(m));
        }
        cout<<"按回车继续....";
        getchar();
        getchar();
        system("cls");
    }while(1 == num|| 2 == num || 3 == num ||4 == num);
    return 0;
}