cmake_minimum_required(VERSION 3.17)
project(ft_containers)


################################
# GTest
################################

add_subdirectory(google_test/)
enable_testing()

include_directories(google_test/googletest/include)


add_executable(runVector my_tests/vector_test.cpp includes/vector.hpp)
target_link_libraries(runVector gtest gtest_main)
add_test( runVector runVector)


add_executable(runList my_tests/list_test.cpp includes/list.hpp)
target_link_libraries(runList gtest gtest_main)
add_test( runList runList)

add_executable(runStack my_tests/stack_test.cpp includes/stack.hpp)
target_link_libraries(runStack gtest gtest_main)
add_test( runStack runStack)

add_executable(runQueue my_tests/queue_test.cpp includes/queue.hpp)
target_link_libraries(runQueue gtest gtest_main)
add_test( runQueue runQueue)

add_executable(runMap my_tests/map_test.cpp includes/map.hpp)
target_link_libraries(runMap -Wall -Wextra -Werror gtest gtest_main)
add_test( runMap runMap)

add_executable(ft_containers main.cpp includes/map.hpp)