# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/stephan/Gitkraken/RIS Lab 1 uuv_simulator/catkinws/src/uuv_simulator/uuv_control/uuv_trajectory_control"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/stephan/Gitkraken/RIS Lab 1 uuv_simulator/catkinws/build/uuv_trajectory_control"

# Utility rule file for clean_test_results_uuv_trajectory_control.

# Include the progress variables for this target.
include CMakeFiles/clean_test_results_uuv_trajectory_control.dir/progress.make

CMakeFiles/clean_test_results_uuv_trajectory_control:
	/usr/bin/python3 /home/stephan/catkinws/src/catkin/cmake/test/remove_test_results.py "/home/stephan/Gitkraken/RIS Lab 1 uuv_simulator/catkinws/build/uuv_trajectory_control/test_results/uuv_trajectory_control"

clean_test_results_uuv_trajectory_control: CMakeFiles/clean_test_results_uuv_trajectory_control
clean_test_results_uuv_trajectory_control: CMakeFiles/clean_test_results_uuv_trajectory_control.dir/build.make

.PHONY : clean_test_results_uuv_trajectory_control

# Rule to build all files generated by this target.
CMakeFiles/clean_test_results_uuv_trajectory_control.dir/build: clean_test_results_uuv_trajectory_control

.PHONY : CMakeFiles/clean_test_results_uuv_trajectory_control.dir/build

CMakeFiles/clean_test_results_uuv_trajectory_control.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clean_test_results_uuv_trajectory_control.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clean_test_results_uuv_trajectory_control.dir/clean

CMakeFiles/clean_test_results_uuv_trajectory_control.dir/depend:
	cd "/home/stephan/Gitkraken/RIS Lab 1 uuv_simulator/catkinws/build/uuv_trajectory_control" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/stephan/Gitkraken/RIS Lab 1 uuv_simulator/catkinws/src/uuv_simulator/uuv_control/uuv_trajectory_control" "/home/stephan/Gitkraken/RIS Lab 1 uuv_simulator/catkinws/src/uuv_simulator/uuv_control/uuv_trajectory_control" "/home/stephan/Gitkraken/RIS Lab 1 uuv_simulator/catkinws/build/uuv_trajectory_control" "/home/stephan/Gitkraken/RIS Lab 1 uuv_simulator/catkinws/build/uuv_trajectory_control" "/home/stephan/Gitkraken/RIS Lab 1 uuv_simulator/catkinws/build/uuv_trajectory_control/CMakeFiles/clean_test_results_uuv_trajectory_control.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/clean_test_results_uuv_trajectory_control.dir/depend

