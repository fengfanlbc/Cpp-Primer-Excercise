#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int * p = new int[10]();
    cout << p[0] << endl;
    p[0] = 1;
    delete []p;
    cout << p[0] << endl;
    
    return 0;
}
