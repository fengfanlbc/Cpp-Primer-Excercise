#include <string>
#include <iostream>
#include <memory>

int main(int argc, char const *argv[])
{
    std::unique_ptr<std::string> p1(new std::string("hello"));
    std::cout << *p1 << std::endl; 
    //std::unique_ptr<std::string> p2 = p1;
    p1.reset();
    return 0;
}
