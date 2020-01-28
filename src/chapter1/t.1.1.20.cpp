#include <cmath>
#include <iostream>

using IntType = unsigned int;
using FloatType = double;

FloatType LogFact(IntType n) {
  if (n == 0 || n == 1) {
    return 0;
  }
  return std::log(n) + LogFact(n - 1);
}

int main() {
  for (auto i = 0; i < 10; ++i) {
    std::cout << "Log(" << i << "!) = " << LogFact(i) << std::endl;
  }
  return 0;
}
