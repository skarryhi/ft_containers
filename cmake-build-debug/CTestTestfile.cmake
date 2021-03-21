# CMake generated Testfile for 
# Source directory: /Users/skarry/Desktop/ft_containers
# Build directory: /Users/skarry/Desktop/ft_containers/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(runVector "runVector")
set_tests_properties(runVector PROPERTIES  _BACKTRACE_TRIPLES "/Users/skarry/Desktop/ft_containers/CMakeLists.txt;17;add_test;/Users/skarry/Desktop/ft_containers/CMakeLists.txt;0;")
add_test(runList "runList")
set_tests_properties(runList PROPERTIES  _BACKTRACE_TRIPLES "/Users/skarry/Desktop/ft_containers/CMakeLists.txt;22;add_test;/Users/skarry/Desktop/ft_containers/CMakeLists.txt;0;")
add_test(runStack "runStack")
set_tests_properties(runStack PROPERTIES  _BACKTRACE_TRIPLES "/Users/skarry/Desktop/ft_containers/CMakeLists.txt;26;add_test;/Users/skarry/Desktop/ft_containers/CMakeLists.txt;0;")
add_test(runQueue "runQueue")
set_tests_properties(runQueue PROPERTIES  _BACKTRACE_TRIPLES "/Users/skarry/Desktop/ft_containers/CMakeLists.txt;30;add_test;/Users/skarry/Desktop/ft_containers/CMakeLists.txt;0;")
subdirs("google_test")
