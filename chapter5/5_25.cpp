#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    for (int i, j; cout << "input two numbers", cin >> i >> j;)
    {
        try
        {
            if (j == 0)
            {
                throw runtime_error("divisor is 0");
            }
            cout << i / j << endl;
        }
        catch (runtime_error e)
        {
            std::cerr << e.what() << "\n try again ? y or n" << '\n';
            char c;
            cin >> c;
            if (!cin || c == 'n')
            {
                break;
            }
        }
    }
    return 0;
}
