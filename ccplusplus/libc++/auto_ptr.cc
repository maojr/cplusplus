// auto_ptr is deprecated because of it's copy constructor
// auto_ptr cannot be used in STL containers because it has a copy constructor
// that does not meet requirements of container copyconstructable.
#include <iostream>
#include <memory>

#include <assert.h>

using namespace std;

class Empty{
 public:
    Empty(string name) {
        this->name = name;
        std::cout << "Empty class " << this->name << " created." << std::endl;
    }
    ~Empty() {
        std::cout << "Empty class " << this->name << " destoryed." << std::endl;
    }
    void print() {
        std::cout << "Class name: " << this->name << std::endl;
    }
 private:
    string name;
};

void showEmpty(auto_ptr<Empty> p) {
    p->print();
    std::cout << "showEmpty scope: objects in showEmpty scope will destroy after this." << std::endl;
}

int main()
{
    auto_ptr<Empty> p(new Empty("p"));
    auto_ptr<Empty> r(new Empty("r"));
    auto_ptr<Empty> q;

    showEmpty(r);
    assert(r.get() == NULL);

    cout << "after initialization:" << endl;
    cout << " p: " << p.get() << endl;
    cout << " q: " << q.get() << endl;

    q = p;
    cout << "after assigning auto pointers:" << endl;
    cout << " p: " << p.get() << endl;
    cout << " q: " << q.get() << endl;

    std::cout << "main scope: objects in main scope will destroy after this." << std::endl;
    return 0;
}
