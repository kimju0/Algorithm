# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dev.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dev.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dev.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dev.dir/flags.make

CMakeFiles/dev.dir/main.cpp.obj: CMakeFiles/dev.dir/flags.make
CMakeFiles/dev.dir/main.cpp.obj: C:/Users/juyoung/Desktop/2-2/algorithm/proj2/dev/main.cpp
CMakeFiles/dev.dir/main.cpp.obj: CMakeFiles/dev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dev.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dev.dir/main.cpp.obj -MF CMakeFiles\dev.dir\main.cpp.obj.d -o CMakeFiles\dev.dir\main.cpp.obj -c C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev\main.cpp

CMakeFiles/dev.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dev.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev\main.cpp > CMakeFiles\dev.dir\main.cpp.i

CMakeFiles/dev.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dev.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev\main.cpp -o CMakeFiles\dev.dir\main.cpp.s

# Object files for target dev
dev_OBJECTS = \
"CMakeFiles/dev.dir/main.cpp.obj"

# External object files for target dev
dev_EXTERNAL_OBJECTS =

dev.exe: CMakeFiles/dev.dir/main.cpp.obj
dev.exe: CMakeFiles/dev.dir/build.make
dev.exe: CMakeFiles/dev.dir/linkLibs.rsp
dev.exe: CMakeFiles/dev.dir/objects1.rsp
dev.exe: CMakeFiles/dev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dev.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dev.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dev.dir/build: dev.exe
.PHONY : CMakeFiles/dev.dir/build

CMakeFiles/dev.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dev.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dev.dir/clean

CMakeFiles/dev.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev\cmake-build-debug C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev\cmake-build-debug C:\Users\juyoung\Desktop\2-2\algorithm\proj2\dev\cmake-build-debug\CMakeFiles\dev.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dev.dir/depend

