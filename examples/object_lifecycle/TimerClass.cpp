#include <cstdio>
#include <sys/time.h>
#include <unistd.h>

class TimerClass {
  public:
    TimerClass() {
      timeval now;
      if (gettimeofday(&now, nullptr) == 0) {
        timestamp = now.tv_sec;
      }
    }

    ~TimerClass() {
      timeval now;
      if (gettimeofday(&now, nullptr) == 0) {
        printf("Lifetime of the timer(in seconds) >> %ld\n", now.tv_sec - timestamp);
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
  usleep(5000000);
}