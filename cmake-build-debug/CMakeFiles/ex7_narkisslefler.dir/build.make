# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /Users/narkisslefler/ex7-narkisslefler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/narkisslefler/ex7-narkisslefler/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex7_narkisslefler.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ex7_narkisslefler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex7_narkisslefler.dir/flags.make

CMakeFiles/ex7_narkisslefler.dir/tests.cpp.o: CMakeFiles/ex7_narkisslefler.dir/flags.make
CMakeFiles/ex7_narkisslefler.dir/tests.cpp.o: ../tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/narkisslefler/ex7-narkisslefler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex7_narkisslefler.dir/tests.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex7_narkisslefler.dir/tests.cpp.o -c /Users/narkisslefler/ex7-narkisslefler/tests.cpp

CMakeFiles/ex7_narkisslefler.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex7_narkisslefler.dir/tests.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/narkisslefler/ex7-narkisslefler/tests.cpp > CMakeFiles/ex7_narkisslefler.dir/tests.cpp.i

CMakeFiles/ex7_narkisslefler.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex7_narkisslefler.dir/tests.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/narkisslefler/ex7-narkisslefler/tests.cpp -o CMakeFiles/ex7_narkisslefler.dir/tests.cpp.s

# Object files for target ex7_narkisslefler
ex7_narkisslefler_OBJECTS = \
"CMakeFiles/ex7_narkisslefler.dir/tests.cpp.o"

# External object files for target ex7_narkisslefler
ex7_narkisslefler_EXTERNAL_OBJECTS =

ex7_narkisslefler: CMakeFiles/ex7_narkisslefler.dir/tests.cpp.o
ex7_narkisslefler: CMakeFiles/ex7_narkisslefler.dir/build.make
ex7_narkisslefler: CMakeFiles/ex7_narkisslefler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/narkisslefler/ex7-narkisslefler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex7_narkisslefler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex7_narkisslefler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex7_narkisslefler.dir/build: ex7_narkisslefler
.PHONY : CMakeFiles/ex7_narkisslefler.dir/build

CMakeFiles/ex7_narkisslefler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex7_narkisslefler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex7_narkisslefler.dir/clean

CMakeFiles/ex7_narkisslefler.dir/depend:
	cd /Users/narkisslefler/ex7-narkisslefler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/narkisslefler/ex7-narkisslefler /Users/narkisslefler/ex7-narkisslefler /Users/narkisslefler/ex7-narkisslefler/cmake-build-debug /Users/narkisslefler/ex7-narkisslefler/cmake-build-debug /Users/narkisslefler/ex7-narkisslefler/cmake-build-debug/CMakeFiles/ex7_narkisslefler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex7_narkisslefler.dir/depend

