#include <iostream>
#include "13_36.h"

// 消息交换
void swap(Message& m1, Message& m2){
    m1.remove_from_folders();
    m2.remove_from_folders();
    std::swap(m1.folders, m2.folders);
    std::swap(m1.content, m2.content);
    m1.add_to_folders(m1);
    m2.add_to_folders(m2);

}
// 把消息添加到所有归属目录
void Message::add_to_folders(const Message& m){
    for(auto f : m.folders){
        f->addMsg(this);
    }
}

// 从所有归属目录中删除该消息
void Message::remove_from_folders(){
    for(auto f : folders){
        f->removeMsg(this);
    }
    //folders.clear();
}

// 拷贝构造函数定义
Message::Message(const Message& m): content(m.content), folders(m.folders) {
    add_to_folders(m);
}

// 移动构造函数定义
Message::Message(Message&& m): content(std::move(m.content)){
    std::cout << "use move constructor" << std::endl;
    move_folders(&m);
}

// 辅助移动构造和移动赋值
// 将传递的消息从folder 中移出
// 将传递的消息的folder 内容置空，变为可析构状态
void Message::move_folders(Message *m){
    // 直接移动folders指针
    folders = std::move(m->folders);
    // 将现有folders 里的m消息删除
    // 加上现有的新消息
    for(auto f : folders){
        f->removeMsg(m);
        f->addMsg(this);
    }
    // 保证移动后的源对象是可析构、销毁的
    m->folders.clear();
}

// 拷贝赋值
Message& Message::operator=(const Message& m) {
    
    remove_from_folders();
    this->content = m.content;
    this->folders = m.folders;
    add_to_folders(m);
    return *this;
}

// 移动赋值
Message& Message::operator=(Message&& m) {
    std::cout << "use move assign" << std::endl;
    if (this != &m) {
        remove_from_folders();
        content = std::move(m.content);
        move_folders(&m);
    }
    return *this;
}

// 析构函数定义
Message::~Message(){
    remove_from_folders();
}

// 保存一个消息到指定目录
void Message::save(Folder& f){
    addFolder(&f);
    // 访问其它类的私有函数，需要定义友员
    f.addMsg(this);
}

// 从指定目录删除消息
void Message::remove(Folder& f){
    remFolder(&f);
    f.removeMsg(this);
}


void Message::print_debug() {
    std::cout << "content:" << content << std::endl;
}

/////////////// Folder 实现//////////////////////////////

void Folder::add_to_messages(){
    for(auto m : messages){
        m->addFolder(this);
    }
}

void Folder::remove_from_messages() {
    for(auto m : messages){
        m->remFolder(this);
    }
}

// 拷贝构造函数
Folder::Folder(const Folder& f): messages(f.messages){
    add_to_messages();
}

// 拷贝赋值
Folder& Folder::operator=(const Folder& f) {
    // 先将关联的消息，从消息对象侧删除
    remove_from_messages();
    messages = f.messages;
    // 再将关联的消息从消息对象侧加上
    add_to_messages();
    return *this;
}

// 析构函数
Folder::~Folder() {
    remove_from_messages();
}

void swap(Folder& lhs, Folder& rhs)
{
    using std::swap;
    lhs.remove_from_messages();
    rhs.remove_from_messages();

    swap(lhs.messages, rhs.messages);

    lhs.add_to_messages();
    rhs.add_to_messages();
}

void Folder::print_debug(){
    std::cout << "folder messages:" << std::endl;
    for (auto m : messages){
        std::cout << m->content << std::endl;
    }
}