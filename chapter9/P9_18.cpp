#include <iostream>
#include <deque>
#include <list>
using namespace std;


int main(int argc, char const *argv[])
{
    //deque<string> dq;
    list<string> dq;
    string word;
    while(cin >> word){
        dq.push_back(word);
    }
    for(auto it = dq.begin(); it != dq.end(); it++){
        cout << *it << endl;
    }

    return 0;
}
