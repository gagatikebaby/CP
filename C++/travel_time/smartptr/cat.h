#ifndef CAT_H
#define CAT_H
#include<string>
#include<iostream>
class Cat
{
    public:
    Cat(std::string name);
    Cat() = default;
    ~Cat();

    void cat_info(){
        std::cout << "cat info name: "<<name<<std::endl;
    }
    
    std::string get_name() const{
        return name;
    }

    void set_name(const std::string &name)
    {
        this->name = name;
    }

    private:
    std::string name{"mini"};
};

#endif