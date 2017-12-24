#include <map>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main(int argc, char const *argv[])
{
    std::map<int, int> v;
    v.insert(std::pair<int, int>(1, 1));
    v.insert(std::pair<int, int>(1, 2));
    std::cout << "std::map :" << std::endl;
    std::cout << "map[1] : " << v[1] << std::endl;
    std::cout << "map size(): " << v.size() << std::endl;

    std::multimap<int, int> m;
    m.insert(std::pair<int, int>(1, 1));
    m.insert(std::pair<int, int>(1, 2));
    std::cout << "std::multimap :" << std::endl;
    // std::cout << "map[1] : " << m[1] << std::endl; // type 'std::multimap<int, int>' does not provide a subscript operator
    std::cout << "map size(): " << m.size() << std::endl;

    return 0;
}
