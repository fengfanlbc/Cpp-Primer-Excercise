#include <iostream>
#include <vector>
using namespace std;
class X {
    public:
        // 构造函数
        X() {
            cout << "use constructor: X()" << endl;
        }

        // 拷贝构造函数 
        X(const X& x) {
            cout << "use copy constructor: X(const X& x)" << endl; 
        }
        
        X& operator=(const X& x){
            cout << "use copy assginment=: X& operator=(const X& x)" << endl;
            return *this;
        }

        ~X(){
            cout << "use destructor: ~X()" << endl;
        }
};

void f1(X x) {
    cout << "use f1()" << endl;
}

void f2(X &x){
    cout << "use f2()" << endl;
}

int main(int argc, char const *argv[])
{
    cout << "local variable test:"<< endl;
    // 这里会调用构造函数
    X x;
    cout << "=====================" << endl;

    cout << "use not refrence param" <<endl;
    // 使用拷贝构造函数
    f1(x);
    cout << "=====================" << endl;

    cout << "use refrence param" << endl;
    // 这里既没有使用构造函数，也没有使用拷贝构造函数
    f2(x);
    cout << "=====================" << endl;
    
    cout << "use dynamic allocate" << endl;
    // 会使用构造函数
    X *px = new X;
    cout << "=====================" << endl;

    cout << "push back to vector" << endl;
    vector<X> vx;
    cout << "capacity:" << vx.capacity() << endl;
    //会使用拷贝构造函数
    //调用1次copy constructor
    vx.push_back(x);
    cout << "capacity:" << vx.capacity() << endl;
    cout << "=====================" << endl;

    cout << "emplace to vector" << endl;
    //调用2次copy constructor
    vx.push_back(x);
    cout << "capacity:" << vx.capacity() << endl;
    //调用4次copy constructor
    vx.emplace_back(x);
    cout << "capacity:" << vx.capacity() << endl;
    cout << "=====================" << endl;

    cout << "delete" << endl;
    delete px;
    cout << "=====================" << endl;

    cout << "copy initial && assignment" << endl;
    // 使用拷贝构造函数
    X y = x;
    // 使用拷贝赋值运算符
    y = x;
    cout << "=====================" << endl;

    return 0;
}
