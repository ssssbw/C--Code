#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

#define HASHSIZE 17
typedef struct Node
{
    int data;
    Node *next;
}HashList;

HashList list[HASHSIZE];


