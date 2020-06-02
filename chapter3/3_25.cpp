#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<unsigned> grades(11, 0);
    for (int grade; cin >> grade;)
    {
        if (grade <= 100 && 0 < grade)
        {
            ++*(grades.begin() + (grade / 10));
        }
    }
    // for (auto it = grades.begin(); it < grades.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    for (auto s : grades)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
