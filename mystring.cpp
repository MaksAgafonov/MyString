#include "mystring.h"

MyString::MyString()
{
    size_ = 0;
    str_ = new char[size_+1];
    str_[0]='\0';
}

MyString::MyString(const char *str)  {
    size_ = strLen(str);
    str_ = new char[size_+1];
    for(auto i = 0; i<size_;++i)
        str_[i] = str[i];
    str_[size_] = '\0';
}

MyString::MyString(const MyString &other) : MyString(other.str_){}

MyString::MyString(MyString &&s):size_(s.size_),str_(s.str_){
    s.size_=0;
    s.str_ = nullptr;
}

MyString &MyString::operator=(MyString &&s){
    delete [] str_;
    str_ = s.str_;
    size_ = s.size_;
    s.str_ = nullptr;
    s.size_ = 0;
    return *this;
}

MyString &MyString::operator=(const MyString &other){
    cout << " === "<<endl;
    if(this != &other){
        delete [] str_;
        new(this) MyString(other.str_);
    }
    return *this;
}
bool strlwr(){

}
bool MyString::operator<(const MyString &right){
    unsigned int s =0;
    size_<right.size_ ? s=size_ : s = right.size_;
    for(auto i =0; i<s; ++i){
        if(tolower(str_[i])==tolower(right.str_[i])){
            continue;
        }
        return tolower(str_[i])<tolower(right.str_[i]);
    }
    return size_<right.size_;
}

bool MyString::operator>(const MyString &right)
{
    return !(*this < right);
}

void MyString::append(const MyString &str){
    auto sizeBuf = size_;
    //char * buf = new char[_size+1];
    char buf[size_+1];
    for(auto i = 0; i <size_;++i)
        buf[i] = str_[i];

    delete [] str_;

    size_+=str.size_;
    str_ = new char[size_+1];

    for(auto i = 0; i <sizeBuf;++i)
        str_[i] = buf[i];

    for(auto i = sizeBuf; i <size_;++i)
        str_[i] = str.str_[i-sizeBuf];
    str_[size_]='\0';
 //   delete [] buf;
}

MyString::~MyString(){
    delete [] str_;
}

unsigned int MyString::strLen(const char *str){
    const char * s = str;
    while(*++s);
    return s - str;
}





