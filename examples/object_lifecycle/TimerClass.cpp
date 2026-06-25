#include <cstdio>
#include <sys/time.h>

class TimerClass {
  public:
    TimerClass() {
      timeval now;
      if (gettimeofday(&now, nullptr) == 0) {
        timestamp = now.tv_sec;
      }
    }

    void print() {
      printf("timestamp >> %ld\n", timestamp);
    }

  private:
    time_t timestamp;
};

int main() {
  TimerClass t{};
  t.print();
}