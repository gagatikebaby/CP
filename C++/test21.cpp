#include<iostream>

int main()
{
    /*
    int *x;
     x = new int[1000];
     */
    int *x = new int[1000];


    delete x;
    x = NULL;

    return 0;
}