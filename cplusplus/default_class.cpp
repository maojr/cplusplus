// Effective C++ 05:
// Know what functions C++ silently writes and calls
// 当声明一个 C++ 类的时候，如果代码中没有自定义，那么编译器会自动(implicit)
// 声明 构造函数, 析构函数，拷贝构造函数，赋值运算符。如果在类的声明
// 中定义了，那么编译器就不再进行定义。
//
// class Empty { };
//     ↓
// class Empty {
// public:
//  Empty() { ... }
//  Empty(const Empty& rhs) { ... }
//  ~Empty() { ... }
//  Empty& operator=(const Empty& rhs) { ... }
// };
//
// Class a = b 和 Class a(b)都调用 Class 的拷贝构造函数
//
// 如果你打算在一个内含有 reference 或 const 成员的 class 内支持赋值操作(assignment)
// 你必须自己定义 copy assignment 操作符。
// compiles warnning:
// error: cannot define the implicit copy assignment operator for 'NameObject<int>', because non-static reference member 'nameValue' cannot use copy assignment operator
// error: cannot define the implicit copy assignment operator for 'NameObject<int>', because non-static const member 'objectName' cannot use copy assignment operator
#include <iostream>

class Empty
{
public:
    Empty() { std::cout << "Empty()" << std::endl; }
    Empty(const Empty& rhs) { std::cout << "Empty(const Empty& rhs)" << std::endl; }
    ~Empty() { std::cout << "~Empty()" << std::endl; }
    void operator=(const Empty& rhs) { std::cout << "Empty& operator=(const Empty& rhs)" << std::endl; }
};

template<class T>
class NameObject
{
public:
    NameObject(std::string& name, const T& value):nameValue(name), objectName(value){};
private:
    std::string& nameValue;
    const T objectName;
    // std::string nameValue;
    // T objectName;
};

int main()
{
    Empty a;
    Empty b(a);
    Empty c = b;
    Empty d;
    d = c;

    // std::string newDog("newDog");
    // std::string oldDog("oldDog");
    // NameObject<int> p(newDog, 17);
    // NameObject<int> s(oldDog, 11);
    // // will have errors when compiling
    // p = s;

    return 0;
}
