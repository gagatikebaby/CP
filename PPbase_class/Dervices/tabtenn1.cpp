#include"tabtenn1.h"
#include<iostream>

TableTennisPlayer::TableTennisPlayer (const string &fn,                               
const string &ln, bool ht) : firstname(fn),lastname(ln), hasTable(ht){}        //基类的构造函数+初始化列表


void TableTennisPlayer::Name() const
{
    std:: cout << lastname <<","<<firstname;              //基类的name函数定义

}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn,   
const string &ln, bool ht) : TableTennisPlayer(fn,ln,ht)
{
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)   //派生类的构造函数+初始化列表
    : TableTennisPlayer(tp),rating(r)
    {

    }