#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class T>
void selectionSort(T list[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        T min = list[i];
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if(min > list[j])
            {
                min = list[j];
                index = j;
            }
        }
        if(i != index)
        {
            list[index] = list[i];
            list[i] = min;
        }
    }
}

template<class T>
void printArray(const T list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

class Rational
{
    private:
        int num;//分子
        int den;//分母
    public:
        Rational(int x = 0, int y = 1):num(x), den(y){}
        void simplify();
        friend ostream& operator<<(ostream &out, Rational obj);
        Rational operator=(Rational);
        bool operator>(const Rational &obj);
        bool operator<(const Rational &obj);
        bool operator==(const Rational &obj);
        bool operator!=(const Rational &obj);
  
};

void Rational::simplify()
{
    int m,n,r;
    n=fabs(den);
    m=fabs(num);
    while(r=m%n)  // 求m，n的最大公约数
    {
        m=n;
        n=r;
    }
    den/=n;     // 化简
    num/=n;
    if (den<0)  // 将分母转化为正数
    {
        den=-den;
        num=-num;
    }
}

ostream &operator<<(ostream &out,Rational x)
{
    cout<<x.num<<'/'<<x.den;
    return cout;
}

// 分数比较大小
bool Rational::operator>(const Rational &c)
{
    int this_num,c_num,common_den;
    this_num=num*c.den;        // 计算分数通分后的分子，同分母为den*c.den
    c_num=c.num*den;
    common_den=den*c.den;
    if ((this_num-c_num)*common_den>0) return true;
    return false;
}
 
// 分数比较大小
bool Rational::operator<(const Rational &c)
{
    int this_num,c_num,common_den;
    this_num=num*c.den;
    c_num=c.num*den;
    common_den=den*c.den;
    if ((this_num-c_num)*common_den<0) return true;
    return false;
}
 
// 分数比较大小
bool Rational::operator==(const Rational &c)
{
    if (*this != c) return false;
    return true;
}

// 分数比较大小
bool Rational::operator!=(const Rational &c)
{
    if (*this>c || *this<c) return true;
    return false;
}

Rational Rational::operator=(Rational obj)
{
    Rational temp;
    temp.num = obj.num;
    temp.den = obj.den;
    num = temp.num;
    den = temp.den;
    return temp;
}


int main()
{
    int size = 20;
    int random1, random2;

    //生成100以内的随机数
    srand(unsigned(time(NULL)));
    int n = rand() % 100;

    Rational list[size];
    for(int i = 0; i < size; i++)
    { 
        random1 = rand() % 100;
        random2 = rand() % 100;
        list[i] = Rational(random1, random2);
        list[i].simplify();
    }
    
    cout << "before sort: " << endl;
    printArray(list, size);
    cout << "after sort: " << endl;
    selectionSort(list, size);
    printArray(list, size);

    return 0;
}