/***********
 * 实现哈希表的构造和查找算法，要求：用除留余数法构造哈希函数，
 * 分别采用二次探测再散列、链地址法解决冲突。
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

#define HASHSIZE 17
typedef struct
{
    int *elem;
    int count;
}HashTable;

int size = 0;

void initHashTable(HashTable *h)
{
    size =  HASHSIZE;
    h->count = size;
    h->elem = (int *)malloc(size * sizeof(int));
    if(!h->elem) exit(0);
    for (int i = 0; i < size; i++)
    {
        h->elem[i] = -1;
    }
}

int hash2(int key)
{
    return key % size;
}

bool searchHash(HashTable *h, int num)
{
    int cnt = 1;
    int index = hash2(num);
    int temp = index;
    bool isFind = true;
    while(h->elem[temp] != num)
    {
        if(h->elem[temp] == -1)
        {
            isFind = false;
            break;
        }
        int i = pow(-1, cnt + 1) * pow((int)(cnt + 1) / 2, 2);
        cnt++;
        temp = (index + i + size) % size; 
    }
    if(isFind)
        cout << "查找成功, 位置在哈希表中第" << temp + 1 << "个!" << endl;
    else
        cout << "查找失败!" << endl;
    return true;
}

bool insertHash(HashTable *h, int key)
{
    int cnt = 1;
    int index = hash2(key);
    int temp = index;
    while(h->elem[temp] != -1)
    {
        int i = pow(-1, cnt + 1) * pow((int)(cnt + 1) / 2, 2);
        cnt++;
        temp = (index + i + size) % size; 
    }
    h->elem[temp] = key;
    return true;
}

int main()
{
    HashTable h;
    initHashTable(&h);

    srand(unsigned(time(NULL)));
    int randNum;

    for(int i = 0; i < 13; i++)
    {
        randNum = rand() % 100;
        insertHash(&h, randNum);
    }

    for(int i = 0; i < size; i++)
    {
        cout << h.elem[i] << " ";
    }
    cout << endl;

    cout << "请输入要查找的数字: ";
    int num;
    cin >> num;

    searchHash(&h, num);

    return 0;
}