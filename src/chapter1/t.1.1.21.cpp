#include <iostream>
#include <limits>
#include <sstream>
#include <string>

bool TestStreamError(const std::istream& s) { return !s.eof() && !s.bad(); }

bool HandleOperationFailure(std::istream& s) {
  if (s.fail()) {
    s.clear();
    s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
  }
  return true;
}

int main() {
  std::string line, name;
  int first, second;

  while (true) {
    std::cout << "Please enter the name, two numbers and press enter: ";
    std::cin >> name;
    if (!TestStreamError(std::cin)) {
      break;
    } else if (!HandleOperationFailure(std::cin)) {
      continue;
    }

    std::cin >> first;
    if (!TestStreamError(std::cin)) {
      break;
    } else if (!HandleOperationFailure(std::cin)) {
      continue;
    }
    std::cin >> second;
    if (!TestStreamError(std::cin)) {
      break;
    } else if (!HandleOperationFailure(std::cin)) {
      continue;
    }
    std::cout << name << ": " << first << "/" << second << " = "
              << double(first) / second << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return 0;
}
