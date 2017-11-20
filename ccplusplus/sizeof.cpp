#include <iostream>
using namespace std;

// C++ standard explictly prohibits 0 sized objects
class A {};

class B {
public:
    void b() {};
};

class C {
public:
    virtual void c() {};
};

class D {
public:
    char c;
};

class E {
public:
    short s;
};

class F {
public:
    int i;
};

class G {
public:
    int i;
    char c;
};

class C1 {
public:
    virtual void c1() {};
};

// multiple vptrs in multiple inheritance
class C2 : public C, C1 {};

int main(int argc, char* argv[]) {
    cout << "sizeof(A) : " << sizeof(A)  << endl;
    cout << "sizeof(B) : " << sizeof(B)  << endl;
    cout << "sizeof(C) : " << sizeof(C)  << endl;
    cout << "sizeof(C2): " << sizeof(C2) << endl;
    cout << "sizeof(D) : " << sizeof(D)  << endl;
    cout << "sizeof(E) : " << sizeof(E)  << endl;
    cout << "sizeof(F) : " << sizeof(F)  << endl;
    cout << "sizeof(G) : " << sizeof(G)  << endl;
    return 0;
}