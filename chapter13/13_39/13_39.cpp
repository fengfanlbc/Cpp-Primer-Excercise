#include "13_39.h"

// 静态成员必须在类外定义https://stackoverflow.com/questions/272900/undefined-reference-to-static-class-member
// 否则会报错：undefined reference to `StrVec::alloc[abi:cxx11]'
std::allocator<std::string> StrVec::alloc;
StrVec::StrVec(const StrVec& rhs) {
    // 重新申请一个空间
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    // 更新指针
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy (const std::string* b, const std::string* e){
    // 动态产出空间
    auto data = alloc.allocate(e-b);
    // uninitialized_copy 将 b 指针到 e指针的内容复制到 data 内存空间里
    return {data,std::uninitialized_copy(b, e, data)};
    
}

void StrVec::push_back(const std::string& s){
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

StrVec::~StrVec(){
    free();
}

void StrVec::free () {
    if (elements) {
        // 逆序销毁元素
        for (auto p = first_free; p != elements;) {
            // destroy 会运行p指针指向元素的析构函数，即 string 对象的析构函数
            alloc.destroy(--p);
        }
        // 释放从elements 开始 长度为 cap - elements 长度的内存
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate() {
    // 如果是最初的大小为 0 分配大小为 1 的空间
    // 如果已经有元素了，分配2倍的空间
    auto new_capacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(new_capacity);
    auto dest = newdata;
    auto elem = elements;
    for ( size_t i = 0; i < size(); i++ ) {
        // move 会让construct 使用 string 的移动构造函数
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_capacity;

}