cmake_minimum_required(VERSION 3.28)

include(GoogleTest)

# partial_flip_sort

add_library(partial_flip_sort
    partial_flip.cpp
    partial_flips_sort.cpp
)

target_include_directories(partial_flip_sort
PUBLIC
    .
)

# quizsort

add_executable(quizsort 
    main.cpp
    
)

target_link_libraries(quizsort
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

# Functional Tests

add_executable(sort_functional_test
    partial_flips_sort.f.t.cpp
)

target_include_directories(sort_functional_test
PRIVATE
    .
)

target_link_libraries(sort_functional_test
    gtest
    gtest_main
    partial_flip_sort
)

# install files

install(
    TARGETS quizsort 
    RUNTIME DESTINATION bin COMPONENT Runtime
) 