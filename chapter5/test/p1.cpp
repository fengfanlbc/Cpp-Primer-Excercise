#include <iostream>
using namespace std;

size_t count_calls()
{
    static size_t count = 0;
    ++count;
    return count;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "第 " << count_calls() << " 次调用";
    }
    return 0;
}
