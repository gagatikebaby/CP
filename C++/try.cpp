#include<iostream>
#include<climits>

unsigned long returnFactorial(unsigned short num) throw(const char *);

int main()
{
    unsigned short num = 0;
    std::cout<<"请输入一个整数: ";
    while (!(std::cin>>num)||(num<1))
    {
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout <<"请输入一个整数: ";

    }
    std::cin.ignore(100,'\n');

    try
    {
        unsigned long factorial = returnFactorial(num);
        std::cout << num <<"的阶乘值是 "<<factorial;
    }

    catch(const char *e){
        std::cout<<e;
    }
    return 0;
    
}

unsigned long returnFactorial(unsigned short num)throw(const char *)
{
    unsigned long sum = 1;
    unsigned long max = ULLONG_MAX;

    for(int i = 1; i <= num;i++)
    {
        sum *= i;
        sum /=i;
    }

    if(max < 1)
    {
        throw"基数太大，无法在计算机求出阶乘!\n";
    }
    else
    {
        return sum;
    }
}