#include <iostream>
#include <string>

class Add
{
public:
    Add();

    Add(int i, int j);

    Add operator+(Add &d);

    void print();

private:
    int num;
    int deno;
}

Add::Add()
{
    num = 0;
    deno = 0;
}

Add ::Add(int i, int j)
{
    num = i;
    deno = j;
}

Add Add ::operator+(Add &d)
{
    return Add(num + d.num, deno + d.deno);
}

void Add::print()
{

    std::cout << num << "/" << deno << "\n";
}

int main()
{

    Add c1(1, 8), c2(3, 8), c3;
}