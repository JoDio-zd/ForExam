cmake_minimum_required(VERSION 3.14)
project("考研")
include_directories(include)
file(GLOB SRC_FILE "*.cc")
add_executable(main ${SRC_FILE})
