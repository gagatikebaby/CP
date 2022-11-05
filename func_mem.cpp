#include<iostream>
#include<memory>
using namespace std;
int *newInt(int value);

int main()
{
    
    auto_ptr<int> x (newInt(20));

   std::cout << *x;
  

    return 0;
}

int *newInt(int value)
{
    int *myInt = new int;
    *myInt = value;

    return myInt;
}