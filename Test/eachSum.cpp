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
    int eachNum[3] = {0};
    int i = 2;
    for (; i >= 0; i--)
    {
        eachNum[i] = sum % 10;
        sum /= 10;
    }
    string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (i = 0; i < 2; i++)
    {
        if(eachNum[i] == 0) continue;
        cout << num[eachNum[i]] << " ";
    }
    cout << num[eachNum[i]];
    return 0;
}
//以上代码不能ac,检测点二出现问题
//以下是ac代码
/*
#include <stdio.h>

int main()
{
    int sum = 0;
    char c, *pinyins[] = {"ling", "yi", "er", "san", "si",
                          "wu", "liu", "qi", "ba", "jiu"};

    while((c = getchar()) != '\n')
        sum += c - '0';

    if(sum / 100)                           
        printf("%s ", pinyins[sum / 100]);
    if(sum / 10)                            
        printf("%s ", pinyins[sum / 10 % 10]);
    printf("%s", pinyins[sum % 10]);        

    return 0;
}

*/