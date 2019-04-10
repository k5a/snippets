#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>

std::string ToBinarySS(int n) {
  std::ostringstream oss;
  while (n > 0) {
    oss << n % 2;
    n /= 2;
  }
  auto result = oss.str();
  std::reverse(std::begin(result), std::end(result));
  return result;
}

std::string ToBinaryS(int n) {
  std::size_t length = std::size_t(std::floor(std::log2(n) + 1));
  std::string result(length, '0');
  for (int i = 1; i <= length; ++i) {
    result[length - i] = '0' + (n % 2);
    n /= 2;
  }
  return result;
}

int main() {
  int n{0};
  std::cout << "Enter the number: ";
  std::cin >> n;
  std::cout << "String stream result: " << ToBinarySS(n) << std::endl;
  std::cout << "String result: " << ToBinaryS(n) << std::endl;
}
