#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    size_t v1 = 42;
    auto f = [v1]() mutable {return ++v1;};
    v1 = 0;
    auto j  = f();

    vector<string> vs = {"123", "1234", "123456", "1234567"};
    size_t sz = 4;
    auto res = count_if(vs.begin(), vs.end(), [sz](string const &s){return s.size() > sz;});
    cout << "res:" << res << endl;

}