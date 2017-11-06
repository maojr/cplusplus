// learn more about reference as a parameter & return value
#include <iostream>

class Object
{
public:
    Object(){
        std::cout << "constructor" << std::endl;
    };
    Object(const Object&){
        std::cout << "copy constructor" << std::endl;
    };
    ~Object(){
        std::cout << "destructor" << std::endl;
    };
    void print(){
        std::cout << "Object print" << std::endl;
    };
};

Object& foo(Object& obj)
{
    return obj;
}

int main(int argc, char const *argv[])
{
    Object obj1;
    Object& obj2 = foo(obj1);
    obj2.print();
    return 0;
}
