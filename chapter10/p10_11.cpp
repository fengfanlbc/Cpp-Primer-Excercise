#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    
    while(getline(cin, s)){
        vector<string> wordsList;
        cout << "primary string is:" << s << endl;
        stringstream ss(s);
        string word;
        while(ss >> word){
            wordsList.push_back(word);
        }
        sort(wordsList.begin(), wordsList.end());
        auto unique_end = unique(wordsList.begin(), wordsList.end());
        wordsList.erase(unique_end, wordsList.end());
        for(auto i : wordsList){
            cout << i;
        }
        cout << endl;

        s.clear();
        //s.insert(s.begin(), wordsList.begin(), wordsList.end());
        //s.assign(wordsList.begin(), wordsList.end());
        
        s = accumulate(wordsList.begin(), wordsList.end(), s);
        cout << "unique string is:" << s<< endl;

    }   
    return 0;
}
