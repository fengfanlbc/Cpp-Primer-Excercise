#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    // int *a;
    // int b = 3;
    // *a = b;
    // cout << *a << endl;
    string s1 = "test", *p = &s1;
    auto n = s1.size();
    cout << "size:" << n << endl;
    n = p->size();
    cout << "size:" << n << endl;
    return 0;
}
