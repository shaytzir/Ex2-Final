# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/shay/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/shay/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shay/CLionProjects/Ex2-shay

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shay/CLionProjects/Ex2-shay/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ex2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ex2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ex2.dir/flags.make

CMakeFiles/Ex2.dir/src/main.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ex2.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/src/main.cpp.o -c /home/shay/CLionProjects/Ex2-shay/src/main.cpp

CMakeFiles/Ex2.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/src/main.cpp > CMakeFiles/Ex2.dir/src/main.cpp.i

CMakeFiles/Ex2.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/src/main.cpp -o CMakeFiles/Ex2.dir/src/main.cpp.s

CMakeFiles/Ex2.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/src/main.cpp.o.requires

CMakeFiles/Ex2.dir/src/main.cpp.o.provides: CMakeFiles/Ex2.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/src/main.cpp.o.provides

CMakeFiles/Ex2.dir/src/main.cpp.o.provides.build: CMakeFiles/Ex2.dir/src/main.cpp.o


CMakeFiles/Ex2.dir/src/Board.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/src/Board.cpp.o: ../src/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Ex2.dir/src/Board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/src/Board.cpp.o -c /home/shay/CLionProjects/Ex2-shay/src/Board.cpp

CMakeFiles/Ex2.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/src/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/src/Board.cpp > CMakeFiles/Ex2.dir/src/Board.cpp.i

CMakeFiles/Ex2.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/src/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/src/Board.cpp -o CMakeFiles/Ex2.dir/src/Board.cpp.s

CMakeFiles/Ex2.dir/src/Board.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/src/Board.cpp.o.requires

CMakeFiles/Ex2.dir/src/Board.cpp.o.provides: CMakeFiles/Ex2.dir/src/Board.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/src/Board.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/src/Board.cpp.o.provides

CMakeFiles/Ex2.dir/src/Board.cpp.o.provides.build: CMakeFiles/Ex2.dir/src/Board.cpp.o


CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o: ../src/ReversiRules.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o -c /home/shay/CLionProjects/Ex2-shay/src/ReversiRules.cpp

CMakeFiles/Ex2.dir/src/ReversiRules.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/src/ReversiRules.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/src/ReversiRules.cpp > CMakeFiles/Ex2.dir/src/ReversiRules.cpp.i

CMakeFiles/Ex2.dir/src/ReversiRules.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/src/ReversiRules.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/src/ReversiRules.cpp -o CMakeFiles/Ex2.dir/src/ReversiRules.cpp.s

CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o.requires

CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o.provides: CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o.provides

CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o.provides.build: CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o


CMakeFiles/Ex2.dir/src/HumanP.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/src/HumanP.cpp.o: ../src/HumanP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Ex2.dir/src/HumanP.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/src/HumanP.cpp.o -c /home/shay/CLionProjects/Ex2-shay/src/HumanP.cpp

CMakeFiles/Ex2.dir/src/HumanP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/src/HumanP.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/src/HumanP.cpp > CMakeFiles/Ex2.dir/src/HumanP.cpp.i

CMakeFiles/Ex2.dir/src/HumanP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/src/HumanP.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/src/HumanP.cpp -o CMakeFiles/Ex2.dir/src/HumanP.cpp.s

CMakeFiles/Ex2.dir/src/HumanP.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/src/HumanP.cpp.o.requires

CMakeFiles/Ex2.dir/src/HumanP.cpp.o.provides: CMakeFiles/Ex2.dir/src/HumanP.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/src/HumanP.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/src/HumanP.cpp.o.provides

CMakeFiles/Ex2.dir/src/HumanP.cpp.o.provides.build: CMakeFiles/Ex2.dir/src/HumanP.cpp.o


CMakeFiles/Ex2.dir/src/GameFlow.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/src/GameFlow.cpp.o: ../src/GameFlow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Ex2.dir/src/GameFlow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/src/GameFlow.cpp.o -c /home/shay/CLionProjects/Ex2-shay/src/GameFlow.cpp

CMakeFiles/Ex2.dir/src/GameFlow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/src/GameFlow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/src/GameFlow.cpp > CMakeFiles/Ex2.dir/src/GameFlow.cpp.i

CMakeFiles/Ex2.dir/src/GameFlow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/src/GameFlow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/src/GameFlow.cpp -o CMakeFiles/Ex2.dir/src/GameFlow.cpp.s

CMakeFiles/Ex2.dir/src/GameFlow.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/src/GameFlow.cpp.o.requires

CMakeFiles/Ex2.dir/src/GameFlow.cpp.o.provides: CMakeFiles/Ex2.dir/src/GameFlow.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/src/GameFlow.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/src/GameFlow.cpp.o.provides

CMakeFiles/Ex2.dir/src/GameFlow.cpp.o.provides.build: CMakeFiles/Ex2.dir/src/GameFlow.cpp.o


CMakeFiles/Ex2.dir/src/Console.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/src/Console.cpp.o: ../src/Console.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Ex2.dir/src/Console.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/src/Console.cpp.o -c /home/shay/CLionProjects/Ex2-shay/src/Console.cpp

CMakeFiles/Ex2.dir/src/Console.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/src/Console.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/src/Console.cpp > CMakeFiles/Ex2.dir/src/Console.cpp.i

CMakeFiles/Ex2.dir/src/Console.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/src/Console.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/src/Console.cpp -o CMakeFiles/Ex2.dir/src/Console.cpp.s

CMakeFiles/Ex2.dir/src/Console.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/src/Console.cpp.o.requires

CMakeFiles/Ex2.dir/src/Console.cpp.o.provides: CMakeFiles/Ex2.dir/src/Console.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/src/Console.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/src/Console.cpp.o.provides

CMakeFiles/Ex2.dir/src/Console.cpp.o.provides.build: CMakeFiles/Ex2.dir/src/Console.cpp.o


CMakeFiles/Ex2.dir/gtest_main.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/gtest_main.cpp.o: ../gtest_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Ex2.dir/gtest_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/gtest_main.cpp.o -c /home/shay/CLionProjects/Ex2-shay/gtest_main.cpp

CMakeFiles/Ex2.dir/gtest_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/gtest_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/gtest_main.cpp > CMakeFiles/Ex2.dir/gtest_main.cpp.i

CMakeFiles/Ex2.dir/gtest_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/gtest_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/gtest_main.cpp -o CMakeFiles/Ex2.dir/gtest_main.cpp.s

CMakeFiles/Ex2.dir/gtest_main.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/gtest_main.cpp.o.requires

CMakeFiles/Ex2.dir/gtest_main.cpp.o.provides: CMakeFiles/Ex2.dir/gtest_main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/gtest_main.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/gtest_main.cpp.o.provides

CMakeFiles/Ex2.dir/gtest_main.cpp.o.provides.build: CMakeFiles/Ex2.dir/gtest_main.cpp.o


CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o: ../Tests/Test_Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o -c /home/shay/CLionProjects/Ex2-shay/Tests/Test_Board.cpp

CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/Tests/Test_Board.cpp > CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.i

CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/Tests/Test_Board.cpp -o CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.s

CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o.requires

CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o.provides: CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o.provides

CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o.provides.build: CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o


CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o: ../Tests/Test_ReversiRules.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o -c /home/shay/CLionProjects/Ex2-shay/Tests/Test_ReversiRules.cpp

CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/Tests/Test_ReversiRules.cpp > CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.i

CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/Tests/Test_ReversiRules.cpp -o CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.s

CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o.requires

CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o.provides: CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o.provides

CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o.provides.build: CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o


CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o: ../src/AIPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o -c /home/shay/CLionProjects/Ex2-shay/src/AIPlayer.cpp

CMakeFiles/Ex2.dir/src/AIPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/src/AIPlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/src/AIPlayer.cpp > CMakeFiles/Ex2.dir/src/AIPlayer.cpp.i

CMakeFiles/Ex2.dir/src/AIPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/src/AIPlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/src/AIPlayer.cpp -o CMakeFiles/Ex2.dir/src/AIPlayer.cpp.s

CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o.requires

CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o.provides: CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o.provides

CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o.provides.build: CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o


CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o: CMakeFiles/Ex2.dir/flags.make
CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o: ../Tests/Test_HumanP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o -c /home/shay/CLionProjects/Ex2-shay/Tests/Test_HumanP.cpp

CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shay/CLionProjects/Ex2-shay/Tests/Test_HumanP.cpp > CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.i

CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shay/CLionProjects/Ex2-shay/Tests/Test_HumanP.cpp -o CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.s

CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o.requires:

.PHONY : CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o.requires

CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o.provides: CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ex2.dir/build.make CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o.provides.build
.PHONY : CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o.provides

CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o.provides.build: CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o


# Object files for target Ex2
Ex2_OBJECTS = \
"CMakeFiles/Ex2.dir/src/main.cpp.o" \
"CMakeFiles/Ex2.dir/src/Board.cpp.o" \
"CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o" \
"CMakeFiles/Ex2.dir/src/HumanP.cpp.o" \
"CMakeFiles/Ex2.dir/src/GameFlow.cpp.o" \
"CMakeFiles/Ex2.dir/src/Console.cpp.o" \
"CMakeFiles/Ex2.dir/gtest_main.cpp.o" \
"CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o" \
"CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o" \
"CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o" \
"CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o"

# External object files for target Ex2
Ex2_EXTERNAL_OBJECTS =

Ex2: CMakeFiles/Ex2.dir/src/main.cpp.o
Ex2: CMakeFiles/Ex2.dir/src/Board.cpp.o
Ex2: CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o
Ex2: CMakeFiles/Ex2.dir/src/HumanP.cpp.o
Ex2: CMakeFiles/Ex2.dir/src/GameFlow.cpp.o
Ex2: CMakeFiles/Ex2.dir/src/Console.cpp.o
Ex2: CMakeFiles/Ex2.dir/gtest_main.cpp.o
Ex2: CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o
Ex2: CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o
Ex2: CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o
Ex2: CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o
Ex2: CMakeFiles/Ex2.dir/build.make
Ex2: lib/googletest-master/googlemock/gtest/libgtestd.a
Ex2: lib/googletest-master/googlemock/gtest/libgtest_maind.a
Ex2: lib/googletest-master/googlemock/gtest/libgtestd.a
Ex2: CMakeFiles/Ex2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable Ex2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ex2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ex2.dir/build: Ex2

.PHONY : CMakeFiles/Ex2.dir/build

CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/src/main.cpp.o.requires
CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/src/Board.cpp.o.requires
CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/src/ReversiRules.cpp.o.requires
CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/src/HumanP.cpp.o.requires
CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/src/GameFlow.cpp.o.requires
CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/src/Console.cpp.o.requires
CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/gtest_main.cpp.o.requires
CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/Tests/Test_Board.cpp.o.requires
CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/Tests/Test_ReversiRules.cpp.o.requires
CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/src/AIPlayer.cpp.o.requires
CMakeFiles/Ex2.dir/requires: CMakeFiles/Ex2.dir/Tests/Test_HumanP.cpp.o.requires

.PHONY : CMakeFiles/Ex2.dir/requires

CMakeFiles/Ex2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ex2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ex2.dir/clean

CMakeFiles/Ex2.dir/depend:
	cd /home/shay/CLionProjects/Ex2-shay/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shay/CLionProjects/Ex2-shay /home/shay/CLionProjects/Ex2-shay /home/shay/CLionProjects/Ex2-shay/cmake-build-debug /home/shay/CLionProjects/Ex2-shay/cmake-build-debug /home/shay/CLionProjects/Ex2-shay/cmake-build-debug/CMakeFiles/Ex2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ex2.dir/depend

