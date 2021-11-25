#ifndef MY_QUERYRESULT_H
#define MY_QUERYRESULT_H
#include <string>
#include <vector>
#include <set>
#include "My_StrBlob.h"

using namespace std;
class QueryResult{
    friend ostream & print(ostream & , const QueryResult&);
    public:
        typedef vector<string>::size_type line_no;
        // 定义构造函数
        QueryResult(const string &s, 
                    shared_ptr<set<line_no>> l, 
                    StrBlob &f):
            sought(s), lines(l), file(f){}
    private:
        string sought;
        shared_ptr<set<line_no>> lines;
        StrBlob file;
};
ostream & print(ostream & , const QueryResult&);
#endif

