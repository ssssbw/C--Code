#include <stdio.h>
#include <string.h>
#define MAX 1000
int main()
{
    int i, len;
    char str[MAX];
    while (gets(str))
    {
        len = strlen(str);  
        for (i = 0; i < len; i++)
        {
            if (str[i] <= 'Z' && str[i] >= 'A')
            {
                str[i] = char (str[i] + 32);
            } 
        }
        puts(str);
    }
    return 0;
}