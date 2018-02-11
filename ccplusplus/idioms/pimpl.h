#ifndef PIMPL_H_
#define PIMPL_H_
#include <memory>

class MyClassImpl;
class MyClass
{
public:
    MyClass(const MyClass& rhs);
    MyClass& operator=(const MyClass& rhs);

    void DoSth();
    void DoConst() const;

private:
    std::unique_ptr<MyClassImpl> pImpl;
};

#endif // PIMPL_H_
