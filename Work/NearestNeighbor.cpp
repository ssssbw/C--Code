#include <iostream>
#include <cmath>
using namespace std;

int a[100000] = {0};
int num = 0, n = 0;

int search(int num, int n) 
{
    int left = 0, right = n - 1, mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(a[mid] < num) left = mid + 1;
        else right = mid - 1;
    }
    if(abs(a[left] - num) <= abs(a[right] - num)) return left;
    else return right; 
}

int main()
{
    scanf("%d %d", &n, &num);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int index = search(num, n);
    printf("%d", a[index]);
    return 0;
}