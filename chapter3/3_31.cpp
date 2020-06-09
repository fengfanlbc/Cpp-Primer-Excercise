#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[10];
    for (size_t i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    for (auto e : arr)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
