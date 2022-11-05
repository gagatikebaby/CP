#include<iostream>
#include<stdlib.h>
#include<string.h>

class Rational
{
    public:
    Rational(int num, int denom);
    Rational operator+(Rational rhs);
    Rational operator-(Rational rhs);
    Rational operator*(Rational rhs);
    Rational operator/(Rational rhs);

    private:
    int numerator;
    int denominator;
    void normalize();
    friend std::ostream& operator<<(std::ostream& os, Rational f);
};

Rational :: Rational(int num, int denom)
{
    numerator = num;
    denominator = denom;

    normalize();
}

void Rational ::normalize()
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
    denominator /=a;

    numerator /= a;  
}

Rational Rational :: operator+(Rational rhs)
{
    int a = numerator;
    int b = denominator;
    int c = rhs.numerator;
    int d = rhs.denominator;

    int e = a * d + c * b;
    int f = b * d;

    return Rational(e,f);
}

Rational Rational :: operator-(Rational rhs)
{
    rhs.numerator = -rhs.numerator;

    return operator+(rhs);
}

Rational Rational :: operator*(Rational rhs)
{
    int a = numerator * rhs.numerator;
    int b = denominator *rhs.denominator;

    return Rational(a,b);

}

Rational Rational :: operator/(Rational rhs)
{
    int t = rhs.numerator;
    rhs.numerator = rhs.denominator;
    rhs.denominator = t;

    return operator*(rhs);
}

std::ostream& operator<<(std::ostream& os, Rational f);

int main()
{
    Rational f1(2,16);
    Rational f2(7,8);

    std :: cout << f1 <<"+"<<f2<<" = "<<(f1+f2)<<"\n";

    std :: cout << f1 << "-" << f2 << " = " << (f1 -f2) <<"\n";

    std :: cout << f1 << "*" << f2 << " = " << (f1 *f2) << "\n";

    std :: cout << f1 << "/" << f2 << " = " << (f1 / f2) << "\n"; 
}

std :: ostream& operator<<(std :: ostream& os, Rational f)
{
    os << f.numerator << " / " << f.denominator;
    return os;
}