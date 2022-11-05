#include <iostream>  //此程序出的问题：两个数组没有初始化，

using namespace std;
#define N 100
class Data
{

public:
    char s[N];

    void Output_func(char str[]);
};
void Data::Output_func(char str[])
{
    int num[N]={0};
    int i=0;
    int j = 0;
    for (i; i < N && str[i] != 0; i++)       //str[i]!=0,表示字符串不结束
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            j = str[i]-'A';
            num[j]++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            j = str[i]-'a';
            num[j]++;
        }
        else
        {
            printf("What you input is not a valid string,error--> %c\n", s[i]);

        
        }
        
    }
    printf("The result is as follows:\n");

    char s[26] ;
   for(int n =0;n<26;n++)
   {
         s[n] =97+n;
   }          //初始化字符数组

    for(int k = i -1;k>=0;k--)
    {
        for(int g = 0;g < k;g++)
        {
            if(num[g]<num[g+1])
            {
                swap(num[g],num[g+1]);
                swap(s[g],s[g+1]);
                
            }
        }
    }        //统计输入

   for(int i =0;i<26;i++)
    {
        if (num[i] != 0)
            printf("%c----%d\n", s[i], num[i]);

    }
    
}
int main()
{
    Data Out;
    cin >> Out.s;
    Out.Output_func(Out.s);
    return 0;
}
