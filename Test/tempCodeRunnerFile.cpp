#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char arr[101] = "";
    cin >> arr;
    int n = 0;
    int sum = 0;
    while (arr[n] != '\0')
    {
        sum += (arr[n] - '0');
        n++;
    }
    int a, b, c;
    a = sum / 100;
    b = sum / 10 % 10;
    c = sum % 10;
    string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    cout << num[a] << " " << num[b] << " " << num[c];
    return 0;
}