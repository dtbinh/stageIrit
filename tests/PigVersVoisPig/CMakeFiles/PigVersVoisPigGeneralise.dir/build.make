# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig

# Include any dependencies generated for this target.
include CMakeFiles/PigVersVoisPigGeneralise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PigVersVoisPigGeneralise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PigVersVoisPigGeneralise.dir/flags.make

CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o: CMakeFiles/PigVersVoisPigGeneralise.dir/flags.make
CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o: PigVersVoisPigGeneralise.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o -c /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig/PigVersVoisPigGeneralise.cpp

CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig/PigVersVoisPigGeneralise.cpp > CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.i

CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig/PigVersVoisPigGeneralise.cpp -o CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.s

CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o.requires:
.PHONY : CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o.requires

CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o.provides: CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o.requires
	$(MAKE) -f CMakeFiles/PigVersVoisPigGeneralise.dir/build.make CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o.provides.build
.PHONY : CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o.provides

CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o.provides.build: CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o

# Object files for target PigVersVoisPigGeneralise
PigVersVoisPigGeneralise_OBJECTS = \
"CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o"

# External object files for target PigVersVoisPigGeneralise
PigVersVoisPigGeneralise_EXTERNAL_OBJECTS =

PigVersVoisPigGeneralise: CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o
PigVersVoisPigGeneralise: CMakeFiles/PigVersVoisPigGeneralise.dir/build.make
PigVersVoisPigGeneralise: CMakeFiles/PigVersVoisPigGeneralise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable PigVersVoisPigGeneralise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PigVersVoisPigGeneralise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PigVersVoisPigGeneralise.dir/build: PigVersVoisPigGeneralise
.PHONY : CMakeFiles/PigVersVoisPigGeneralise.dir/build

CMakeFiles/PigVersVoisPigGeneralise.dir/requires: CMakeFiles/PigVersVoisPigGeneralise.dir/PigVersVoisPigGeneralise.cpp.o.requires
.PHONY : CMakeFiles/PigVersVoisPigGeneralise.dir/requires

CMakeFiles/PigVersVoisPigGeneralise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PigVersVoisPigGeneralise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PigVersVoisPigGeneralise.dir/clean

CMakeFiles/PigVersVoisPigGeneralise.dir/depend:
	cd /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig /home/jackdanny/Bureau/stageIrit/tests/PigVersVoisPig/CMakeFiles/PigVersVoisPigGeneralise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PigVersVoisPigGeneralise.dir/depend
