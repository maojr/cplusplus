// http://cppisland.com/?p=501
#include <iostream>
#include <memory>
#include <mutex>

class Singleton {
public:
  static Singleton &getInstance() {
    std::call_once(Singleton::onceFlag,
                   []() { instance.reset(new Singleton); });
    return *(instance.get());
  }
  ~Singleton() { std::cout << "~Singleton()" << std::endl; };

private:
  Singleton() { std::cout << "Singleton()" << std::endl; };
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;

  static std::unique_ptr<Singleton> instance;
  static std::once_flag onceFlag;
};

std::unique_ptr<Singleton> Singleton::instance;
std::once_flag Singleton::onceFlag;

int main(int argc, char const *argv[]) {
  Singleton &s1 = Singleton::getInstance();
  Singleton &s2 = Singleton::getInstance();
  return 0;
}
