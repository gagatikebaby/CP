#include<iostream>

using namespace std;
template<typename T>
void Swap(T &a,T &b);


int main()
{
    int a,b;
    cin >> a;
    cin >> b;
    cout<<"1----:"<<a<<".\n"
    <<"2----:"<<b<<".\n\n";
    Swap(a,b);
    cout<<"1----:"<<a<<".\n"
    <<"2----:"<<b<<".\n";
    return 0;
}

template<typename T>
void Swap(T &a,T &b)
{
    T temp;    //T代表实例化之后，具体的数据类型。

temp = b;

b = a;

a = temp;
}