// distinguish NULL, 0, nullptr
// url: http://airtrack.me/posts/2012/09/16/NULL%E3%80%810%E3%80%81nullptr/
#include <iostream>
#include <typeinfo>

void foo(int i) {
    std::cout << "int: " << i << std::endl;
}

void foo(int* i) {
    std::cout << "int*: " << i << std::endl;
}

int main() {
    std::cout << NULL << std::endl;
    std::cout << typeid(NULL).name() << std::endl; // l - In C++, the definition of NULL is 0
    // #undef NULL                     // NULL is defined 0L in cplusplus
    // std::cout << NULL << std::endl; // compile error appear after #undef
    // int *b = (void*)0; // compile error
    int* a = NULL;
    int *b = static_cast<int*>((void*)0); // it's ok
    int* c = nullptr;
    // foo(NULL); // error: call to 'foo' is ambiguous
    foo(nullptr); // it's ok. That's why nullptr is better than NULL
    return 0;
}
