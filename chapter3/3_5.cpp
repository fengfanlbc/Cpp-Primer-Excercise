#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string res;
    string word;
    char a = word[0];
    cout << a << endl;
    while (cin >> word)
    {
        res += word + " ";
    }
    cout << "res:" << res << endl;
    return 0;
}
