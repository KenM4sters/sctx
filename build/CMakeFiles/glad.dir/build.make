# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/samuelbrookman/Desktop/projects/sandbox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/samuelbrookman/Desktop/projects/sandbox/build

# Include any dependencies generated for this target.
include CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glad.dir/flags.make

gladsources/glad/include/KHR/khrplatform.h:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/samuelbrookman/Desktop/projects/sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) glad-generate
	cd /Users/samuelbrookman/Desktop/projects/sandbox/external/glad && echo Cleaning /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad
	cd /Users/samuelbrookman/Desktop/projects/sandbox/external/glad && /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E remove_directory /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad
	cd /Users/samuelbrookman/Desktop/projects/sandbox/external/glad && /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E make_directory /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad
	cd /Users/samuelbrookman/Desktop/projects/sandbox/external/glad && echo Generating with args --out-path /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad --api gl:core=3.3 --reproducible c --mx
	cd /Users/samuelbrookman/Desktop/projects/sandbox/external/glad && /Library/Frameworks/Python.framework/Versions/3.12/bin/python3.12 -m glad --out-path /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad --api gl:core=3.3 --reproducible c --mx
	cd /Users/samuelbrookman/Desktop/projects/sandbox/external/glad && echo Writing /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad/args.txt
	cd /Users/samuelbrookman/Desktop/projects/sandbox/external/glad && echo --out-path /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad --api gl:core=3.3 --reproducible c --mx > /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad/args.txt

gladsources/glad/include/glad/gl.h: gladsources/glad/include/KHR/khrplatform.h
	@$(CMAKE_COMMAND) -E touch_nocreate gladsources/glad/include/glad/gl.h

gladsources/glad/src/gl.c: gladsources/glad/include/KHR/khrplatform.h
	@$(CMAKE_COMMAND) -E touch_nocreate gladsources/glad/src/gl.c

gladsources/glad/args.txt: gladsources/glad/include/KHR/khrplatform.h
	@$(CMAKE_COMMAND) -E touch_nocreate gladsources/glad/args.txt

CMakeFiles/glad.dir/gladsources/glad/src/gl.c.o: CMakeFiles/glad.dir/flags.make
CMakeFiles/glad.dir/gladsources/glad/src/gl.c.o: gladsources/glad/src/gl.c
CMakeFiles/glad.dir/gladsources/glad/src/gl.c.o: CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/samuelbrookman/Desktop/projects/sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/glad.dir/gladsources/glad/src/gl.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/glad.dir/gladsources/glad/src/gl.c.o -MF CMakeFiles/glad.dir/gladsources/glad/src/gl.c.o.d -o CMakeFiles/glad.dir/gladsources/glad/src/gl.c.o -c /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad/src/gl.c

CMakeFiles/glad.dir/gladsources/glad/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glad.dir/gladsources/glad/src/gl.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad/src/gl.c > CMakeFiles/glad.dir/gladsources/glad/src/gl.c.i

CMakeFiles/glad.dir/gladsources/glad/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glad.dir/gladsources/glad/src/gl.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/samuelbrookman/Desktop/projects/sandbox/build/gladsources/glad/src/gl.c -o CMakeFiles/glad.dir/gladsources/glad/src/gl.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/gladsources/glad/src/gl.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

libglad.a: CMakeFiles/glad.dir/gladsources/glad/src/gl.c.o
libglad.a: CMakeFiles/glad.dir/build.make
libglad.a: CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/samuelbrookman/Desktop/projects/sandbox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libglad.a"
	$(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glad.dir/build: libglad.a
.PHONY : CMakeFiles/glad.dir/build

CMakeFiles/glad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glad.dir/clean

CMakeFiles/glad.dir/depend: gladsources/glad/args.txt
CMakeFiles/glad.dir/depend: gladsources/glad/include/KHR/khrplatform.h
CMakeFiles/glad.dir/depend: gladsources/glad/include/glad/gl.h
CMakeFiles/glad.dir/depend: gladsources/glad/src/gl.c
	cd /Users/samuelbrookman/Desktop/projects/sandbox/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/samuelbrookman/Desktop/projects/sandbox /Users/samuelbrookman/Desktop/projects/sandbox /Users/samuelbrookman/Desktop/projects/sandbox/build /Users/samuelbrookman/Desktop/projects/sandbox/build /Users/samuelbrookman/Desktop/projects/sandbox/build/CMakeFiles/glad.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/glad.dir/depend

