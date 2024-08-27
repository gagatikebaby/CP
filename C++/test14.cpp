#include<iostream>
#include<stdlib.h>
#include<string>

class Rational
{
    public:
    Rational(int num, int denom);
    Rational operator+(Rational rhs);
    Rational operator-(Rational rhs);
    Rational operator*(Rational rhs);
    Rational operator/(Rational rhs);
    void print();

    private:
    void normlize();

    int numerator;
    int denominator;
};

Rational :: Rational(int num, int denom)
{
    numerator = num;
    denominator = denom;
    normlize();
}

void Rational :: normlize()
{
    if(denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    int a = abs(numerator);
    int b = abs(denominator);

    while (b > 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }

    numerator /= a;
    denominator /= a; 

}

Rational Rational ::operator+(Rational rhs)
{
     int a = numerator ;
     int c = rhs.numerator;
     int b = denominator ;
     int d = rhs.denominator;

    int e = a*b + c*d;
    int f = b*d;

     return Rational(e,f);
}

Rational Rational ::operator-(Rational rhs)
{
    rhs.numerator = -rhs.numerator;

    return operator+(rhs);
}

Rational Rational ::operator*(Rational rhs)
{
    
   

    int a = numerator * rhs.numerator;
    int b =  denominator * rhs.denominator;

    return Rational(a,b);
}

Rational Rational ::operator/(Rational rhs)
{
    int t;
     t = rhs.denominator ;
    rhs.denominator = rhs.numerator;
    rhs.numerator = t;
    
    return operator*(rhs);
}

void Rational:: print()
{
    if (numerator % denominator == 0)
    {
        std::cout <<numerator / denominator;
    }
    else
    {
        std::cout << numerator <<"/" <<denominator;
    }
}

int main()
{
    Rational f1(2,16),f2(7,8);
    // 加法运算
    Rational res = f1 + f2;
    f1.print();
    std::cout << " + ";
    f2.print();
    std::cout << " = ";
    res.print();
    std::cout << "\n";

    // 减法运算
    res = f1 - f2;
    f1.print();
    std::cout << " - ";
    f2.print();
    std::cout << " = ";
    res.print();
    std::cout << "\n";

    // 乘法运算
    res = f1 * f2;
    f1.print();
    std::cout << " * ";
    f2.print();
    std::cout << " = ";
    res.print();
    std::cout << "\n";

    // 除法运算
    res = f1 / f2;
    f1.print();
    std::cout << " / ";
    f2.print();
    std::cout << " = ";
    res.print();
    std::cout << "\n";

    return 0;
}