#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "please input string" << endl;
    string s;
    vector<string> ss;
    while (cin >> s)
    {
        if (!s.empty())
        {
            ss.push_back(s);
        }
    }

    for (auto &i : ss)
    {
        for (auto &t : i)
        {
            if (ispunct(t))
            {
                cout << "input error " << endl;
                return -1;
            }
            t = toupper(t);
        }
        cout << i << endl;
        cout << endl;
    }
    return 0;
}
