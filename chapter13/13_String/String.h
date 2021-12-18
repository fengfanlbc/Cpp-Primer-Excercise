#ifndef __CH13_STRING_H__
#define __CH13_STRING_H__
#include <memory>

class String {
public:
    // 默认构造函数
    String():String(""){};
    // 支持常量字符串构造
    String(const char*);
    // 拷贝构造，拷贝赋值
    String(const String&);
    String& operator=(const String&);

    // 移动构造，移动赋值
    String(String&&) noexcept;
    String& operator=(String&&) noexcept;

    // 析构函数
    ~String();

    const char* c_str() const {return begin;}
    size_t size() {return end - begin;}

private:
    std::pair<char*, char*> alloc_n_copy(const char* b, const char* e);
    void range_initializer(const char* b, const char* e);
    void free();

private:
    char* begin;
    char* end;
    std::allocator<char> alloc;
};

#endif