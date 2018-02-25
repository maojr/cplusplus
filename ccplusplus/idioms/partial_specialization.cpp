// partial template specialization
// Allows customizing class templatesfor a given category of template arguments
// Class templates can be partially specialized, and the resulting class is still a
// template.
// partial template specialization - interviewed at xiaomi.inc
#include <iostream>

template <typename T>
struct Type {
    Type() {
        std::cout << "template <typename T>" << std::endl;
        std::cout << "struct Type" << std::endl;
    }
};

// Template partial specialization for pointer types
template <typename T>
struct Type<T*> {
    Type() {
        std::cout << "template <typename T>" << std::endl;
        std::cout << "struct Type<T*>" << std::endl;
    }
};

int main()
{
    Type<int>();
    Type<int*>();
    return 0;
}
