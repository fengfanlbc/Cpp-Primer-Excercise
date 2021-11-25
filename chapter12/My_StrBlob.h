#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
using namespace std;
class StrBlobStr;

class StrBlob{
    friend class StrBlobStr;
    public:
        // 容器元素类型别名
        typedef std::vector<string>::size_type size_type;
        // 默认构造函数
        StrBlob();
        // 自定义构造函数
        StrBlob(initializer_list<string> il);
        StrBlob(vector<string> *p);
        // 获取长度
        size_type size() const {return data->size();}
        // 判断是否为空
        bool empty() const{ return data->empty();}

        void push_back(const string &s){data->push_back(s);}
        void pop_back();
        string& front();
        string& back();
        // 函数重载为常量成员函数
        const string& front() const;
        const string& back() const;
        StrBlobStr begin();
        StrBlobStr begin() const;
        StrBlobStr end();
        StrBlobStr end() const;
    private:
        shared_ptr<std::vector<std::string>> data;
        void check(size_type i, const std::string &message) const;
};
inline StrBlob::StrBlob():data(make_shared<vector<string>>()){};
inline StrBlob::StrBlob(vector<string> *p):data(p){};
StrBlob::StrBlob(initializer_list<string> is):data(make_shared<vector<string>>(is)){}

void StrBlob::check(size_type i, const string &message) const{
    if(i > data->size()){
        throw out_of_range(message);
    }
}

inline void StrBlob::pop_back() {
    check(0, "pop back on empty vector");
    data->pop_back();
}

inline string& StrBlob::front() {
    check(0, "front have no element");
    return data->front();
}

inline const string& StrBlob::front() const{
    check(0, "front have no element");
    return data->front();
}

inline string& StrBlob::back() {
    check(0, "back have no element");
    return data->back();
}

inline const string& StrBlob::back() const{
    check(0, "back have no element");
    return data->back();
};

class StrBlobStr{
    public:
        size_t curr;
        StrBlobStr():curr(0){}
        StrBlobStr(StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz){}
        // 接受常量参数的构造函数
        StrBlobStr(const StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz){}

        string& deref() const;
        string& deref(size_t sz) const;
        StrBlobStr& incr();
        StrBlobStr& decr();
        bool operator!=(const StrBlobStr& p){
            return curr != p.curr;
        }

    private:
        
        weak_ptr<vector<string>> wptr;
        shared_ptr<vector<string>> check(size_t i, const string &s) const;      
};

inline shared_ptr<vector<string>> StrBlobStr::check(size_t i, const string &s) const{
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(s);
    return ret;
}

inline string& StrBlobStr::deref() const {
    auto p = check(curr, "deref past end");
    return (*p)[curr];
}

inline string& StrBlobStr::deref(size_t sz) const {
    auto p = check(curr + sz, "deref past end");
    return (*p)[curr + sz];
}

inline StrBlobStr& StrBlobStr::incr() {
    check(curr, "incr pass end");
    ++curr;
    return *this;
}

inline StrBlobStr& StrBlobStr::decr() {
    --curr;
    check(curr, "decr pass begin");
    return *this;
}

inline StrBlobStr StrBlob::begin(){
    return StrBlobStr(*this);
}

inline StrBlobStr StrBlob::end(){
    auto ret = StrBlobStr(*this, data->size());
    return ret;
}

inline StrBlobStr StrBlob::begin() const{
    return StrBlobStr(*this);
}

inline StrBlobStr StrBlob::end() const{
    auto ret = StrBlobStr(*this, data->size());
    return ret;
}

#endif