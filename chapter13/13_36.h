#include <string>
#include <unordered_set>
using namespace std;

class Folder;

class Message {
friend class Folder;
friend void swap(Message& m1, Message& m2);
public:
    // 构造函数
    explicit Message(const string &s = ""):content(s){}
    Message(const Message&);
    Message& operator=(const Message&);
    // 保存到消息到指定目录
    void save(Folder&);
    // 从指定目录中删除该消息
    void remove(Folder&);
    ~Message();

    void print_debug();

private:
    string content;
    unordered_set<Folder*> folders;

    void add_to_folders(const Message&);

    void remove_from_folders();
    
    void addFolder(Folder* f) {
        folders.insert(f);
    }
    void remFolder(Folder* f) {
        folders.erase(f);
    }
};
void swap(Message& m1, Message& m2);


class Folder {
friend class Message;
friend void swap(Folder& lhs, Folder& rhs);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void print_debug();

private:
    unordered_set<Message*> messages;
    void addMsg(Message* msg){
        messages.insert(msg);
    }
    void removeMsg(Message* msg){
        messages.erase(msg);
    }

    void remove_from_messages();
    void add_to_messages();
};

void swap(Folder& f1, Folder& f2);