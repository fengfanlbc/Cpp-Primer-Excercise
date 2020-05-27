#include <iostream>
using namespace std;
string StringCompare(string, string);
int main(int argc, char const *argv[])
{
    string a = "aaa";
    string b = "bbbb";
    string res = StringCompare(a, b);
    cout << "res:" << res << endl;
    /* code */
    return 0;
}

string StringCompare(string a, string b)
{
    // 先比较长度
    if (a == b)
    {
        return a;
    }
    else if (a > b)
    {
        return a;
    }
    return b;
}
