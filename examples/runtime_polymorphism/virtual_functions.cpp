#include <cstdio>

class Base {
  public:
    virtual const char* msg() const {
      return "hey hey hey";
    }
};

class Derived : public Base {};

int main() {
  Base b;
  Derived d;

  printf("Base class message >> %s\n", b.msg());
  printf("Derived class message >> %s\n", d.msg());
}