#include "My_TextQuery.h"
#include <string>
#include <sstream>
using namespace std;

TextQuery::TextQuery(ifstream &is):file(new vector<string>){
    string line;
    while(getline(is, line)){
        file.push_back(line);
        int n = file.size();
        istringstream ss(line);
        string word;
        while(ss >> word){
            auto it = wm.find(word);
            if(it == wm.end()){
                wm[word].reset(new set<line_no>);
            }
            wm[word]->insert(n-1);
        }
    }   
}

QueryResult TextQuery::query(const string& sought){
    // 为什么要声明为静态的？
    static shared_ptr<set<line_no>> nodata;
    auto lines = wm.find(cleanup_str(sought));
    if(lines == wm.end()){
        return QueryResult(sought, nodata, file);
    }else{
        return QueryResult(sought, lines->second, file);
    }
    
}

std::string TextQuery::cleanup_str(const std::string &word){
    string ret;
    for(auto it = word.begin(); it != word.end(); ++it) {
        if(!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}

ostream& print(ostream & os, const QueryResult &qr){
    os << qr.sought << " occurs " << qr.lines->size() << " times:"<< endl;
    for(auto line : *qr.lines){
        //qr 是常量
        os << "line " << line << ": " << qr.file.begin().deref(line) << endl;
    }
    return os;
}