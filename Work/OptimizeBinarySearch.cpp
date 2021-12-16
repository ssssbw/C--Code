#include <iostream>
#include <algorithm>
using namespace std;
int a[100000] = {0};
int n = 0;
int num = 0;

int binarySearch(int *a, int n, int num)
{
    int left = 0, right = n - 1, mid = 0;
    while (left <= right)
    {   
        mid = left + ((right - left) >> 1);
        if(a[mid] == num) 
            return mid;
        if(a[mid] > num) 
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return -1;
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &num);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    while (true)
    {
        if(num < a[0])
        {
            printf("-1 0");
            break;
        }
        else if(num > a[n - 1])
        {
            printf("%d %d", n - 1, n);
            break;
        }
        else if(binarySearch(a, n, num) < 0)
        {
            int left = binarySearch(a, n, num - 1);
            int right = binarySearch(a, n, num + 1);
            if(left && right)
            {   
                printf("%d %d", left, right);
                break;
            }
            else
            {
                left = binarySearch(a, n, num - 1);
                right = binarySearch(a, n, num + 1);
            }
        }
        else
        {
            printf("%d %d", binarySearch(a, n, num), binarySearch(a, n, num));
            break;
        }
    }
    return 0; 
}