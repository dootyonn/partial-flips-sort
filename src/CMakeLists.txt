cmake_minimum_required(VERSION 3.28)

# quiz_sort

add_executable(quiz_sort 
    partial_flip.cpp
    sort.cpp
)

target_include_directories(quiz_sort
PRIVATE
  .
)

# quiz_sort_test

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(quiz_sort_test
    partial_flip.t.cpp
)

target_include_directories(quiz_sort_test
PRIVATE
    .
)

target_link_libraries(quiz_sort_test
    gtest
    gtest_main
)

gtest_discover_tests(quiz_sort_test)
