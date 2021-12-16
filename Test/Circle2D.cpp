#include <iostream>
#include <cmath>
using namespace std;

class  Circle2D
{
private:
    double x, y;
    double radius;
public:
     Circle2D();
     Circle2D(double x, double y, double radius):x(x), y(y), radius(radius){}
    ~ Circle2D();
    double getX() const { return x;}
    double getY() const { return y;}
    double getRadius() const { return radius;}
    double getArea() const;
    double getPerimeter() const;
    bool containsPoint(double x, double y) const;
    bool containsCircle2D(const Circle2D& circle) const;
    bool overlaps(const Circle2D& circle) const;
};

 Circle2D:: Circle2D(/* args */)
{
    this->x = 0.0;
    this->y = 0.0;
    this->radius = 1.0;
}

 Circle2D::~ Circle2D()
{
}

double Circle2D::getArea() const
{
    return 3.1415926 * this->radius * radius;
}

double Circle2D::getPerimeter() const
{
    return 2 * 3.1415926 * this->radius;
}

bool Circle2D::containsPoint(double x, double y) const
{
    return (pow((x - this->x), 2) + pow((y - this->y), 2)) < pow(this->radius, 2);
}

bool Circle2D::containsCircle2D(const Circle2D& circle) const
{
    return (pow((circle.x - this->x), 2) + pow((circle.y - this->y), 2)) <= fabs(circle.radius - this->radius); 
}

bool Circle2D::overlaps(const Circle2D& circle) const
{
    return pow((circle.x-this->x),2) + pow((circle.y-this->y),2) > abs(circle.radius-this->radius) && pow((circle.x-this->x),2) + pow((circle.y-this->y),2) < circle.radius + this->radius;
}

void test()
{
    Circle2D c1(2, 2, 5.5);
    Circle2D c2(2, 2, 3.5);
    Circle2D c3(4, 5, 10.5);
    double c1Area, c1Perimeter;
    c1Area = c1.getArea();
    c1Perimeter = c1.getPerimeter();
    cout << c1Area << " " << c1Perimeter << endl;
    cout << "---------------------" << endl;
    cout << c1.containsPoint(3, 3) << endl;
    cout << c1.containsCircle2D(c2) << endl;
    cout << c1.overlaps(c3) << endl;
}

int main()
{
    test();
    return 0;
}