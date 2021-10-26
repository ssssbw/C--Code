#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
    public:
        string name;
        string number;
        int grade;
};

int main()
{
    int n;
    int i = 0;
    cin >> n;
    int count = n;
    Student *stu = new Student[n];
    while (count--)
    {
        cin >> stu[i].name >> stu[i].number >> stu[i].grade;
        i++;
    }
    int min = 0, max = 0;
    for (int j = 0; j < n; j++)
    {
        if(stu[max].grade < stu[j].grade) max = j;
        if(stu[min].grade > stu[j].grade) min = j;
    }
    cout << stu[max].name << " " << stu[max].number << endl;
    cout << stu[min].name << " " << stu[min].number << endl;
    delete[] stu;
    return 0;
}