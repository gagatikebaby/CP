#include<iostream>

using namespace std;

int main()
{
    int *x = new int[10];
    x[1] = 45;

    cout<<x[1];
}