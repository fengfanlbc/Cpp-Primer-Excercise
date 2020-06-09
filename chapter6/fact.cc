#include "chapter6.h"
#include <iostream>
using namespace std;
int fact(int val)
{
    if (val == 1 || val == 0)
        return 1;
    else
        return val * fact(val - 1);
}

int func()
{
    int n, ret = 1;
    cout << "please input a number" << endl;
    cin >> n;
    while (n > 1)
        ret *= n--;
    return ret;
}