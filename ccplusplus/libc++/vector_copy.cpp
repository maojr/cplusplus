#include <vector>
#include <iostream>

class Empty
{
public:
    Empty() {
        std::cout << "Empty()" << std::endl;
    }
    // Empty(Empty& empty) is not ok in gcc-4.7, const is required
    Empty(const Empty& empty) {
        std::cout << "Empty(Empty& empty)" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<Empty> v;
    v.reserve(3);
    std::cout << "capacity: " << v.capacity() << " size: " << v.size() << " sizeof vector: " << sizeof(v) << std::endl;
    v.emplace_back();
    std::cout << "capacity: " << v.capacity() << " size: " << v.size() << " sizeof vector: " << sizeof(v) << std::endl;
    v.emplace_back();
    std::cout << "capacity: " << v.capacity() << " size: " << v.size() << " sizeof vector: " << sizeof(v) << std::endl;
    v.emplace_back();
    std::cout << "capacity: " << v.capacity() << " size: " << v.size() << " sizeof vector: " << sizeof(v) << std::endl;

    // vector copy -- deep copy
    std::cout << "----- std::vector<Empty> v2 = v -----" << std::endl;
    std::vector<Empty> v2 = v;
    return 0;
}