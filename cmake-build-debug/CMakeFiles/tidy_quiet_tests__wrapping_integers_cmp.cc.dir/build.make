# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /home/hog/.cache/JetBrains/RemoteDev/dist/68305831d57ea_CLion-2022.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hog/.cache/JetBrains/RemoteDev/dist/68305831d57ea_CLion-2022.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hog/cs144/lab0/sponge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hog/cs144/lab0/sponge/cmake-build-debug

# Utility rule file for tidy_quiet_tests__wrapping_integers_cmp.cc.

# Include any custom commands dependencies for this target.
include CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/progress.make

CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc:
	clang-tidy -checks='*,-fuchsia-*,-hicpp-signed-bitwise,-google-build-using-namespace,-android*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-google-runtime-references,-readability-avoid-const-params-in-decls,-llvm-header-guard' -header-filter=.* -p=/home/hog/cs144/lab0/sponge/cmake-build-debug /home/hog/cs144/lab0/sponge/tests/wrapping_integers_cmp.cc 2>/dev/null

tidy_quiet_tests__wrapping_integers_cmp.cc: CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc
tidy_quiet_tests__wrapping_integers_cmp.cc: CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/build.make
.PHONY : tidy_quiet_tests__wrapping_integers_cmp.cc

# Rule to build all files generated by this target.
CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/build: tidy_quiet_tests__wrapping_integers_cmp.cc
.PHONY : CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/build

CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/clean

CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/depend:
	cd /home/hog/cs144/lab0/sponge/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hog/cs144/lab0/sponge /home/hog/cs144/lab0/sponge /home/hog/cs144/lab0/sponge/cmake-build-debug /home/hog/cs144/lab0/sponge/cmake-build-debug /home/hog/cs144/lab0/sponge/cmake-build-debug/CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tidy_quiet_tests__wrapping_integers_cmp.cc.dir/depend

