#include <string>
#include <unordered_set>
using namespace std;

class Folder;

class Message {

public:
    // 构造函数
    explicit Message(const string &s = ""):content(s){}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

private:
    string content;
    unordered_set<Folder*> folders;
    void add_to_folders(const Message&);
    void remove_from_folders();
};

class Folder {
public:
    void addMsg(Message* msg){
        messages.insert(msg);
    }
    void removeMsg(Message* msg){
        messages.erase(msg);
    }

    
private:
    unordered_set<Message*> messages; 
};