#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vInt;
    //for (int tmp; cin >> tmp; vInt.push_back(tmp))
    int tmp;
    while (cin >> tmp)
    {
        vInt.push_back(tmp);
    }

    for (auto it = vInt.cbegin(); it + 1 != vInt.cend(); ++it)
    {
        cout << *(it) + *(it + 1) << " ";
    }
    cout << endl;
    return 0;
}
