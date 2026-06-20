#include <cstdio>
#include <string>

class PlanetOfTheSolarSystem {
  public:
    static std::string our_star;
    std::string planet_name;

    PlanetOfTheSolarSystem(std::string n) {
      this->planet_name = n;
    }

    std::string get_planet_name() {
      return this->planet_name;
    }
};

std::string PlanetOfTheSolarSystem::our_star{ "Sun (other name is Sol)" };

void print_planets_star(std::string planet_name, std::string star_of_the_planet) {
  printf("Star of the %s is %s\n", planet_name.c_str(), star_of_the_planet.c_str());
}

int main() {
  PlanetOfTheSolarSystem venus{ "Venus" };
  PlanetOfTheSolarSystem earth{ "Earth" };

  print_planets_star(venus.get_planet_name(), venus.our_star);
  print_planets_star(earth.get_planet_name(), earth.our_star);

  return 0;
}