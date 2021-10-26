#include <iostream>
using namespace std;
int main()
{
    int count = 0;
    int i = 0;
    cin >> i;
    while (i != 1)
    {
        if (i % 2 == 0)
        {
            i /= 2;
        }
        else
        {
            i = (3 * i + 1) / 2;
        }
        count++;
    }
     cout << count << endl;
     return 0;
}