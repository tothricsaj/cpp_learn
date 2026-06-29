#include <cstdio>

class BaseMsg {
  public:
    virtual const char* msg() const =0;
};

class HelloMsg : public BaseMsg {
  public:
    const char* msg() const override {
      return "hello hello hello";
    }
};

class ChioMsg : public BaseMsg {
  public:
    const char* msg() const override {
      return "chio chio chio";
    }
};

void printMsg(BaseMsg& msgHolder) {
  printf("The message is >> %s\n", msgHolder.msg());
}

int main() {
  HelloMsg hello;
  ChioMsg chio;

  BaseMsg& base = chio;

  printMsg(hello);
  printMsg(chio);
  printMsg(base);
}