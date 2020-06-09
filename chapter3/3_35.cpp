#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    for (int *p = a; p != a + 5; p++)
    {
        *p = 0;
    }
    return 0;
}
