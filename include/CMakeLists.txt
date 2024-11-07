cmake_minimum_required(VERSION 3.14)
project(Containers)

add_library(containers INTERFACE)
target_include_directories(containers .)
target_compile_features(containers cxx_std_17)
