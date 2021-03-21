cmake_minimum_required(VERSION 3.17)
project(ft_containers)


################################
# GTest
################################

add_subdirectory(google_test/)
enable_testing()

include_directories(google_test/googletest/include)


add_executable(runVector vector_test.cpp vector.hpp)
target_link_libraries(runVector gtest gtest_main)
add_test( runVector runVector)


add_executable(runList list_test.cpp list.hpp)
target_link_libraries(runList gtest gtest_main)
add_test( runList runList)