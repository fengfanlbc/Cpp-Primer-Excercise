#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 3;
    string s = "who";
    int arr[] = {1, 2, 3, 4};
    char c = 'a';
    char *ptr1 = &c;
    string *ptr2 = &s;
    //int[] *ptr3 = arr;
    int *ptr3 = arr;
    cout << "int a:" << sizeof a << endl;
    cout << "string s:" << sizeof s << endl;
    cout << "int arr:" << sizeof arr << "; num:" << sizeof(arr) / sizeof(*arr) << endl;
    cout << "char c = " << sizeof c << endl;
    cout << "pointer char * = " << sizeof ptr1 << endl;
    cout << "pointer string * = " << sizeof ptr2 << endl;
    cout << "pointer arr ptr * = " << sizeof ptr3 << endl;
    return 0;
}
