#include <iostream>
#include <string>

class Point
{
public:
    Point(int a, int b);

    void function2(int a, int b);

private:
    int x, y;
};

Point::Point(int a, int b)
{
    x = a;
    y = b;
    std::cout << "x =  " << x << "\n";
    std::cout << "y =  " << y << "\n";
}

void Point::function2(int a, int b)
{
    x = a;
    y = b;
    std::cout << "x =  " << x << "\n";
    std::cout << "y =  " << y << "\n";
}

int main()
{
    Point point(15, 20);
    point.function2(21, 33);
}