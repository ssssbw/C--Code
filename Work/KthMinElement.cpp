#include <iostream>
#include <algorithm>
using namespace std;

int a[1000000];
int n = 0;
int num = 0;

// int binarySearch(int *a, int num, int n)
// {
//     int left = 0, right = n - 1, mid = 0;
//     while (left <= right)
//     {   
//         mid = left + ((right - left) >> 1);
//         if(a[mid] == num) 
//             return mid;
//         if(a[mid] > num) 
//             right = mid - 1;
//         else 
//             left = mid + 1;
//     }
//     return -1;
// }

int main()
{
    scanf("%d", &n);
    scanf("%d", &num);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    //int size = unique(a, a + n) - a;
    //int index = binarySearch(a, num, size);
    printf("%d", a[num - 1]);
    return 0;
}