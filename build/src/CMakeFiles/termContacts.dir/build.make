# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\Users\Acer\scoop\apps\cmake\3.27.3\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Acer\scoop\apps\cmake\3.27.3\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Acer\C++ Programs\Term Contacts"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Acer\C++ Programs\Term Contacts\build"

# Include any dependencies generated for this target.
include src/CMakeFiles/termContacts.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/termContacts.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/termContacts.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/termContacts.dir/flags.make

src/CMakeFiles/termContacts.dir/main.cpp.obj: src/CMakeFiles/termContacts.dir/flags.make
src/CMakeFiles/termContacts.dir/main.cpp.obj: src/CMakeFiles/termContacts.dir/includes_CXX.rsp
src/CMakeFiles/termContacts.dir/main.cpp.obj: C:/Users/Acer/C++\ Programs/Term\ Contacts/src/main.cpp
src/CMakeFiles/termContacts.dir/main.cpp.obj: src/CMakeFiles/termContacts.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Acer\C++ Programs\Term Contacts\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/termContacts.dir/main.cpp.obj"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/termContacts.dir/main.cpp.obj -MF CMakeFiles\termContacts.dir\main.cpp.obj.d -o CMakeFiles\termContacts.dir\main.cpp.obj -c "C:\Users\Acer\C++ Programs\Term Contacts\src\main.cpp"

src/CMakeFiles/termContacts.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/termContacts.dir/main.cpp.i"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Acer\C++ Programs\Term Contacts\src\main.cpp" > CMakeFiles\termContacts.dir\main.cpp.i

src/CMakeFiles/termContacts.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/termContacts.dir/main.cpp.s"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Acer\C++ Programs\Term Contacts\src\main.cpp" -o CMakeFiles\termContacts.dir\main.cpp.s

src/CMakeFiles/termContacts.dir/modules/contact.cpp.obj: src/CMakeFiles/termContacts.dir/flags.make
src/CMakeFiles/termContacts.dir/modules/contact.cpp.obj: src/CMakeFiles/termContacts.dir/includes_CXX.rsp
src/CMakeFiles/termContacts.dir/modules/contact.cpp.obj: C:/Users/Acer/C++\ Programs/Term\ Contacts/src/modules/contact.cpp
src/CMakeFiles/termContacts.dir/modules/contact.cpp.obj: src/CMakeFiles/termContacts.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Acer\C++ Programs\Term Contacts\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/termContacts.dir/modules/contact.cpp.obj"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/termContacts.dir/modules/contact.cpp.obj -MF CMakeFiles\termContacts.dir\modules\contact.cpp.obj.d -o CMakeFiles\termContacts.dir\modules\contact.cpp.obj -c "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\contact.cpp"

src/CMakeFiles/termContacts.dir/modules/contact.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/termContacts.dir/modules/contact.cpp.i"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\contact.cpp" > CMakeFiles\termContacts.dir\modules\contact.cpp.i

src/CMakeFiles/termContacts.dir/modules/contact.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/termContacts.dir/modules/contact.cpp.s"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\contact.cpp" -o CMakeFiles\termContacts.dir\modules\contact.cpp.s

src/CMakeFiles/termContacts.dir/modules/contact_manager.cpp.obj: src/CMakeFiles/termContacts.dir/flags.make
src/CMakeFiles/termContacts.dir/modules/contact_manager.cpp.obj: src/CMakeFiles/termContacts.dir/includes_CXX.rsp
src/CMakeFiles/termContacts.dir/modules/contact_manager.cpp.obj: C:/Users/Acer/C++\ Programs/Term\ Contacts/src/modules/contact_manager.cpp
src/CMakeFiles/termContacts.dir/modules/contact_manager.cpp.obj: src/CMakeFiles/termContacts.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Acer\C++ Programs\Term Contacts\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/termContacts.dir/modules/contact_manager.cpp.obj"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/termContacts.dir/modules/contact_manager.cpp.obj -MF CMakeFiles\termContacts.dir\modules\contact_manager.cpp.obj.d -o CMakeFiles\termContacts.dir\modules\contact_manager.cpp.obj -c "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\contact_manager.cpp"

src/CMakeFiles/termContacts.dir/modules/contact_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/termContacts.dir/modules/contact_manager.cpp.i"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\contact_manager.cpp" > CMakeFiles\termContacts.dir\modules\contact_manager.cpp.i

src/CMakeFiles/termContacts.dir/modules/contact_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/termContacts.dir/modules/contact_manager.cpp.s"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\contact_manager.cpp" -o CMakeFiles\termContacts.dir\modules\contact_manager.cpp.s

src/CMakeFiles/termContacts.dir/modules/file_io.cpp.obj: src/CMakeFiles/termContacts.dir/flags.make
src/CMakeFiles/termContacts.dir/modules/file_io.cpp.obj: src/CMakeFiles/termContacts.dir/includes_CXX.rsp
src/CMakeFiles/termContacts.dir/modules/file_io.cpp.obj: C:/Users/Acer/C++\ Programs/Term\ Contacts/src/modules/file_io.cpp
src/CMakeFiles/termContacts.dir/modules/file_io.cpp.obj: src/CMakeFiles/termContacts.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Acer\C++ Programs\Term Contacts\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/termContacts.dir/modules/file_io.cpp.obj"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/termContacts.dir/modules/file_io.cpp.obj -MF CMakeFiles\termContacts.dir\modules\file_io.cpp.obj.d -o CMakeFiles\termContacts.dir\modules\file_io.cpp.obj -c "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\file_io.cpp"

src/CMakeFiles/termContacts.dir/modules/file_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/termContacts.dir/modules/file_io.cpp.i"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\file_io.cpp" > CMakeFiles\termContacts.dir\modules\file_io.cpp.i

src/CMakeFiles/termContacts.dir/modules/file_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/termContacts.dir/modules/file_io.cpp.s"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\file_io.cpp" -o CMakeFiles\termContacts.dir\modules\file_io.cpp.s

src/CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.obj: src/CMakeFiles/termContacts.dir/flags.make
src/CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.obj: src/CMakeFiles/termContacts.dir/includes_CXX.rsp
src/CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.obj: C:/Users/Acer/C++\ Programs/Term\ Contacts/src/modules/unicode_ui.cpp
src/CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.obj: src/CMakeFiles/termContacts.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Acer\C++ Programs\Term Contacts\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.obj"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.obj -MF CMakeFiles\termContacts.dir\modules\unicode_ui.cpp.obj.d -o CMakeFiles\termContacts.dir\modules\unicode_ui.cpp.obj -c "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\unicode_ui.cpp"

src/CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.i"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\unicode_ui.cpp" > CMakeFiles\termContacts.dir\modules\unicode_ui.cpp.i

src/CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.s"
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && C:\PROGRA~1\MinGW\bin\C__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Acer\C++ Programs\Term Contacts\src\modules\unicode_ui.cpp" -o CMakeFiles\termContacts.dir\modules\unicode_ui.cpp.s

# Object files for target termContacts
termContacts_OBJECTS = \
"CMakeFiles/termContacts.dir/main.cpp.obj" \
"CMakeFiles/termContacts.dir/modules/contact.cpp.obj" \
"CMakeFiles/termContacts.dir/modules/contact_manager.cpp.obj" \
"CMakeFiles/termContacts.dir/modules/file_io.cpp.obj" \
"CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.obj"

# External object files for target termContacts
termContacts_EXTERNAL_OBJECTS =

C:/Users/Acer/C++\ Programs/Term\ Contacts/bin/termContacts.exe: src/CMakeFiles/termContacts.dir/main.cpp.obj
C:/Users/Acer/C++\ Programs/Term\ Contacts/bin/termContacts.exe: src/CMakeFiles/termContacts.dir/modules/contact.cpp.obj
C:/Users/Acer/C++\ Programs/Term\ Contacts/bin/termContacts.exe: src/CMakeFiles/termContacts.dir/modules/contact_manager.cpp.obj
C:/Users/Acer/C++\ Programs/Term\ Contacts/bin/termContacts.exe: src/CMakeFiles/termContacts.dir/modules/file_io.cpp.obj
C:/Users/Acer/C++\ Programs/Term\ Contacts/bin/termContacts.exe: src/CMakeFiles/termContacts.dir/modules/unicode_ui.cpp.obj
C:/Users/Acer/C++\ Programs/Term\ Contacts/bin/termContacts.exe: src/CMakeFiles/termContacts.dir/build.make
C:/Users/Acer/C++\ Programs/Term\ Contacts/bin/termContacts.exe: src/CMakeFiles/termContacts.dir/linkLibs.rsp
C:/Users/Acer/C++\ Programs/Term\ Contacts/bin/termContacts.exe: src/CMakeFiles/termContacts.dir/objects1.rsp
C:/Users/Acer/C++\ Programs/Term\ Contacts/bin/termContacts.exe: src/CMakeFiles/termContacts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\Acer\C++ Programs\Term Contacts\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable \"C:\Users\Acer\C++ Programs\Term Contacts\bin\termContacts.exe\""
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\termContacts.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/termContacts.dir/build: C:/Users/Acer/C++\ Programs/Term\ Contacts/bin/termContacts.exe
.PHONY : src/CMakeFiles/termContacts.dir/build

src/CMakeFiles/termContacts.dir/clean:
	cd /d C:\Users\Acer\C__PRO~1\TERMCO~1\build\src && $(CMAKE_COMMAND) -P CMakeFiles\termContacts.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/termContacts.dir/clean

src/CMakeFiles/termContacts.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Acer\C++ Programs\Term Contacts" "C:\Users\Acer\C++ Programs\Term Contacts\src" "C:\Users\Acer\C++ Programs\Term Contacts\build" "C:\Users\Acer\C++ Programs\Term Contacts\build\src" "C:\Users\Acer\C++ Programs\Term Contacts\build\src\CMakeFiles\termContacts.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : src/CMakeFiles/termContacts.dir/depend

