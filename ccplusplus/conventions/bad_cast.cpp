// dynamic_cast conversion
// Safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy
// If the cast fails and new_type is a pointer type, it returns a null pointer of that type. 
// If the cast fails and new_type is a reference type, it throws an exception that matches a handler of type std::bad_cast.

#include <iostream>
#include <typeinfo>

struct Bar { virtual ~Bar() {} };
struct Foo : Bar { virtual ~Foo() {} };

int main()
{
    Bar b;
    try {
        Foo& f = dynamic_cast<Foo&>(b);
    } catch (const std::bad_cast& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
