// 知乎上的一个问题:
// https://www.zhihu.com/question/65133985?utm_medium=social&utm_source=wechat_session
// 当一个类对象作为一个参数传入函数, 会通过拷贝构造函数
#include <iostream>
using namespace std;

class Stat
{
public:
    Stat(int r = 0):y(r)
    {
        cout << "constructor - " << y << endl;
    };
    Stat(const Stat& a):y(3 * a.y)
    {
        // y = 3 * a.y;
        cout << "copy constructor - " << y <<endl;
    }
    ~Stat()
    {
        cout << "destructor - " << y << endl;
    }
private:
    int y;
};

// an empty function with value parameter
// with generate a temporary Stat object
void show1(Stat o)
{
}

// an empty function with reference parameter
void show2(Stat& o)
{
}

int main()
{
    Stat ob1(5), ob2(ob1);
    show1(ob2);
    show2(ob2);
    return 0;
}