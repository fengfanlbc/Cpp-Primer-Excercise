#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void elimdumps(vector<string> &vs){
    sort(vs.begin(), vs.end());
    auto newEnd = unique(vs.begin(), vs.end());
    vs.erase(newEnd, vs.end());
}

void biggies(vector<string> &vs, size_t sz) {
    elimdumps(vs);
    stable_sort(vs.begin(), vs.end(), [](string const &lhs, string const & rhs){return lhs.size() < rhs.size();});
    auto wc = find_if(vs.begin(), vs.end(), [sz](string const &s){return s.size() >= sz;});
    for_each(wc, vs.end(), [](string const &s){cout << s << " " << endl;});

}

int main()
{
	std::vector<std::string> v
	{
	"1234", "1234", "1234", "hi~", "alan", "alan", "cp"
};
	std::cout << "ex10.16: ";
	biggies(v, 3);
	std::cout << std::endl;

	return 0;
}