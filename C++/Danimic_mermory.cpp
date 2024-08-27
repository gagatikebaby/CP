#include<iostream>
#include<string>

class Company
{
    
    public:
    Company(std::string theName);
    virtual void printInfo();

    protected:
    std::string name;
};

class TechCompany : public Company
{
    public:
    TechCompany(std::string theName, std::string product);
    virtual void printInfo();

    private:
    std::string product;
};    //class报错通常是忘了加；

Company::Company(std::string theName)
{
    name = theName;
}

void Company :: printInfo()
{
    std::cout << "这个公司名字是: "<<name<<".\n";
}



 TechCompany:: TechCompany(std::string theName, std::string product) : Company(theName)    //构造函数定义域别忘,构造函数不用加声明类型
{
    this->product = product;  //这里this指针表示的是基类techerCompany的首地址，使用场景为形参参数与成员函数变量名一样时
}

void TechCompany::printInfo()
{
    std::cout <<name <<"公司大量生产" << product<<"这款产品！\n";
}

int main()
{
    Company *company = new Company("Apple");
    company -> printInfo();

    delete company;
    company = NULL;

    Company *techcompany = new TechCompany("apple","IPhone");
    techcompany -> printInfo();

    delete techcompany;
    techcompany = NULL;
    return 0;
}