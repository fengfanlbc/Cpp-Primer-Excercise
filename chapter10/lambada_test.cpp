#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    auto basicLambada = [] {cout << "hello world" << endl;};
    basicLambada();

    auto add = [](int a, int b) -> int {return a + b;};
    cout << "add res:" << add(2,3) << endl;
    return 0;
}
