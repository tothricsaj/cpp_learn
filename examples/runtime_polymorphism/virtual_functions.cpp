#include <cstdio>

class Base {
  public:
    virtual const char* msg() const {
      return "hey hey hey";
    }
};

class Derived : public Base {
  public:
    const char* msg() const override {
      return "hello hello hello";
    }
};

int main() {
  Base b;
  Derived d;

  // printf("\n--------------RESULT--------------\n\n");
  printf("Base class message >> %s\n", b.msg());
  printf("Derived class message >> %s\n", d.msg());
}