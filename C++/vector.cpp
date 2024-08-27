#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>

int main()
{
    std::vector<int> a = {4,3,5,3,1,32,2};
    auto n = std::count_if(a.begin(),a.end(),std::bind2nd(std::less<int>(),4));
    std::cout << n <<std::endl;
    return 0;
}