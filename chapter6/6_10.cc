#include <iostream>
using namespace std;
void swap(int *, int *);
void swap(int &, int &);

int main(int argc, char const *argv[])
{
    int a = 10, b = 5;
    swap(&a, &b);
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}