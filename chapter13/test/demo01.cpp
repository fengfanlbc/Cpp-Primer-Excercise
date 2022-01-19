#include <iostream>
#include <utility>
int main(int argc, char const *argv[])
{
    int i = 2;
    int &il = i;
    int &&rl = std::move(il);
    i = 4;
    std::cout << "left refrence: " << il << " ; right refrence:" << rl << std::endl; 
    return 0;
}
