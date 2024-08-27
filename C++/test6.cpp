#include<iostream>
#include<string>//字符串头文件
#include<algorithm>//sort函数头文件
using namespace std;
struct node{
        int times;//次数
        int num;//号码 0~25 代表a~z
        node(){times=0;}//构造函数让每个结构体对象初始times为0
}a[26];
bool op(node a,node b){//排序条件
        return a.times>b.times;
}
int main()
{
        string s;//字符串
        for(int i=0;i<26;i++)
                a[i].num=i;
        while(cin>>s){
                for(int i=0;i<s.size();i++){
                        s[i]=tolower(s[i]);//让每个字符变成小写字母
                        a[s[i]-'a'].times++;
                }
                sort(a,a+26,op);//对26个字母以times降序来排序
                for(int i=0;i<26;i++)//最后输出
                        if(a[i].times)
                                cout<<(char)(a[i].num+'a')<<"数目为："<<a[i].times<<endl;
        }
        system("pause");
}