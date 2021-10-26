#include <iostream>
#include <cmath> 
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int i = abs(a - b) * 2;
        if(a > i || b > i || c > i)
        {
            cout << "-1" << endl;
        }
        else
        {
            if (c <= i / 2)
            {
                cout << c + i / 2 << endl;
            }
            else
            {
                cout << c - i / 2 << endl;
            }
        }
    }
    return 0;
}




