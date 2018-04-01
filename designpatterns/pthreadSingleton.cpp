// excerpt from
//《Linux 多线程服务端编程》
#include <iostream>
#include <pthread.h>

class Foo {
public:
  Foo() { std::cout << "Foo()" << std::endl; }
  ~Foo() { std::cout << "~Foo()" << std::endl; }
};

template <typename T> class Singleton {
public:
  static T &instance() {
    pthread_once(&ponce_, &Singleton::init);
    return *value_;
  }

private:
  Singleton();
  ~Singleton();

  static void init() { value_ = new T(); }

private:
  static pthread_once_t ponce_;
  static T *value_;
};

template <typename T> pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template <typename T> T *Singleton<T>::value_ = NULL;

int main(int argc, char const *argv[]) {
  Foo &foo = Singleton<Foo>::instance();
  Foo &bar = Singleton<Foo>::instance();
  return 0;
}
