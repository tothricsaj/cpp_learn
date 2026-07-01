#include <cstdio>

void foo(const int& counter) {
  auto& hibernation_counter = const_cast<int&>(counter);

  hibernation_counter++;
  printf("Hibernation_counter >> %d\n", hibernation_counter);
}

int main() {
  int foo_counter = 0;
  foo(foo_counter);

  printf("foo_counter >> %d\n", foo_counter);
}