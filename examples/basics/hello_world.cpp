#include <iostream>
#include <functional>
#include <string>

using namespace std;

class MyClass {
  private:
    int salery = 100;

  public:
    MyClass() {
      cout << "MyClass is created!!!!" << endl;
    }

    int mynum;
    string myString;
    void myMethod();

    int getSalery() {
      return salery;
    }

    void setSalery(int newSalery) {
      salery = newSalery;
    }

    friend void displaySalery(MyClass mc);
};

void MyClass::myMethod() {
  cout << "Hello world!" << endl;
}

void displaySalery(MyClass mc) {
  cout << mc.salery << endl;
}

int main() {
  MyClass myObj;

  myObj.mynum = 33;
  myObj.myString = "some text";

  cout << myObj.getSalery() << endl;

  myObj.setSalery(2343);
  displaySalery(myObj);
  
  return 0;
}