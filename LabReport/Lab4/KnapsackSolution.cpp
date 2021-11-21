/*
背包问题(Knapsack Problem)。
(1) 有n件物品和一个容量为V的背包，第i件物品的重量是w[i]，价值是v[i]，求解将哪些物品装入背包可使这些物品的重量总和不超过背包容量，且价值总和最大。
(2) 背包问题是一种组合优化的NP完全问题，问题的名称来源于如何选择最合适的物品放置于给定背包中。相似问题经常出现在商业、组合数学，计算复杂性理论、
密码学和应用数学等领域中。也可以将背包问题描述为决定性问题，即在总重量不超过W的前提下，总价值是否能达到V？它是在1978年由Merkel和Hellman提出的。
(3) 分别设计背包问题的递归算法和利用栈解决背包问题的非递归算法，分析比较两种算法的时间复杂度和空间复杂度。
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e4;
int weight[MAX] = {0}, value[MAX] = {0};
int res[MAX][MAX] = {0};
int item[MAX] = {0};

void solveKnapspack1(int vol, int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= vol; j++)
        {
            if(j < weight[i])
            {
                res[i][j] = res[i - 1][j];
            }
            else
            {
                res[i][j] = max(res[i - 1][j], res[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
}

int solveKnapspack2(int vol, int n)
{
    if(vol == 0 || n == 0)  return 0;
    else
    {
        for(int i = n; i >= 0; i--)
        {
            if(vol < weight[i])
            {
                item[i] = 0;
                return solveKnapspack2(vol, n - 1);
            }
            else
            {
                int res1 = solveKnapspack2(vol, n - 1);
                int res2 = solveKnapspack2(vol - weight[i], n - 1) + value[i];
                if(res1 > res2)
                {
                    item[i] = 0;
                    return res1;
                }
                else
                {
                    item[i] = 1;
                    return res2;
                }
            }
        }
    }
    return 0;
}

void backtrack(int n, int vol)
{
    if(n >= 0)
    {
        if(res[n][vol] == res[n - 1][vol])
        {
            item[n - 1] = 0;
            backtrack(n - 1, vol); 
        }
        else if(vol >= weight[n] && res[n][vol] == res[n - 1][vol - weight[n]] + value[n])
        {
            item[n - 1] = n;
            backtrack(n - 1, vol - weight[n]);
        }
        else n--;
    }
}

void inputAndInit(int vol, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "请输入第" << i << "件物品的重量和价值: ";
        cin >> weight[i] >> value[i];
    }
    weight[0] = 0, value[0] = 0; //初始化边界条件 
}

void outputRes(int vol, int n)
{
    for(int i = 0; i <= n; i++)
    {
        for (int j = 0 ; j <= vol; j++)
        {
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }
}

void outputItemAndBestSolution(int vol, int n)
{
    cout << "应装以下重量: ";
    for(int i = 0; i < n; i++)
    {
        if(item[i] != 0)
            cout << weight[item[i]] << "  ";
    }
    cout << endl << "其对应价格为: ";
    for(int i = 0; i < n; i++)
    {
        if(item[i] != 0)
            cout << value[item[i]] << "  ";
    }
    cout << endl;
    cout << "容量为" << vol << "的背包最多能装价值为" << res[n][vol] << " 的东西!" << endl;
}

void test1(int vol,int n)
{
    inputAndInit(vol, n);
    solveKnapspack1(vol, n);
    backtrack(n, vol);
    outputRes(vol, n);
    outputItemAndBestSolution(vol, n);
}

void test2(int vol,int n)
{
    inputAndInit(vol, n);
    int bestSolution = solveKnapspack2(vol, n);
    cout << "最优解为: " << bestSolution << endl;
}

int main()
{
    int vol, n;
    cout << "请输入背包的数量和物品件数: ";
    cin >> vol >> n;
    
    test1(vol, n);
    // test2(vol, n);
    return 0;
}