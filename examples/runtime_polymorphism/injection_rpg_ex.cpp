#include <cstdio>

class Attack {
  public:
    const virtual char* make_attack() const =0;

    virtual ~Attack() = default; 
};

class ArrowAttack : public Attack {
  public:
    const char* make_attack() const override {
      return "shoot the arrow -->";
    }
};

class SwordAttack : public Attack {
  public:
    const char* make_attack() const override {
      return "swing the sword";
    }
};

class Hero {
  public:
    Hero(Attack* attack_handler) : attack_handler{ attack_handler } {};

    void attack() {
      printf("Hero attacks and %s\n", attack_handler->make_attack());
    }

  private:
    Attack* attack_handler;
};

int main() {
  ArrowAttack* arrow_attack{ new ArrowAttack };
  SwordAttack* sword_attack{ new SwordAttack };

  Hero arrow_hero{ arrow_attack };
  Hero sword_hero{ sword_attack };

  arrow_hero.attack();
  sword_hero.attack();

  delete arrow_attack;
  delete sword_attack;
}