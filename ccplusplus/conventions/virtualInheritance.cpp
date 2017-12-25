// virtual inheritance
// 虚继承: https://zh.wikipedia.org/wiki/%E8%99%9A%E7%BB%A7%E6%89%BF
// 虚继承: 是面向对象编程中的一种技术，是指一个指定的基类，在继承体系结构中.
// 将其成员数据实例共享给也从这个基类型直接或间接派生的其它类。
// 虚继承 is not 虚函数
//
#include <iostream>

class A
{
public:
    A() {
        std::cout << "A()" << std::endl;
    }
};

class B : public virtual A
{
public:
    B() {
        std::cout << "B()" << std::endl;
    }
};

class C : public virtual A
{
public:
    C() {
        std::cout << "C()" << std::endl;
    }
};

class D : public B, public C
{
public:
    D() {
        std::cout << "D()" << std::endl;
    }
};

// 多重继承中基类调用顺序和什么有关?
// public C, public B VS public B, public C
class D2 : public C, public B
{
public:
    D2() {
        std::cout << "D()" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    D d; // vs D2 d
    return 0;
}
