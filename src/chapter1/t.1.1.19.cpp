#include <timer.hpp>

#include <iostream>

using IntType = unsigned int;

IntType RecursiveFibonacci(IntType n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }

  return RecursiveFibonacci(n - 2) + RecursiveFibonacci(n - 1);
}

IntType Fibonacci(IntType n) {
  if (n == 0 || n == 1) {
    return n;
  }

  IntType a = 0, b = 1, c;
  for (auto i = 2; i <= n; ++i) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int main() {
  for (unsigned int i = 0; i < 100; ++i) {
    std::cout << "Calculating Fibonacci(" << i << "): ";
    snippets::Timer timer{};
    std::cout << Fibonacci(i) << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
