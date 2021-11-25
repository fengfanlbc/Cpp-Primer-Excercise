#include <iostream>
#include <string>
using namespace std;
class HasPtr{
public:
    // 构造函数
    HasPtr(const string &s = string()):ps(new string(s)), i(0),use(new size_t(1)){
        cout << "call default constructor" << endl;
    }
    // 拷贝构造函数
    HasPtr(const HasPtr &p):ps(p.ps), i(p.i), use(p.use){
        ++*use;
        cout << "call copy constructor" << endl;
    }
    // 拷贝赋值运算符
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string&);
    // 重载其解引用运算符，用于值的获取
    string& operator*();
    // 析构函数
    ~HasPtr();
private:
    string *ps;
    int i;
    // 引用计数器作为一个指针，指向计数值
    size_t *use;
};
HasPtr::~HasPtr(){
    // 当计数值为0时才回收
    if(--*use == 0){
        cout << "call finial delete" << endl;
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& p){
    // 类指针行为自赋值
    // 为了避免自赋值，需要先将赋值元素的引用计数加1，再对被赋值元素减一
    ++*p.use;
    if(--*use == 0){
        delete ps;
        delete use;
    }
    ps = p.ps;
    i = p.i;
    use = p.use;
    return *this;
}

HasPtr& HasPtr::operator=(const string& s){
    *ps = s;
    return *this;
}

string& HasPtr::operator*(){
    return *ps;
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
    //cout << "h4:" << *h4 << endl;
    return 0;
}