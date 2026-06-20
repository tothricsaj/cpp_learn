#include <iostream>
#include <functional>
#include <string>

using namespace std;

class Animal {
  public:
    virtual void animalSound() {
      cout << "Make some noise..." << endl;
    }
};

class Dog: public Animal {
  public:
    void animalSound() override {
      cout << "Woof, wooff!!!!" << endl;
    }
};

class Cat: public Animal {
  public:
    void animalSound() override {
      cout << "Meow...asshole" << endl;
    }
};

template <typename T>
T add(T a, T b) {
  return a + b;
}

template <typename T>
class Box {
  public:
  T value;
  Box(T v) {
    value = v;
  }
  
  void show() {
    cout << "Value >> " << value << "\n";
  }
};

int main() {
  Animal *a;
  Dog d;
  Cat c;

  a = &d;
  a->animalSound();

  a = &c;
  a->animalSound();

  cout << add<int>(5, 3) << endl;
  cout << add<float>(5.343, 3.14) << endl; 

  Box<int> intBox(33);
  Box<string> strBox("Hello");

  intBox.show();
  strBox.show();

  return 0;
}