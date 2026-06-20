#include <cstdio>
#include <stdio.h>
#include <string>

class Planet {
  public:
    std::string name;

    Planet(std::string n) {
      this->name = n;
    }

    std::string get_planet_name() {
      return this->name;
    }
};

int main() {
  Planet earth{ "Earth" };

  printf("The planet name is: %s\n", earth.get_planet_name().c_str());

  return 0;
}