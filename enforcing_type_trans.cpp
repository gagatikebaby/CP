#include<iostream>
#include<string.h>
using namespace std;
class Company
{
    public:

    Company(string theName,string product);
    virtual void printInfo();
    
    protected:
    string name;
    string product;
};

class Techcompany : public Company
{
    public:
    Techcompany(string theName, string product);
    void printInfo();
};

Company::Company(string theName, string product)
{
    this->name = theName;
    this->product = product;
}

void Company :: printInfo()
{
    cout <<"The company name is " << name << ", product is "<<product <<endl;
} 

Techcompany::Techcompany(string theName, string product) : Company(theName,product)  //继承于构造函数，这里是使用了，不是声明函数，所以不用string修饰了
{

}

void Techcompany:: printInfo()
{
    cout << name <<" 公司大量生产"<<product <<" 产品!"<<endl;

}


int main()
{
    Company *company = new Techcompany("Apple","Iphone"); //用Company声明一个变量
    
    Techcompany *techcompany = (Techcompany *)company;//将company强制转换为 Techcompany 指针类型，将指针设置为地址 company 

    techcompany->printInfo();

    delete company;

    company = NULL;
    techcompany = NULL;

    return 0;
}