<Add project description here>

# Environment Setup

Dependencies:
* `doctest` (unit testing)
* `nanobench` (benchmarking)

Dependencies can come from any environment manager (e.g., system packages, pixi, conda),
so long as
[config mode](https://cmake.org/cmake/help/latest/command/find_package.html#id18)
scripts can be found with
[find_package()](https://cmake.org/cmake/help/latest/command/find_package.html).

## Vendoring Dependencies

As a convenience, this repo includes git submodules for vendoring `doctest` and `nanobench`.
Initialize and install them (within this repo under `env/`) as follows:
```
git submodule update --init --recursive # init submodules
cmake -P cmake/prepare_vendored.cmake   # build + install modules in env/
```

Then configure with the preset that points `CMAKE_PREFIX_PATH` at `env/`:
```
cmake -S . -B --build --preset vendored_env [additional args]..
```

# Build

Build with cmake normally, eg:
```
cmake -S . -B build --preset vendored_env -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -GNinja
cmake --build build
```

# Run
```
build/main
```

# Unit Testing
Unit tests use `doctest` and are built when `BUILD_TESTING=ON` (default).
Provide it via your environment and then use regular cmake/ctest conventions:
```
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
ctest --test-dir build
```

# Benchmarking
Benchmarks use `nanobench` and are built when `BUILD_BENCHMARKING=ON` (default).
```
cmake -S . -B build -DBUILD_BENCHMARKING=ON
cmake --build build --target benchmain
build/benchmain
```
