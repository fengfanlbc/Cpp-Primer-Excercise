#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt;
    cout << "please input numbers" << endl;
    int n;
    while (cin >> n)
    {
        vInt.push_back(n);
    }
    if (vInt.size() == 0)
    {
        cout << "no numbers" << endl;
        return -1;
    }
    for (int i = 0; i < vInt.size() / 2; i++)
    {
        cout << vInt[i] + vInt[vInt.size() - 1 - i] << " ";
        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }

    if (vInt.size() % 2 != 0)
    {
        cout << vInt[vInt.size() / 2] << endl;
    }
    return 0;
}
