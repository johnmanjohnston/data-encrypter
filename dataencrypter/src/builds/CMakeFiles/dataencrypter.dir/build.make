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
CMAKE_SOURCE_DIR = /workspaces/data-encrypter/dataencrypter/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/data-encrypter/dataencrypter/src/builds

# Include any dependencies generated for this target.
include CMakeFiles/dataencrypter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dataencrypter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dataencrypter.dir/flags.make

CMakeFiles/dataencrypter.dir/Main.cpp.o: CMakeFiles/dataencrypter.dir/flags.make
CMakeFiles/dataencrypter.dir/Main.cpp.o: ../Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/data-encrypter/dataencrypter/src/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dataencrypter.dir/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dataencrypter.dir/Main.cpp.o -c /workspaces/data-encrypter/dataencrypter/src/Main.cpp

CMakeFiles/dataencrypter.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dataencrypter.dir/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/data-encrypter/dataencrypter/src/Main.cpp > CMakeFiles/dataencrypter.dir/Main.cpp.i

CMakeFiles/dataencrypter.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dataencrypter.dir/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/data-encrypter/dataencrypter/src/Main.cpp -o CMakeFiles/dataencrypter.dir/Main.cpp.s

CMakeFiles/dataencrypter.dir/Crypt.cpp.o: CMakeFiles/dataencrypter.dir/flags.make
CMakeFiles/dataencrypter.dir/Crypt.cpp.o: ../Crypt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/data-encrypter/dataencrypter/src/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dataencrypter.dir/Crypt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dataencrypter.dir/Crypt.cpp.o -c /workspaces/data-encrypter/dataencrypter/src/Crypt.cpp

CMakeFiles/dataencrypter.dir/Crypt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dataencrypter.dir/Crypt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/data-encrypter/dataencrypter/src/Crypt.cpp > CMakeFiles/dataencrypter.dir/Crypt.cpp.i

CMakeFiles/dataencrypter.dir/Crypt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dataencrypter.dir/Crypt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/data-encrypter/dataencrypter/src/Crypt.cpp -o CMakeFiles/dataencrypter.dir/Crypt.cpp.s

CMakeFiles/dataencrypter.dir/Utils.c.o: CMakeFiles/dataencrypter.dir/flags.make
CMakeFiles/dataencrypter.dir/Utils.c.o: ../Utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/data-encrypter/dataencrypter/src/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/dataencrypter.dir/Utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dataencrypter.dir/Utils.c.o   -c /workspaces/data-encrypter/dataencrypter/src/Utils.c

CMakeFiles/dataencrypter.dir/Utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dataencrypter.dir/Utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/data-encrypter/dataencrypter/src/Utils.c > CMakeFiles/dataencrypter.dir/Utils.c.i

CMakeFiles/dataencrypter.dir/Utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dataencrypter.dir/Utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/data-encrypter/dataencrypter/src/Utils.c -o CMakeFiles/dataencrypter.dir/Utils.c.s

# Object files for target dataencrypter
dataencrypter_OBJECTS = \
"CMakeFiles/dataencrypter.dir/Main.cpp.o" \
"CMakeFiles/dataencrypter.dir/Crypt.cpp.o" \
"CMakeFiles/dataencrypter.dir/Utils.c.o"

# External object files for target dataencrypter
dataencrypter_EXTERNAL_OBJECTS =

dataencrypter: CMakeFiles/dataencrypter.dir/Main.cpp.o
dataencrypter: CMakeFiles/dataencrypter.dir/Crypt.cpp.o
dataencrypter: CMakeFiles/dataencrypter.dir/Utils.c.o
dataencrypter: CMakeFiles/dataencrypter.dir/build.make
dataencrypter: CMakeFiles/dataencrypter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/data-encrypter/dataencrypter/src/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable dataencrypter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dataencrypter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dataencrypter.dir/build: dataencrypter

.PHONY : CMakeFiles/dataencrypter.dir/build

CMakeFiles/dataencrypter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dataencrypter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dataencrypter.dir/clean

CMakeFiles/dataencrypter.dir/depend:
	cd /workspaces/data-encrypter/dataencrypter/src/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/data-encrypter/dataencrypter/src /workspaces/data-encrypter/dataencrypter/src /workspaces/data-encrypter/dataencrypter/src/builds /workspaces/data-encrypter/dataencrypter/src/builds /workspaces/data-encrypter/dataencrypter/src/builds/CMakeFiles/dataencrypter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dataencrypter.dir/depend

