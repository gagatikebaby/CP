#include<iostream>
#include<string>


int main()
{
    int a = 1;
    
    int *p = NULL;
    p = &a;

  // int *p = &a;   //这里直接就是解引用 &a ， 等价于 p = &a , *p；

    std::cout << p;

    return 0;
}