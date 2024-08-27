#include<iostream>
#include<string.h>

using namespace std;
int main()
{   
    unsigned int i = 0;
    int *x = new int[i];  //x相当于10个整形变量数组的数组名
    
    cin >> i;
    for(int j = 0;j < i ;j++)
    {
        x[j] = j;
    }

    for(int j = 0;j<i;j++)
    {
        cout<<"x["<<j<<"] = "<<x[j]<<endl;
    }

    delete []x;
    return 0;

}