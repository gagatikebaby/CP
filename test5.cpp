#include<iostream>
#include<string>

class Base{
    public:
    Base();
    ~Base();
    void dosomething();

};

class subclass : public Base
{
    public:
    subclass();
    ~subclass();
}; 

Base::Base()
{
    std::cout<<"进入基类构造器。。。。\n\n";
    std::cout<<"我在基类构造器里边干了某些事...\n\n";
}
Base::~Base()
{
    std::cout << "进入基类解析器。。。\n";
    std::cout<<"我在基类析构器里边甘露某些事\n";
}

void Base::dosomething()
{
    std::cout << "我干了某些事。。。\n\n";
}

subclass::subclass()
{
    std::cout<<"进入子类构造器。。。\n";
    std::cout<<"为在子类构造器dosomething\n\n";
}
subclass::~subclass()
{
    std::cout<<"进入子类的西枸杞。。、\n";
    std::cout<<"dosomething。。。\n\n";
}

int main()
{
    subclass sub;
    sub.dosomething();

    std::cout  << "END\n";

}