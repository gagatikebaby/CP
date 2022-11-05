#include<iostream>

using namespace std;

int main()
{
    
    int a = 5;
    int *p ;
    p = &a;
    int b = *p;

   cout<<"b value is "<<b<<endl;
cout<<"b address is "<<&b<<endl;

#if(0)
int *p = &a 是可以的 ， int*p;*p = &a; 是报错的
    return 0;

#endif
}