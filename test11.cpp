#include <iostream>

class Complex
{
public:
    Complex();             //如果没有参数时的构造函数
    Complex(double r, double i);          //有参数时的构造函数
    Complex complex_add(Complex &d); 
    void print();

private:
    double real;
    double imag;
};

Complex::Complex()
{
    real = 0;
    imag = 0;
}

Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

Complex Complex::complex_add(Complex &d) //引用d
{
    Complex c;

    c.real = real + d.real;    //c 类的实部等于  类本来的实部(私有的)+ d 类的实部
    c.imag = imag + d.imag;    //c 类的虚部等于  类本来的虚部（私有的）+ d 类的虚部

    return c;
}

void Complex::print()
{
    std::cout << "(" << real << ", " << imag << "i)\n";
}

int main()
{
    Complex c1(3, 4), c2(5, -10), c3;

    c3 = c1.complex_add(c2);

    std::cout << "c1 = ";
    c1.print();
    std::cout << "c2 = ";
    c2.print();
    std::cout << "c1 + c2 = ";
    c3.print();

    return 0;
}
