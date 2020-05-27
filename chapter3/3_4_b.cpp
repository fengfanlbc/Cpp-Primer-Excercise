#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string s1, s2;
    cout << "input 2 nums" << endl;
    cin >> s1 >> s2;
    auto len1 = s1.size();
    auto len2 = s2.size();
    if (len1 == len2)
    {
        cout << "length is same" << endl;
    }
    else if (len1 > len2)
    {
        cout << "s1 is longer" << endl;
    }
    else
    {
        cout << "s2 is longer" << endl;
    }
    return 0;
}
