# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = /Users/skarry/Desktop/containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/skarry/Desktop/containers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/runList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runList.dir/flags.make

CMakeFiles/runList.dir/my_tests/list_test.cpp.o: CMakeFiles/runList.dir/flags.make
CMakeFiles/runList.dir/my_tests/list_test.cpp.o: ../my_tests/list_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/skarry/Desktop/containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runList.dir/my_tests/list_test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runList.dir/my_tests/list_test.cpp.o -c /Users/skarry/Desktop/containers/my_tests/list_test.cpp

CMakeFiles/runList.dir/my_tests/list_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runList.dir/my_tests/list_test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/skarry/Desktop/containers/my_tests/list_test.cpp > CMakeFiles/runList.dir/my_tests/list_test.cpp.i

CMakeFiles/runList.dir/my_tests/list_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runList.dir/my_tests/list_test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/skarry/Desktop/containers/my_tests/list_test.cpp -o CMakeFiles/runList.dir/my_tests/list_test.cpp.s

# Object files for target runList
runList_OBJECTS = \
"CMakeFiles/runList.dir/my_tests/list_test.cpp.o"

# External object files for target runList
runList_EXTERNAL_OBJECTS =

runList: CMakeFiles/runList.dir/my_tests/list_test.cpp.o
runList: CMakeFiles/runList.dir/build.make
runList: google_test/googlemock/gtest/libgtestd.a
runList: google_test/googlemock/gtest/libgtest_maind.a
runList: google_test/googlemock/gtest/libgtestd.a
runList: CMakeFiles/runList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/skarry/Desktop/containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runList.dir/build: runList

.PHONY : CMakeFiles/runList.dir/build

CMakeFiles/runList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runList.dir/clean

CMakeFiles/runList.dir/depend:
	cd /Users/skarry/Desktop/containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/skarry/Desktop/containers /Users/skarry/Desktop/containers /Users/skarry/Desktop/containers/cmake-build-debug /Users/skarry/Desktop/containers/cmake-build-debug /Users/skarry/Desktop/containers/cmake-build-debug/CMakeFiles/runList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runList.dir/depend

