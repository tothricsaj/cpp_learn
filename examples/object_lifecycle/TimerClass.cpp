#include <cstdio>
#include <cstring>
#include <sys/time.h>
#include <unistd.h>
#include <utility>

class TimerClass {
  public:
    TimerClass() {
      timeval now;
      if (gettimeofday(&now, nullptr) == 0) {
        timestamp = now.tv_sec;
      }

      name = new char[3];
      name[0] = 0;
    }

    // TimerClass(const TimerClass& t_other) :
    //   timestamp { t_other.timestamp }
    // {}

    // TimerClass& operator=(const TimerClass& t_other) {
    //   if (&t_other == this) return *this;

    //   timestamp = t_other.timestamp;
      
    //   return *this;
    // }

    // TimerClass(TimerClass&& t_other) noexcept :
    //   timestamp { t_other.timestamp }
    // {
    //   t_other.timestamp = 0;
    // }

    // TimerClass& operator=(TimerClass&& t_other) {
    //   timestamp = t_other.timestamp;
    //   t_other.timestamp = 0;

    //   return *this;
    // }

    ~TimerClass() {
      timeval now;
      if (gettimeofday(&now, nullptr) == 0) {
        printf("Lifetime of %s timer(in seconds) >> %ld\n", name, now.tv_sec - timestamp);
      }

      delete[] name;
    }

    void print() {
      printf("timestamp >> %ld\n", timestamp);
    }

    bool add_name(const char* x) {
      std::strncpy(name, x, 3);

      return true;
    }

  private:
    time_t timestamp;
    char* name;
    size_t name_size;
};

int main() {
  TimerClass t_1{};
  TimerClass t_2{};

  usleep(1000000);

  TimerClass t_3{};

  t_1.add_name("t_1");
  t_2.add_name("t_2");
  t_3.add_name("t_3");

  printf("t_1 >> ");
  t_1.print();
  printf("t_2 >> ");
  t_2.print();
  printf("t_3 >> ");
  t_3.print();

  // t_3 = std::move(t_2);

  // printf("t_3 after move assignment >> ");
  // t_3.print();
}