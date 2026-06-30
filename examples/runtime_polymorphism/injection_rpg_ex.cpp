#include <cstdio>

class Attack {
  public:
    Attack(const char* attack_name) : name{ attack_name } {}
    const char* name;
    virtual const char* make_attack() const =0;

    virtual ~Attack() = default; 
};

class ArrowAttack : public Attack {
  public:
    ArrowAttack() : Attack{ "arrow" } {}

    const char* make_attack() const override {
      return "shoot the arrow -->";
    }
};

class SwordAttack : public Attack {
  public:
    SwordAttack() : Attack{ "sword" } {}

    const char* make_attack() const override {
      return "swing the sword";
    }
};

class Hero {
  public:
    Hero(Attack* attack_handler) : attack_handler{ attack_handler } {};

    void change_weapon(Attack* attack_handler_ptr) {
      attack_handler = attack_handler_ptr;

      printf("The hero changed the weapon to %s\n", attack_handler->name);
    }

    void attack() {
      printf("Hero attacks and %s\n", attack_handler->make_attack());
    }

  private:
    Attack* attack_handler;
};

int main() {
  ArrowAttack arrow_attack;
  SwordAttack sword_attack;

  Hero hero{ &arrow_attack };

  hero.attack();
  hero.change_weapon(&sword_attack);
  hero.attack();
}