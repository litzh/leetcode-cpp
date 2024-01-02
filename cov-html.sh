#!/bin/bash
cmake -B build \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_CXX_FLAGS="-fprofile-instr-generate -fcoverage-mapping" \
    -DCMAKE_C_FLAGS="-fprofile-instr-generate -fcoverage-mapping" \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=yes \
    -G Ninja

cmake --build build --config Debug

pushd build
LLVM_PROFILE_FILE="tests.profraw" ./tests

llvm-profdata merge -sparse tests.profraw -o tests.profdata

llvm-cov show ./tests \
    -ignore-filename-regex="build/|include/|test/" \
    -instr-profile=tests.profdata \
    -format=html \
    -output-dir=cov-html

open cov-html/index.html

popd
