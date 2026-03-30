#!/bin/bash

# Build the project using CMake
rm -rf build
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Compile the project
cd build && make
