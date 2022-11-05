#include<iostream>
#include<string>

class Lovers{
    public:
    Lovers(std::string theName);
    void kiss(Lovers *lover);
    void ask(Lovers *lover, std::string something);
    protected:

    std::string name;
    friend class Others;
};

class Boyfriend: public Lovers
{
    public:
    Boyfriend(std::string theName);
};

class Girlfriend : public Lovers{
    public:
    Girlfriend(std::string theName);
};

class Others
{
    public:
    Others(std::string theName);

    void Kiss(Lovers *lover);

    protected:
    std::string name;
};

Lovers :: Lovers(std::string theName)
{
    name = theName;
}

void Lovers :: Kiss(Lovers *lover)
{
    std::cout << "This is KISS!!" <<lover->name <<"help me!"<< something <<std::endl;
}

void Lovers::ask(Lovers *lover, std::string something)
{
    std::cout << "boby" << lover-> name << "help!!"<<something <<std::endl;
}

Boyfriend :: Boyfriend(std :: string theName) : Lovers(theName)
{

}

Girlfriend::Girlfriend(std :: string theName)
{

}

Others :: Kiss(Lovers *lover)
{
    std::cout << name <<"qkiss!!" <<lover->name <<std :: endl;
}
int main()
{
    Boyfriend boyfriend("A person");
    Girlfriend girlfriend("B girl");

    Others others("road person");

    girlfriend.kiss(&boyfriend);
    girlfriend.ask(&boyfriend,"wash cloesh");

    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    others.Kiss(&girlfriend);

    return 0;
}


