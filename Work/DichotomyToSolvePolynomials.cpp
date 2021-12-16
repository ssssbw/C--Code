#include <iostream>
#include <cmath>
using namespace std;

double a3, a2, a1, a0;
double f(double x) 
{
    return (a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * pow(x, 1) + a0 * pow(x, 0));
}

int main()
{
    
    double a, b, mid;
    cin >> a3 >> a2 >> a1 >> a0;
    cin >> a >> b;
    if (b - a < 0.00001)
    {
        printf("%.2f", (a + b) / 2);
    }
    else
    {
        while(true)
        {
            mid = (a + b) / 2;
            if(f(mid) == 0)
            {
                printf("%.2f", mid);
                break;
            }
            else if(f(a) * f(mid) > 0)
                a = mid;
            else if(f(b) * f(mid) > 0)
                b = mid;
        }
    }
    return 0;
}