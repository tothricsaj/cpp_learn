#include <iostream>

class Member {
  public:
    Member() { std::cout << "Member ctor\n"; }
    ~Member() { std::cout << "Member dtor\n"; }
};

class Owner {

  Member member;

  public:
    Owner() { std::cout << "Owner ctor\n"; }
    ~Owner() { std::cout << "Owner dtor\n"; }
};

int main() {
  Owner o;
}