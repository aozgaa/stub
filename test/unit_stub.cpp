#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <hello.hpp>

TEST_CASE("hello returns expected string") {
  CHECK(hello() == "hello world\n");
}
