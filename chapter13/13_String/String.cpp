#include "String.h"

// 堆内存动态分配
// 先申请空间，然后初始化，将原内容拷贝
std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e){
    auto newStr = alloc.allocate(e-b);
    return {newStr, std::uninitialized_copy(b, e, newStr)};
}

void String::range_initializer(const char* b, const char* e){
    auto p = alloc_n_copy(b, e);
    begin = p.first;
    end = p.second;
}

String::String(const char* c) {
    auto l = const_cast<char*>(c);
    while(*l)l++;
    range_initializer(c, ++l);
}

String::String(const String& s) {
    range_initializer(s.begin, s.end);
}


void String::free() {
   if(begin){
       for(char* c = begin; c <= end; c++){
           alloc.destroy(c);
       }
   }
   alloc.deallocate(begin, end - begin);
}

String& String::operator=(const String& s) {
    auto p = alloc_n_copy(s.begin, s.end);
    free();
    begin = p.first;
    end = p.second;
    return *this;
}

String::String(String&& s) noexcept : begin(s.begin), end(s.end){
    s.begin = s.end = nullptr;
}

String& String::operator=(String && s) noexcept {
    
}
