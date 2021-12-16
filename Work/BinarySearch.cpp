#include <iostream>
using namespace std;
int a[1001] = {0};

int binarySearch(int *a, int num, int n, int &cnt)
{
    int left = 0, right = n - 1, mid = 0;
    while (left <= right)
    {   
        cnt++;
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
    int n = 0, i = 0, x = 0;
    int cnt = 0;
    scanf("%d", &n);
    while (n--) 
    {
        scanf("%d", &a[i]);
        i++;
    }
    scanf("%d", &x);
    int index = binarySearch(a, x, i, cnt);
    printf("%d\n%d", index, cnt);
    return 0;
}