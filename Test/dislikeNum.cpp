#include<iostream>
using namespace std;
int main()
{
    int n, count = 0;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        if (((num % 10) - (num  / 10 % 10) - (num / 100 % 10) - (num / 1000)) > 0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
} 

