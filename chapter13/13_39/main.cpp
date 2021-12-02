#include "13_39.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    StrVec s;
    std::string a = "aa";
    s.push_back(a);
    std::cout << "strvec size:" << s.size() << " capacity:" << s.capacity() << std::endl;

    std::string b = "bb";
    std::string c = "cc";
    s.push_back(b);
    s.push_back(c);
    for (auto b = s.begin(); b != s.end(); b++){
        std::cout << *b << std::endl; 
    }
    std::cout << "strvec size:" << s.size() << " capacity:" << s.capacity() << std::endl;

    
    return 0;
}
