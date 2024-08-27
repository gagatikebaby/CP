#include<iostream>
#include<string>

int main()
{
    int *pointer = new int; //定义一个指向整型的指针，用new开辟一个整形的内存
    *pointer = 100; //给new出来的地址空间赋值，赋值为110

    std::cout<<*pointer<<"\n";
    delete pointer;
}