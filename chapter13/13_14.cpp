#include <iostream>
using namespace std;
class numbered{
public:
    
    numbered(){
        mysn = count++;
    }
    // 定义拷贝构造函数后，输出变为3，4，5
    // 为什么不是1，2，3因为f函数调用，也会使用拷贝构造函数
    numbered(numbered &n){
        mysn = count++;
    }

    int mysn;
private:
    static int count;
};
// 静态成员需要定义
int numbered::count = 0;
void f(numbered s){
    cout << s.mysn << endl;
}

int main(int argc, char const *argv[])
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);

    return 0;
}
