# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\neelu\OneDrive\Desktop\fp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\neelu\OneDrive\Desktop\fp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ludo_tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ludo_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ludo_tests.dir/flags.make

CMakeFiles/ludo_tests.dir/src/model.cxx.obj: CMakeFiles/ludo_tests.dir/flags.make
CMakeFiles/ludo_tests.dir/src/model.cxx.obj: CMakeFiles/ludo_tests.dir/includes_CXX.rsp
CMakeFiles/ludo_tests.dir/src/model.cxx.obj: ../src/model.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\neelu\OneDrive\Desktop\fp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ludo_tests.dir/src/model.cxx.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ludo_tests.dir\src\model.cxx.obj -c C:\Users\neelu\OneDrive\Desktop\fp\src\model.cxx

CMakeFiles/ludo_tests.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ludo_tests.dir/src/model.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\neelu\OneDrive\Desktop\fp\src\model.cxx > CMakeFiles\ludo_tests.dir\src\model.cxx.i

CMakeFiles/ludo_tests.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ludo_tests.dir/src/model.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\neelu\OneDrive\Desktop\fp\src\model.cxx -o CMakeFiles\ludo_tests.dir\src\model.cxx.s

CMakeFiles/ludo_tests.dir/test/model_test.cxx.obj: CMakeFiles/ludo_tests.dir/flags.make
CMakeFiles/ludo_tests.dir/test/model_test.cxx.obj: CMakeFiles/ludo_tests.dir/includes_CXX.rsp
CMakeFiles/ludo_tests.dir/test/model_test.cxx.obj: ../test/model_test.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\neelu\OneDrive\Desktop\fp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ludo_tests.dir/test/model_test.cxx.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ludo_tests.dir\test\model_test.cxx.obj -c C:\Users\neelu\OneDrive\Desktop\fp\test\model_test.cxx

CMakeFiles/ludo_tests.dir/test/model_test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ludo_tests.dir/test/model_test.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\neelu\OneDrive\Desktop\fp\test\model_test.cxx > CMakeFiles\ludo_tests.dir\test\model_test.cxx.i

CMakeFiles/ludo_tests.dir/test/model_test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ludo_tests.dir/test/model_test.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\neelu\OneDrive\Desktop\fp\test\model_test.cxx -o CMakeFiles\ludo_tests.dir\test\model_test.cxx.s

# Object files for target ludo_tests
ludo_tests_OBJECTS = \
"CMakeFiles/ludo_tests.dir/src/model.cxx.obj" \
"CMakeFiles/ludo_tests.dir/test/model_test.cxx.obj"

# External object files for target ludo_tests
ludo_tests_EXTERNAL_OBJECTS =

ludo_tests.exe: CMakeFiles/ludo_tests.dir/src/model.cxx.obj
ludo_tests.exe: CMakeFiles/ludo_tests.dir/test/model_test.cxx.obj
ludo_tests.exe: CMakeFiles/ludo_tests.dir/build.make
ludo_tests.exe: .cs211/lib/catch/libcatch.a
ludo_tests.exe: CMakeFiles/ludo_tests.dir/linklibs.rsp
ludo_tests.exe: CMakeFiles/ludo_tests.dir/objects1.rsp
ludo_tests.exe: CMakeFiles/ludo_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\neelu\OneDrive\Desktop\fp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ludo_tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ludo_tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ludo_tests.dir/build: ludo_tests.exe

.PHONY : CMakeFiles/ludo_tests.dir/build

CMakeFiles/ludo_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ludo_tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ludo_tests.dir/clean

CMakeFiles/ludo_tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\neelu\OneDrive\Desktop\fp C:\Users\neelu\OneDrive\Desktop\fp C:\Users\neelu\OneDrive\Desktop\fp\cmake-build-debug C:\Users\neelu\OneDrive\Desktop\fp\cmake-build-debug C:\Users\neelu\OneDrive\Desktop\fp\cmake-build-debug\CMakeFiles\ludo_tests.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ludo_tests.dir/depend
