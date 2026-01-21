#include <nanobench.h>

#include <hello.hpp>

int main() {
  ankerl::nanobench::Bench bench;
  bench.title("stub");
  bench.run("hello", [] { (void)hello(); });
  return 0;
}
