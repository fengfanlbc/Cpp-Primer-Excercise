#include <iostream>
#include <memory>
#include <string>
using namespace std;


struct B;
struct BW;
struct A {
    shared_ptr<B> pb;
    ~A(){
        cout << "~A()" << endl;
    }

};

struct B {
    shared_ptr<A> pa;
    ~B() {
        cout << "~B()" << endl;
    }
};

struct AW {
    shared_ptr<BW> pb;
    ~AW(){
        cout << "~AW()" << endl;
    }
};

struct BW {
    weak_ptr<AW> pa;
    ~BW() {
        cout << "~BW()" << endl;
    }
};

void Test(){
    cout << "Test shared_ptr && shared_ptr" << endl;
    shared_ptr<A> tA (new A());
    shared_ptr<B> tB (new B());
    cout << tA.use_count() << endl;
    cout << tB.use_count() << endl;
    tA->pb = tB;
    tB->pa = tA;
    cout << tA.use_count() << endl;
    cout << tB.use_count() << endl;
}

void Test2() {
    cout << "Test shared_ptr && weak_ptr" << endl;
    shared_ptr<AW> tA (new AW());
    shared_ptr<BW> tB (new BW());
    cout << tA.use_count() << endl;
    cout << tB.use_count() << endl;
    tA->pb = tB;
    tB->pa = tA;
    cout << tA.use_count() << endl;
    cout << tB.use_count() << endl; //2
}

int main(int argc, char const *argv[])
{
    Test();
    Test2();
    return 0;
}
