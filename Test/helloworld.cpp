#include<iostream>
using namespace std;
int sum=0;
 
int BinarySearch(int a[],const int &x,int n)
{
    int left = 0;
    int right = n-1;
    while (left <= right)
    {
        sum++;
        int middle = (left + right)/2;
        if(x == a[middle]) return middle;
        if(x > a[middle]) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
} 
 
int main()
{
    int n,a[1000],x,result;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>x;
    
    result = BinarySearch(a,x,n);
    cout<<result<<endl<<sum;
    return 0;
 
}