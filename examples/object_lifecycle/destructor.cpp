#include <cstdio>

struct Earth
{
  ~Earth() {
    printf("Making way for hyperspace bypass$$$!!!\n");
  }
};

int main() {
  float gettysburg{};
  float* gettysburg_address = &gettysburg;

  printf("%f\n", *gettysburg_address);
  printf("%p\n", static_cast<void*>(gettysburg_address));

  *gettysburg_address = 12234;

  printf("%f\n", *gettysburg_address);
  printf("%p\n", static_cast<void*>(gettysburg_address));
  printf("%p\n", static_cast<void*>(&gettysburg));

  return 0;
}
