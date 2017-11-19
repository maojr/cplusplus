//implement a queue with two stacks
// 360
#include <stack>
#include <iostream>

template <class T>
class Queue
{
public:
    Queue() = default;
    ~Queue() = default;

    bool empty() const {
   	    return pop_stack.empty() && push_stack.empty();
    }

    void push(T t) {
        push_stack.push(t);
    }

    void pop() {
        if (this->empty())
            return;
        if (pop_stack.empty())
            while(!push_stack.empty()) {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        pop_stack.pop();
    }

    T& top() {
        if (pop_stack.empty())
            while(!push_stack.empty()) {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        return pop_stack.top();
    }

private:
    std::stack<T> pop_stack;
    std::stack<T> push_stack;
};

int main(int argc, char const *argv[])
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    std::cout << q.top()  << std::endl;
    q.pop();
    std::cout << q.top()  << std::endl;
    std::cout << q.empty() << std::endl;

    return 0;
}
