#include <functional>
#include <iostream>

class Penguin {
public:
  void run() { std::cout << "running" << std::endl; };
  void swim() { std::cout << "swimming" << std::endl; };
};

class Sparrow {
public:
  void fly() { std::cout << "flying" << std::endl; };
  void run() { std::cout << "running" << std::endl; };
};

typedef std::function<void()> FlyCallback;
typedef std::function<void()> RunCallback;
typedef std::function<void()> SwimCallback;

class Foo {
public:
  Foo(FlyCallback flyCb, RunCallback runCb) : flyCb_(flyCb), runCb_(runCb) {}

private:
  FlyCallback flyCb_;
  RunCallback runCb_;
};

class Bar {
public:
  Bar(SwimCallback swimCb, RunCallback runCb)
      : swimCb_(swimCb), runCb_(runCb) {}

private:
  SwimCallback swimCb_;
  RunCallback runCb_;
};

int main() {
  Sparrow s;
  Penguin p;
  Foo foo(std::bind(&Sparrow::fly, &s), std::bind(&Sparrow::run, &s));
  Bar bar(std::bind(&Penguin::swim, &p), std::bind(&Penguin::run, &p));
  return 0;
}
