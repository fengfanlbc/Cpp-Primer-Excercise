#include <string>
#include <memory>
class StrVec {
public:
    // 默认构造函数
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){};
    // 拷贝构造函数
    // 这里的拷贝构造和拷贝赋值都应该是重新申请空间，然后将旧空间的内容拷贝过去
    // 这里设置一个 alloc_n_copy 方法来实现
    StrVec(const StrVec&);
    // 拷贝赋值
    StrVec& operator=(const StrVec&); 
    // 析构函数，用于是动态分配的空间，所以需要使用 allocator 的deallocate销毁
    ~StrVec();
    // 添加一个元素，需要检查当前容量是否足够，不够的话申请一个更大的空间
    // 这里设置一个chk_n_alloc实现
    void push_back(const std::string);
    // 得到当前容器的大小,为什么定义成常量成员函数？
    size_t size() const {
        return first_free - elements;
    }
    // 得到当前容器的容量
    size_t capacity() const {
        return cap - elements;
    }
    // 得到头部指针, 类似于头部迭代器
    std::string *begin() const {
        return elements;
    }
    std::string *end() const {
        return first_free;
    }

private:
    // 指向首部 string 元素的指针
    std::string *elements;
    // 指向尾部元素下一个位置的指针
    std::string *first_free;
    // 指向申请分配内存末尾之后的位置
    std::string *cap;
    //声明 alloccator 的静态成员用于动态分配内存
    static std::allocator<std::string> alloc;

    // 确保有足够的空间容纳元素
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }
    // 重新分配空间，将旧空间的元素拷贝过去
    void reallocate();
    // 释放内存
    void free();
    // 
    std::pair<std::string*, std::string*> alloc_n_copy (const std::string*, const std::string*);
};