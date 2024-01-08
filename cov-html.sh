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
LLVM_PROFILE_FILE="default.profraw" ./tests

llvm-profdata merge -sparse default.profraw -o default.profdata

llvm-cov show ./tests \
    -ignore-filename-regex="build/|include/|test/" \
    -instr-profile=default.profdata \
    -format=html \
    -output-dir=cov-html

w3m cov-html/index.html

popd
