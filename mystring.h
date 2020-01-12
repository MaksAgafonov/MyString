#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;

class MyString
{
public:
    MyString(); // пустой конструктор

    MyString(const char * str = ""); // конструктор

    MyString(const MyString &other); // контструктор копирования

    MyString(MyString &&s); // перемещающий конструктор

    MyString & operator=( const MyString & other); // оператор присваивания

    MyString & operator=(MyString && s); // перемещающий оператор присваивания

    bool operator<(const MyString & right); // перегрузка сравнения

    bool operator>(const MyString & right);

    void append(const MyString & str); // добавление в конец

    ~MyString(); // деструктор

    friend ostream& operator<< (ostream & object, const MyString&temp){
        return object <<temp.str_;
    }

private:
    unsigned int size_ = 0;
    char * str_ = nullptr;
    unsigned int strLen(const char * str);
};


#endif // STRING_H

