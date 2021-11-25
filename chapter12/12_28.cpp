#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cstdlib>
using namespace std;

using lineNo = std::vector<string>::size_type;
std::vector<std::string> fileContet;
std::unordered_map<string, std::set<lineNo>> wm;

string cleanupStr(const string &word){
    string ret;
    for(auto it = word.begin(); it != word.end(); it++){
        if(!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}

void loadFile(ifstream &infile){
    string line;
    while(getline(infile, line)){
        fileContet.push_back(line);
        int n = fileContet.size() - 1;
        string word;
        istringstream is(line);
        while(is >> word){
            wm[cleanupStr(word)].insert(n);
        }
    }
}

void queryAndPrint(const string &sought, ostream & os){
    auto loc = wm.find(sought);
    if(loc == wm.end()){
        os << sought << "occurs 0 times" << endl;
    }else{
        auto lines = loc->second;
        os << sought << "occurs " << lines.size() << " times:" << endl;
        for(auto num : lines){
            os << "\tline " << num + 1 << ":" << (fileContet[num]) << endl;
        }
    }
}

void runQuery(ifstream &infile){
    loadFile(infile);
    while(true){
        cout << "enter word to look for, or enter q to quit" << endl;
        string s;
        if(!(cin >> s) || s == "q")break;
        queryAndPrint(s, cout);
    }
}

int main(int argc, char const *argv[])
{
    ifstream infile;
    // 检查参数
    if( argc < 2 || !(infile.open(argv[1]), infile)){
        cerr << "No input file" << endl;
        return EXIT_FAILURE;
    }

    runQuery(infile);

    return 0;
}
