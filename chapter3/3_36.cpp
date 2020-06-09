#include <iostream>
#include <vector>
using namespace std;

bool compare(int *xbegin, int *ybegin, int *xend, int *yend)
{
    if ((xend - xbegin) != (yend - ybegin))
    {
        return false;
    }
    while ((xbegin != xend) && (ybegin != yend))
    {
        if ((*xbegin) != (*ybegin))
        {
            return false;
        }

        xbegin++;
        ybegin++;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int arr1[3] = {0, 1, 2};
    int arr2[3] = {0, 1, 2};
    if (compare(begin(arr1), begin(arr2), end(arr1), end(arr2)))
    {
        cout << "arr1 equal to arr2" << endl;
    }
    else
    {
        cout << "arr1 not equal to arr2" << endl;
    }
    return 0;
}
