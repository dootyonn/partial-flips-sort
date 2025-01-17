cmake_minimum_required(VERSION 3.28)

# partial_flip_sort

add_library(partial_flip_sort
    partial_flip.cpp
    partial_flips_sort.cpp
)

target_include_directories(partial_flip_sort
PUBLIC
    .
)

# quiz_sort

add_executable(quiz_sort 
    main.cpp
    
)

target_link_libraries(quiz_sort
    partial_flip_sort
)

# partial_flip_sort_test

add_executable(partial_flip_sort_test
    partial_flip.t.cpp
    partial_flips_sort.t.cpp
)

target_include_directories(partial_flip_sort_test
PRIVATE
    .
)

target_link_libraries(partial_flip_sort_test
    gtest
    gtest_main
    partial_flip_sort
)

gtest_discover_tests(partial_flip_sort_test)
