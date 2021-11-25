#include <string>
#include <iostream>
using namespace std;
class Employee{
public:
    Employee(){
        mysn = count++;
    }
    Employee(const string s){
        name = s;
        mysn = count++;
    }
    Employee(const Employee& e){
        name = e.name;
        mysn = count++;
    }
    Employee& operator=(const Employee& e){
        name = e.name;
        return *this;
    }

    const string getName(){
        return name;
    }

    const int getMysn(){
        return mysn;
    }
private:
    string name;
    int mysn;
    static int count;
};

int Employee::count = 0;

void f(Employee &s){
    cout << s.getName() << ":" << s.getMysn() << endl;
}

int main(int argc, char const *argv[])
{
    Employee a("feng");
    Employee b = a, c = b;
    f(a);f(b);f(c);
    return 0;
}
