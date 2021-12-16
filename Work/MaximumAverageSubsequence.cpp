/*************
 *  至少L长的最大平均子序列 (10 分)
 *给定一个长度为n的正整数序列A。求一个平均数最大的，长度不小于L的子序列
 */

#include <iostream>
using namespace std;
int a[100001] = {0};
int n = 0, l = 0;

double solute(int *a, int n, int l) 
{
    double result = 0;
    double maxResult = result;
    for(int i = 0; i <= n - l; i++)
    {
        for(int j = i; j < l + i; j++)
        {
            result += a[j]; 
        }
        result = result * 1.0 / l ;
        if(result > maxResult)
        {
            maxResult = result;
        }
        result = 0;
    }
    return maxResult;
}

int main()
{
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    double result = solute(a, n, l) * 1000;
    printf("%.0f", result);
    return 0;
}