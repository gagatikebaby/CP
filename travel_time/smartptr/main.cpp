#include <iostream>
#include <memory>
#include "cat.h"
using namespace std;

int main(int argc, char *argv[])
{
    // STACK
#if (0)
    Cat c1("OK");
    c1.cat_info();
    {
        Cat c1("OK");
        c1.cat_info();
    }
    // heap
    Cat *cat_1 = new Cat("OK1");
    cat_1->cat_info();
    {
        Cat *cat_1 = new Cat("OK1");
        cat_1->cat_info();
        delete cat_1;
    }
    delete cat_1;
#endif
    Cat *cat_2 = new Cat("yz"); //实例化
    std::unique_ptr<Cat> u_c_p2{cat_2};
    cat_2 = nullptr;
    u_c_p2->cat_info();

    //second
    std::unique_ptr<Cat> u_c_p3{new Cat("dd")};
    u_c_p3->cat_info();
    u_c_p3->set_name("oo");
    u_c_p3->cat_info();

    //third
    std::unique_ptr<Cat> u_c_p4 = make_unique<Cat>();
    u_c_p4->cat_info();
    u_c_p4->set_name("oo");
    u_c_p4->cat_info();

    cout << "----------------end----------" << endl;

    return 0;
}