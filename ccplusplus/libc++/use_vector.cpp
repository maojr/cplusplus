#include <vector>
#include <iostream>

class Empty
{
public:
    Empty(int val)
    {
        this->val = val;
        std::cout << "Empty():" << val << std::endl;
    }
    Empty(const Empty& e)
    {
        val = e.val;
        std::cout << "Empty(const Empty&):" << val << std::endl;
    }
    ~Empty()
    {
        std::cout << "~Empty():" << val << std::endl;
    }
    void print() const
    {
        std::cout << "Val:" << val << std::endl;
    }
private:
    int val;
};

int main()
{
    std::vector<Empty> v;
    // 避免 v.size() 从1变为2的时候, v的capacity() double, 同时调用v内元素的拷贝构造函数
    // 影响对 emplace_back 和 push_back 方法的比较
    v.reserve(10);

    v.emplace_back(1);
    // Empty(2)为一个临时对象，首先完成销毁
    v.push_back(Empty(2));

    for(auto const& empty : v)
        empty.print();

    return 0;
}