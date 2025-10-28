cmake_minimum_required(VERSION 3.22)

# Project name and version
project(TemplateTest VERSION 1.0)

# Add the executable
add_executable(templatetest src/main.cpp)

# Specify the C++ standard
target_compile_features(templatetest PUBLIC cxx_std_14)

# Link against the CustomVector library
find_package(CustomVector 1.0 REQUIRED)
target_link_libraries(templatetest PUBLIC CustomVector::CustomVector)
