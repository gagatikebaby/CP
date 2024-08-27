#include <iostream>//模板函数是对参数的泛型

template <typename T>       //模板函数宏命令

void Swap(T &a, T &b);      //声明一个模板函数

int main()
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i,j = " << i << "," << j << ".\n";
    cout << "Using compiler_generated int swapper:\n";
    Swap(i, j);
    cout << "Now i,j = " << i << "," << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x,y= " << x << "," << j << ".\n";
    cout << "Using compiler_generates double Swaper:\n";
    Swap(x, y);
    cout << "Now x,y = " << x << "," << y << ".\n";
    return 0;
}

template <typename T>           //使用两次模板函数的定义
void Swap(T &a, T &b)            //定义模板函数 
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
