#include "13_39.h"
StrVec::StrVec(const StrVec& rhs) {
    // 重新申请一个空间
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    // 更新指针
    elements = newdata.first;
    first_free = cap = newdata.second;
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy (const std::string* b, const std::string* e){
    // 动态产出空间
    auto data = alloc.allocate(e-b);
    // uninitialized_copy 将 b 指针到 e指针的内容复制到 data 内存空间里
    std::uninitialized_copy(b, e, data);
    
}