#include <string>
#include <iostream>
using namespace std;

string myReplace(string &s, const string &oldVal, const string &newVal){

    auto curr = s.begin();
    while(curr != s.end() - oldVal.size()){
        if(oldVal == string(curr, curr + oldVal.size())){
            curr = s.erase(curr, curr + oldVal.size());
            curr = s.insert(curr, newVal.begin(), newVal.end());
            curr += newVal.size();
        }else{
            curr++;
        }
    }
    return s;
}

string myReplace2(string &s, const string &oldVal, const string &newVal){

    for(int i = 0; i < s.size() - oldVal.size();){
        if(oldVal == string(s, i , oldVal.size())){
            cout << "debug" << oldVal << endl;
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        }else{
            i++;
        }
    }
    return s;
}

int main(int argc, char const *argv[])
{
    string s("To drive straight thru is a foolish, tho courageous act.");
	myReplace(s,"tho","though");
	myReplace(s, "thru", "through");

	//cout << s <<endl;

    string s1("To drive straight thru is a foolish, tho courageous act.");
    myReplace2(s1,"tho","though");
    cout << s1 << endl;
	myReplace2(s1, "thru", "through");

    cout << s1 << endl;
    return 0;
}
