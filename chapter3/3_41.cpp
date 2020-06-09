#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> vInt(begin(a), end(a));
    for (auto i : vInt)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}