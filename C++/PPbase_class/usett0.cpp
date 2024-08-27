#include<iostream>
#include"tabtenn0.h"

int main(void)
{
    using std::cout;
    TableTennisPlayer Player1("Chuck","Blizzard",true);
    TableTennisPlayer Player2("Tara","Boomdea",false);
    Player1.Name();
    if (Player1.HasTable())
    {
        cout<<": has a table.\n";
    }
    else
    cout<<":hasn't a table.\n";
    Player2.Name();
    {
        if(Player2.HasTable())
        
        cout<<":has a table";
        
        else
        cout<<": hasn't a table.\n";
    }
    return 0;
}