# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/przemek/CLionProjects/Factory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/przemek/CLionProjects/Factory/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Factory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Factory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Factory.dir/flags.make

CMakeFiles/Factory.dir/main.cpp.o: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/przemek/CLionProjects/Factory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Factory.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Factory.dir/main.cpp.o -c /Users/przemek/CLionProjects/Factory/main.cpp

CMakeFiles/Factory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/przemek/CLionProjects/Factory/main.cpp > CMakeFiles/Factory.dir/main.cpp.i

CMakeFiles/Factory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/przemek/CLionProjects/Factory/main.cpp -o CMakeFiles/Factory.dir/main.cpp.s

CMakeFiles/Factory.dir/package.cpp.o: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/package.cpp.o: ../package.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/przemek/CLionProjects/Factory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Factory.dir/package.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Factory.dir/package.cpp.o -c /Users/przemek/CLionProjects/Factory/package.cpp

CMakeFiles/Factory.dir/package.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/package.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/przemek/CLionProjects/Factory/package.cpp > CMakeFiles/Factory.dir/package.cpp.i

CMakeFiles/Factory.dir/package.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/package.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/przemek/CLionProjects/Factory/package.cpp -o CMakeFiles/Factory.dir/package.cpp.s

CMakeFiles/Factory.dir/storage_types.cpp.o: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/storage_types.cpp.o: ../storage_types.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/przemek/CLionProjects/Factory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Factory.dir/storage_types.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Factory.dir/storage_types.cpp.o -c /Users/przemek/CLionProjects/Factory/storage_types.cpp

CMakeFiles/Factory.dir/storage_types.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/storage_types.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/przemek/CLionProjects/Factory/storage_types.cpp > CMakeFiles/Factory.dir/storage_types.cpp.i

CMakeFiles/Factory.dir/storage_types.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/storage_types.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/przemek/CLionProjects/Factory/storage_types.cpp -o CMakeFiles/Factory.dir/storage_types.cpp.s

# Object files for target Factory
Factory_OBJECTS = \
"CMakeFiles/Factory.dir/main.cpp.o" \
"CMakeFiles/Factory.dir/package.cpp.o" \
"CMakeFiles/Factory.dir/storage_types.cpp.o"

# External object files for target Factory
Factory_EXTERNAL_OBJECTS =

Factory: CMakeFiles/Factory.dir/main.cpp.o
Factory: CMakeFiles/Factory.dir/package.cpp.o
Factory: CMakeFiles/Factory.dir/storage_types.cpp.o
Factory: CMakeFiles/Factory.dir/build.make
Factory: CMakeFiles/Factory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/przemek/CLionProjects/Factory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Factory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Factory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Factory.dir/build: Factory

.PHONY : CMakeFiles/Factory.dir/build

CMakeFiles/Factory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Factory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Factory.dir/clean

CMakeFiles/Factory.dir/depend:
	cd /Users/przemek/CLionProjects/Factory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/przemek/CLionProjects/Factory /Users/przemek/CLionProjects/Factory /Users/przemek/CLionProjects/Factory/cmake-build-debug /Users/przemek/CLionProjects/Factory/cmake-build-debug /Users/przemek/CLionProjects/Factory/cmake-build-debug/CMakeFiles/Factory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Factory.dir/depend

