#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    vector<int> v = {1,2,3,4,5};
    vector<int> v2 = {7,8,9,10,11};
    
    copy(v.begin(), v.end(), back_inserter(v2));
    //copy(v.begin(), v.end(), v2);

    // 7;8;9;10;11;1;2;3;4;5;
    // 可以看到是往指定位置插入元素，原来的元素向后移动
    for(auto i : v2) {
        cout << i << ";";
    }
    cout << endl;


    int a[] = {1,2,3,4,5};
    int b[sizeof(a)/sizeof(*a)];
    b[0] = 7;
    copy(begin(a), end(a), b);

    for(auto k : b) {
        cout << k << ";";
    }
    cout << endl;

    vector<int> v3;
    //v3.reserve(5);
    v3.resize(6);
    //fill_n(back_inserter(v3), 5, 6);
    fill_n(v3, 5, 6);
    for(auto e : v3) {
        cout << e << ";";
    }
    cout << endl;
    return 0;
}
