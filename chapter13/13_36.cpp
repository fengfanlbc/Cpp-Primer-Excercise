#include "13_36.h"

void Message::add_to_folders(const Message& m){
    for(auto f : m.folders){
        f->addMsg(this);
    }
}

void Message::remove_from_folders(){
    for(auto f : folders){
        f->removeMsg(this);
    }
    folders.clear();
}

Message::Message(const Message& m):content(m.content), folders(m.folders) {
    add_to_folders(m);
}

Message::~Message(){

}