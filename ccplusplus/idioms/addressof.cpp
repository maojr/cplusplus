#include <memory>
#include <iostream>

class Nonaddressable
{
private:
    void operator&() const;
};

template <typename T>
T* addressof(T& v)
{
    return reinterpret_cast<T*>(&const_cast<char&>(reinterpret_cast<const volatile char &>(v)));
}

int main()
{
    Nonaddressable na;
    // Nonaddressable *p = &na; // compile error, & operator is private
    std::cout << addressof(na) << std::endl;
    std::cout << addressof<Nonaddressable>(na) << std::endl;
    std::cout << std::addressof(na) << std::endl; // std::addressof is introduced in c++11 <memory>
    return 0;
}
