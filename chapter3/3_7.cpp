#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> v;
    int a;
    while (cin >> a)
    {
        v.push_back(a);
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
