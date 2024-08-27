#include<iostream>

#include<string>

class Pet{
    public:
    Pet(std::string theName);       //析构函数、构造函数要和类名一样，不用声明数据类型如int，double
    ~Pet();

    static int getcount();     //这是一个接口
protected:
std::string name;

private:
static int count;    //statci修饰之后，现在是全局变量了，静态成员是所有对象共享的，类里别的成员也能访问静态成员
};

class Dog :public Pet{
    public:
    Dog(std::string theName);
};

class Cat:public Pet{
public:
Cat(std::string theName);            
};

int Pet::count = 0;

Pet::Pet(std::string theName)
{
     name = theName;     //这里不能改成theName = name, 改的话name就是空的，不会输出.
    count++;

    std::cout << "一只宠物出生了，名字叫做： " << name <<"\n";
}

Pet::~Pet()
{
    count--;
    std::cout << name <<"die!!\n";
}

int Pet::getcount()
{
    return count;
}

Dog::Dog(std::string theName) : Pet(theName)
{
    std::cout<< "This: "<< this <<"\n";
}

Cat::Cat(std::string theName) : Pet(theName)
{

}

int main()
{
    Dog dog("Tom");
    Cat cat("Jerry");
std::cout << "dag:  " << &dog <<"\n";
    std::cout << "\n已经诞生了"<<Pet::getcount() << "只宠物！\n\n";
    {
        Dog dag_2("Tom_2");
        Cat cat_2("Jerry_2");

        std::cout << "\n现在呢，已经诞生了"<< Pet::getcount() << "只宠物！\n\n";
    }
    std :: cout << "\nAnd you're back to "<< Pet::getcount()<<"Pets!\n\n";
    return 0;
}

//this 保存着对象本身的地址