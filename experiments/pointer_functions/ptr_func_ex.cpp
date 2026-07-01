#include <iostream>

void copy_value(int x) {
  std::cout << "x before modification in func >> " << x << std::endl;
  x++;
  std::cout << "x after modification in func >> " << x << std::endl;
}

void touch_the_value(int& y) {
  std::cout << "y before modification in func >> " << y << std::endl;
  y++;
  std::cout << "y after modification in func >> " << y << std::endl;
}

void ptr_fun(int* z) {
  if(z) {
    std::cout << "z before modification in func >> " << *z << std::endl;
    *z = 12;
    std::cout << "z after modification in func >> " << *z << std::endl;
  } else {
    std::cout << "Probalby, z is a nullptr\n";
  }
}

int main() {
  int x = 1;
  copy_value(x);
  std::cout << "x is outside from func >> " << x << std::endl; 

  std::cout << "\n####################################\n\n"; 

  int y = 1;
  touch_the_value(y);
  std::cout << "y is outside from func >> " << y << std::endl; 

  std::cout << "\n####################################\n\n"; 

  int* z = &x;
  ptr_fun(z);
  std::cout << "z is outside from func >> " << *z << std::endl; 
  std::cout << "x is outside from func >> " << x << std::endl; 
}