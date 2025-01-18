cmake_minimum_required(VERSION 3.28)

project(quiz_sort
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include(CTest)

find_package(GTest REQUIRED)

add_subdirectory(src)