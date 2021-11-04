#include <iostream>
#include <stdlib.h>
using namespace std;
void sort(int arr[], int num)
{
	int i, j, temp;
	for(i = 0; i < num - 1; i++)
		for(j = 0; j < num - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}			
		}
}

int main()
{
	int arr[1000], num;
	cin >> num;
	for(int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	sort(arr, num);
	for(int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
