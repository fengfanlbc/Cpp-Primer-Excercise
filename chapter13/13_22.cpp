#include <iostream>
#include <string>
using namespace std;
class HasPtr{
    friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
    // 构造函数
    HasPtr(const string &s = string()):ps(new string(s)), i(0){
        cout << "call default constructor" << endl;
    }
    // 拷贝构造函数
    HasPtr(const HasPtr &p):ps(new string(*p.ps)), i(p.i){
        cout << "call copy constructor" << endl;
    }
    // 拷贝赋值运算符
    //HasPtr& operator=(const HasPtr&);

    HasPtr& operator=(HasPtr);
    HasPtr& operator=(const string&);
    // 重载其解引用运算符，用于值的获取
    string& operator*();
    // 析构函数
    ~HasPtr();
private:
    string *ps;
    int i;
};
HasPtr::~HasPtr(){
    delete ps;
}
// HasPtr& HasPtr::operator=(const HasPtr& p){
//     // 避免自赋值，先将拷贝内容保存
//     string *temp = new string(*p.ps);
//     delete ps;
//     ps = temp;
//     i = p.i;
//     return *this;
// }

HasPtr& HasPtr::operator=(HasPtr p){
    // 避免自赋值，先将拷贝内容保存
    swap(*this, p);
    return *this;
}

HasPtr& HasPtr::operator=(const string& s){
    *ps = s;
    return *this;
}

string& HasPtr::operator*(){
    return *ps;
}

inline void swap(HasPtr &lhs, HasPtr &rhs){
    cout << "swap" << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main(int argc, char const *argv[])
{
    // 调用构造函数
    HasPtr h ("hi ff1");
    // 调用拷贝构造函数
    HasPtr h2(h);
    // 调用拷贝构造函数
    HasPtr h3 = h;
    // 使用的拷贝赋值
    h2 = "hi ff2";
    h3 = "hi ff3";

    // 异常error: conversion from 'const char [4]' to non-scalar type 'HasPtr' requested
    //HasPtr h4 = "ff4";
    
    cout << "h:" << *h << endl;
    cout << "h2:" << *h2 << endl;
    cout << "h3:" << *h3 << endl;
    swap(h2, h3);
    cout << "h2:" << *h2 << endl;
    cout << "h3:" << *h3 << endl;
    h3 = h3;
    //cout << "h4:" << *h4 << endl;
    return 0;
}
