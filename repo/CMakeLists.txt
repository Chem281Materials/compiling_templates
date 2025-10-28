cmake_minimum_required(VERSION 3.14)

# Project name and version
project(TemplateTest VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED)

# Add the executable
add_executable(templatetest src/main.cpp)

# Link against the MPIWrapper library
find_package(CustomVector 1.0 REQUIRED)
target_link_libraries(templatetest PUBLIC CustomVector::CustomVector)
