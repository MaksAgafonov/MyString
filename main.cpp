#include <iostream>
#include <vector>
#include <list>
#include "mystring.h"
using namespace std;
MyString operator+(MyString lstr, const MyString &rstr){
    lstr.append(rstr);
    return lstr;
}


int main()
{
    list<MyString> stringList;
    char str[250];
    cout<< "Enter string. Press for exit Ctrl-Z+Enter "<<endl;
    while(cin.getline(str,250)){
        stringList.push_back(str);
    }
    stringList.sort([](  MyString & left,  MyString & right) -> bool{ return left > right;});
    cout<<"Sort string list:" <<endl;
    for(auto b = stringList.begin(); b!=stringList.end();++b){
        cout<<(*b)<<endl;
    }

    return 0;
}
