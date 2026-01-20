#include <hello.hpp>

#include <iostream>

int main() {
  if (hello() == "hello world\n") {
    std::cout << "OK\n";
    return 0;
  }
  std::cerr << "FAIL: hello()\n";
  return 1;
}
