// extend std::list

#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class OrderedList : public std::list<T>
{
public:
    void add(const T& v) {
        auto it = std::lower_bound(this->begin(), this->end(), v);
        this->insert(it, v);
    }
};

int main(int argc, char const *argv[])
{
    OrderedList<int> list;

    list.add(3);
    list.add(1);
    list.add(5);

    for (auto & val : list)
        std::cout << val << std::endl;
    return 0;
}
