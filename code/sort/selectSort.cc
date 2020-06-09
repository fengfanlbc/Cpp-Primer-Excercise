#include <iostream>
#include "Student.h"
using namespace std;

template <typename T>
void selectSort(T a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

int main(int argc, char const *argv[])
{
    int a[5] = {1, 4, 6, 5, 3};
    float b[5] = {1.1, 8.1, 4.3, 5.3, 2.1};
    Student d[5] = {{"a", 90}, {"b", 60}, {"c", 75}, {"d", 55}, {"e", 100}};

    selectSort(a, 5);
    selectSort(b, 5);
    selectSort(d, 5);
    for (int i = 0; i < 5; i++)
        cout << a[i];
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << d[i] << " ";
    cout << endl;

    return 0;
}
