# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Factory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Factory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Factory.dir/flags.make

CMakeFiles/Factory.dir/main.cpp.obj: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Factory.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Factory.dir\main.cpp.obj -c "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\main.cpp"

CMakeFiles/Factory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\main.cpp" > CMakeFiles\Factory.dir\main.cpp.i

CMakeFiles/Factory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\main.cpp" -o CMakeFiles\Factory.dir\main.cpp.s

CMakeFiles/Factory.dir/package.cpp.obj: CMakeFiles/Factory.dir/flags.make
CMakeFiles/Factory.dir/package.cpp.obj: ../package.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Factory.dir/package.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Factory.dir\package.cpp.obj -c "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\package.cpp"

CMakeFiles/Factory.dir/package.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory.dir/package.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\package.cpp" > CMakeFiles\Factory.dir\package.cpp.i

CMakeFiles/Factory.dir/package.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory.dir/package.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\package.cpp" -o CMakeFiles\Factory.dir\package.cpp.s

# Object files for target Factory
Factory_OBJECTS = \
"CMakeFiles/Factory.dir/main.cpp.obj" \
"CMakeFiles/Factory.dir/package.cpp.obj"

# External object files for target Factory
Factory_EXTERNAL_OBJECTS =

Factory.exe: CMakeFiles/Factory.dir/main.cpp.obj
Factory.exe: CMakeFiles/Factory.dir/package.cpp.obj
Factory.exe: CMakeFiles/Factory.dir/build.make
Factory.exe: CMakeFiles/Factory.dir/linklibs.rsp
Factory.exe: CMakeFiles/Factory.dir/objects1.rsp
Factory.exe: CMakeFiles/Factory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Factory.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Factory.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Factory.dir/build: Factory.exe

.PHONY : CMakeFiles/Factory.dir/build

CMakeFiles/Factory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Factory.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Factory.dir/clean

CMakeFiles/Factory.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory" "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory" "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\cmake-build-debug" "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\cmake-build-debug" "C:\Users\Filip Olszowski\Desktop\Kody\Informatyka II\Factory\cmake-build-debug\CMakeFiles\Factory.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Factory.dir/depend

