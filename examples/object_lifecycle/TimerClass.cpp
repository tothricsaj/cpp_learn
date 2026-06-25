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

      set_name_to_zero();
    }

    TimerClass(const TimerClass& t_other) :
      timestamp { t_other.timestamp }
    {
      set_name_to_zero();
    }

    TimerClass& operator=(const TimerClass& t_other) {
      if (&t_other == this) return *this;

      timestamp = t_other.timestamp;

      set_name_to_zero();
      
      return *this;
    }

    TimerClass(TimerClass&& t_other) noexcept :
      timestamp { t_other.timestamp }
    {
      t_other.timestamp = 0;
      set_name_to_zero();
    }

    TimerClass& operator=(TimerClass&& t_other) {
      timestamp = t_other.timestamp;
      t_other.timestamp = 0;

      // set_name_to_zero();

      // const char* move_ltr = "Moved ";
      // char* new_name = new char[30];

      // std::strcat(new_name, move_ltr);
      // std::strcat(new_name, t_other.name);     
      // std::strncpy(name, new_name, 30);

      return *this;
    }

    ~TimerClass() {
      if (timestamp != 0) {
        timeval now;
        if (gettimeofday(&now, nullptr) == 0) {
          printf("Lifetime of %s timer(in seconds) >> %ld\n", name, now.tv_sec - timestamp);
        }
      } else {
        printf("%s was moved-from\n", name);
      }

      delete[] name;
    }

    void print() {
      if(strlen(name) == 0) {
        add_name("unamed");
      }

      printf("%s timestamp >> %ld\n", name, timestamp);
    }

    bool add_name(const char* x) {
      std::strncpy(name, x, 6);

      return true;
    }

  private:
    time_t timestamp;
    char* name;
    size_t name_size;

    void set_name_to_zero() {
      name = new char[30];
      name[0] = 0;
    }
};

int main() {
  TimerClass t_1{};
  TimerClass t_2{ t_1 };

  usleep(1000000);

  TimerClass t_3{};

  t_1.add_name("t_1");
  t_2.add_name("t_2");
  t_3.add_name("t_3");

  t_1.print();
  t_2.print();
  t_3.print();

  t_3 = std::move(t_2);

  printf("t_3 after move assignment >> \n\n");
  t_3.print();
  printf("\n");
}