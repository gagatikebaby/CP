#include<iostream>

void swapr(int &a, int &b);
void swapp(int *p, int *q);
void swapv(int a,int b);
int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;
    cout << "wallet1 = $"<<wallet1;
    cout << "wallet2 = $"<<wallet2 << endl;

    cout<<"using reference to swap contents:\n";
    swapr(wallet1,wallet2);
    cout << "wallet1 = $"<<wallet1;
    cout << "wallet2 = $"<<wallet2 << endl;

    cout<<"using pointers to swap contens again:\n";
    swapp(&wallet1,&wallet2);
    cout << "wallet1 = $"<<wallet1;
    cout << "wallet2 = $"<<wallet2 << endl;   

    cout<<"unsing value to passing "<<endl;
    swapv(wallet1,wallet2);
     cout << "wallet1 = $"<<wallet1;
    cout << "wallet2 = $"<<wallet2 << endl;
}

void swapr(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp; 
}

void swapp(int *p, int *q)
{
    int temp ;
     temp=*q ;
    *q = *p; //不能用q = p，地址相同了就是同一个东西了，只能让地址存的值相同
    *p = temp;
}

void swapv(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;
}