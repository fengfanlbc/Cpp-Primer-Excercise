#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    list<int> lst = {0,1,2,3,4,5,6};
    auto it = lst.begin();
    while(it != lst.end()){
        if(*it % 2){
            it = lst.erase(it);
        }else{
            ++it;
        }
    }
    for(auto s : lst){
        cout << s ;
    }
    cout << endl;
    return 0;
}
