#include <cstdio>

void test_static() {
  static int count{};
  int other_count{};

  count++;
  other_count++;

  printf("The test_static func is called %d times!!!\n", count);
  printf("This is other_count >> %d\n", other_count);
  printf("-------------------------------------------------------\n");
}

int main() {
  test_static();
  test_static();
  test_static();

  return 0;
}
