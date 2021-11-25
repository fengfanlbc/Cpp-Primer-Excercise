#include <iostream>
#include <fstream>
#include "My_TextQuery.h"
#include <cstdlib>
using namespace std;


void runQuery(ifstream &f) {
    TextQuery tq(f);
    while (true) {
        cout << "please enter word to look for, or enter q to quit" << endl;
        string s;
        if(!(cin >> s) || s == "q")break;
        print(cout, tq.query(s)) << endl;
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
