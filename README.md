# Leetcode solutions in C++

![build-and-test](https://github.com/litzh/leetcode-cpp/actions/workflows/build-and-test.yml/badge.svg)

## Build

```bash
# Install toolchain
# MacOS
brew install llvm cmake ninja
export PATH="$(brew --prefix)/opt/llvm/bin:$PATH"
# Debian
pip install cmake ninja
wget -qO- https://apt.llvm.org/llvm-snapshot.gpg.key \
    | sudo tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc
echo 'deb http://apt.llvm.org/bookworm/ llvm-toolchain-bookworm main' \
    | sudo tee /etc/apt/sources.list.d/llvm.list
sudo apt update
sudo apt install -y clang clang-tidy llvm

# Clone repo
git clone https://github.com/litzh/leetcode-cpp.git

# Generate Ninja
cd leetcode-cpp
cmake -B build \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_CXX_FLAGS="-fprofile-instr-generate -fcoverage-mapping" \
    -DCMAKE_C_FLAGS="-fprofile-instr-generate -fcoverage-mapping" \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DCMAKE_C_COMPILER=clang \
    -G Ninja

# Build tests
cmake --build build --config Debug

# Run tests with LLVM profiler
cd build
LLVM_PROFILE_FILE="tests.profraw" ./tests

# Generate coverage report
llvm-profdata merge -sparse tests.profraw -o tests.profdata
llvm-cov show ./tests \
    -ignore-filename-regex="build/|include/|test/" \
    -instr-profile=tests.profdata \
    -format=html \
    -output-dir=cov-html

# View report
# MacOS
open cov-html/index.html
# HTTP server
python -m http.server -d cov-html
```
