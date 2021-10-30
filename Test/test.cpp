#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int number);
int reverse(int number);
bool isPrime(int number);

int main()
{
  int count = 0;
  for (int i = 2; count < 100; i++)
  {
    if (isPrime(i) && isPrime(reverse(i)) && !isPalindrome(i))
    {
      printf("%d ", i);
      count++;
      if (count % 10 == 0)
      {
        printf("\n");
      }
    }
  }
}
bool isPalindrome(int number)
{
  return reverse(number) == number;
}
int reverse(int number)
{
  int reverseNumber = 0;
  do
  {
    reverseNumber = reverseNumber * 10 + number % 10;
    number /= 10;
  } while (number > 0);
  return reverseNumber;
}
bool isPrime(int number)
{
  for (int i = 2; i <= sqrt(number); i++)
  {
    if (number % i == 0)
    {
      return false;
    }
  }
  return true;
}
