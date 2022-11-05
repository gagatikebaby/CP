#include<iostream>

int *newInt(int value);

int main()
{
    int *x = newInt(20);

    std::cout << *x;
    delete x;
    x = NULL;

    return 0;
}

int *newInt(int value)

{
    int *myInt = new int;  //在堆里面申请一块整形的内存
    *myInt = value;   //用* 解引用，赋值

    return myInt;   //返回地址,这里不能返回一个局部变量的指针，但是可以返回动态分配内存new的基地址
}