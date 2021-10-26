#include <stdio.h>
#define swap(a,b) {a = a + b; b = a - b; a = a - b;}

int main()
{
  int arr[12] = {1,1,1,1,2,2,2,2,7,8,8,9};
  int length = 12;
  for (int i = 0; i < length; i++) 
  {
    for (int j = i + 1; j < length; j++) 
    {
      if(arr[i] == arr[j])
      {
        for (int k = j; k < length - 1; k++)
        {
          arr[k] = arr[k + 1];
        }
        length--;
        j--;
      }
    }
  }

  for (int i = 0; i < length; i++) 
  {
    printf("%d\n", arr[i]);
  }
  return 0;
}


