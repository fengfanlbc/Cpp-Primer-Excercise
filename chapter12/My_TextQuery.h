#ifndef MY_TEXTQUERY_H
#define MY_TEXTQUERY_H
#include <unordered_map>
#include <set>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include "My_StrBlob.h"
#include "My_QueryResult.h"
using namespace std;
class QueryResult;

class TextQuery{
    public:
        using line_no = std::vector<string>::size_type;
        TextQuery(ifstream &is);
        QueryResult query(const string &sought);
    private:
        StrBlob file;
        std::unordered_map<std::string, shared_ptr<set<line_no>>> wm;
        static std::string cleanup_str(const std::string&);
};


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
#endif