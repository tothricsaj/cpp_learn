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

    TimerClass(const TimerClass& t_other) :
      timestamp { t_other.timestamp }
    {}

    TimerClass operator=(const TimerClass& t_other) {
      if (&t_other == this) return *this;

      timestamp = t_other.timestamp;
      
      return *this;
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
  TimerClass t_1{};
  TimerClass t_2{ t_1 };

  usleep(5000000);

  TimerClass t_3{};

  printf("t_1 >> ");
  t_1.print();
  printf("t_2 >> ");
  t_2.print();
  printf("t_3 >> ");
  t_3.print();

  t_3 = t_2;

  printf("t_3 after copy assignment >> ");
  t_3.print();
}