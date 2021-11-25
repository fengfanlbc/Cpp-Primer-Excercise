#include<vector>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<string> vs;
    auto iter = vs.begin();
    string word;
    while(cin >> word){
        iter = vs.insert(iter, word);
    } 
    for(auto c : vs)cout << c;
    cout << endl;
    return 0;
}
