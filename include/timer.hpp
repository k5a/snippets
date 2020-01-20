#ifndef __SNIPPETS_TIMER_HPP__
#define __SNIPPETS_TIMER_HPP__

#include <chrono>
#include <ctime>
#include <iostream>

namespace snippets {
class Timer {
  using Clock = std::chrono::steady_clock;
  using TimePoint = std::chrono::time_point<Clock>;

 public:
  Timer() {
    cpu_start_time_ = std::clock();
    start_time_ = Clock::now();
  }
  ~Timer() {
    auto end_time = Clock::now();
    auto duration = std::chrono::duration<double, std::milli>(
        end_time - start_time_).count();
    auto cpu_duration =
        1000.0 * (std::clock() - cpu_start_time_) / CLOCKS_PER_SEC;
    std::cout << "Time passed: " << duration << " ms\n";
    std::cout << "CPU time used: " << cpu_duration << " ms\n";
  }

 private:
  TimePoint start_time_;
  std::clock_t cpu_start_time_;
};
}

#endif  //__SNIPPETS_TIMER_HPP__
