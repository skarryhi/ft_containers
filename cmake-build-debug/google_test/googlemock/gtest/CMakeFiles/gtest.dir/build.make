# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/skarry/Desktop/ft_containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/skarry/Desktop/ft_containers/cmake-build-debug

# Include any dependencies generated for this target.
include google_test/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include google_test/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include google_test/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

google_test/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: google_test/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
google_test/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../google_test/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/skarry/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object google_test/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /Users/skarry/Desktop/ft_containers/cmake-build-debug/google_test/googlemock/gtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /Users/skarry/Desktop/ft_containers/google_test/googletest/src/gtest-all.cc

google_test/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /Users/skarry/Desktop/ft_containers/cmake-build-debug/google_test/googlemock/gtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/skarry/Desktop/ft_containers/google_test/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

google_test/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /Users/skarry/Desktop/ft_containers/cmake-build-debug/google_test/googlemock/gtest && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/skarry/Desktop/ft_containers/google_test/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

google_test/googlemock/gtest/libgtestd.a: google_test/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
google_test/googlemock/gtest/libgtestd.a: google_test/googlemock/gtest/CMakeFiles/gtest.dir/build.make
google_test/googlemock/gtest/libgtestd.a: google_test/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/skarry/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtestd.a"
	cd /Users/skarry/Desktop/ft_containers/cmake-build-debug/google_test/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /Users/skarry/Desktop/ft_containers/cmake-build-debug/google_test/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
google_test/googlemock/gtest/CMakeFiles/gtest.dir/build: google_test/googlemock/gtest/libgtestd.a

.PHONY : google_test/googlemock/gtest/CMakeFiles/gtest.dir/build

google_test/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /Users/skarry/Desktop/ft_containers/cmake-build-debug/google_test/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : google_test/googlemock/gtest/CMakeFiles/gtest.dir/clean

google_test/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	cd /Users/skarry/Desktop/ft_containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/skarry/Desktop/ft_containers /Users/skarry/Desktop/ft_containers/google_test/googletest /Users/skarry/Desktop/ft_containers/cmake-build-debug /Users/skarry/Desktop/ft_containers/cmake-build-debug/google_test/googlemock/gtest /Users/skarry/Desktop/ft_containers/cmake-build-debug/google_test/googlemock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : google_test/googlemock/gtest/CMakeFiles/gtest.dir/depend
