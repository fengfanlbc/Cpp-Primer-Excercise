#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Please input string" << endl;
    string s;
    getline(cin, s);
    // for (auto &c : s)
    for (char &c : s)
    {
        if (!isspace(c))
        {
            c = 'X';
        }
    }
    cout << "res:" << s << endl;
    return 0;
}
