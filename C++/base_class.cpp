#include<iostream>

#include<string>
class Animal
{
    public:
    std::string mouth;
    std::string name;
    Animal(std::string theName);
    void eat();
    void sleep();
    void drool();
};
class Pig:public Animal
{
    public:
    void climb();
    Pig(std::string theName);
    void eat();
  
};

class Turtle : public Animal
{
    public:
    void swim();
    Turtle(std::string theName);
    void eat();
};

Animal::Animal(std::string theName)
{
    name = theName;
}

void Animal::eat()
{
    std::cout<<"I can eat everyday!"<<std::endl;
}

void Animal::sleep()
{
    std::cout<<"I can Sleep everyday!"<<std::endl;
}

void Animal::drool()
{
    std::cout<<"I can drool everyday!"<<std::endl;
}                                                       //父类结束

Pig::Pig(std::string theName):Animal(theName)
{

}

void Pig::climb()
{
    std::cout<<"我是子类！！！！！！！！！"<<std::endl;
}

void Pig::eat()
{
    Animal::eat();
    std::cout<<name<<"正在吃鱼。。。\n";
}

Turtle::Turtle(std::string theName):Animal(theName)
{

}

void Turtle::swim()
{
    std::cout<<"为也是子类!"<<std::endl;
}
void Turtle::eat()
{
    Animal::eat();
    std::cout<<name<<"正在吃鱼。。。\n";
}

int main()
{
    
    Pig B("wocao");   //这里面不写参数会提示没有默认的构造函数，因为只有默认的构造函数才能不带参数
    Turtle C("原来如此");
   Animal D("!!!");
   
    B.climb();
    B.drool();
    C.swim();
    B.eat();
    C.eat();
    D.eat();
    

return 0;
}
