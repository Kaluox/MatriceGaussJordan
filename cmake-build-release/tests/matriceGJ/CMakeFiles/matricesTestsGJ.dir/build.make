# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Matt\CLionProjects\MatriceGaussJordan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release

# Include any dependencies generated for this target.
include tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\depend.make

# Include the progress variables for this target.
include tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\progress.make

# Include the compile flags for this target's objects.
include tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\flags.make

tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\testsMatriceGaussJordan.cpp.obj: tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\flags.make
tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\testsMatriceGaussJordan.cpp.obj: ..\tests\matriceGJ\testsMatriceGaussJordan.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/matriceGJ/CMakeFiles/matricesTestsGJ.dir/testsMatriceGaussJordan.cpp.obj"
	cd C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release\tests\matriceGJ
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\matricesTestsGJ.dir\testsMatriceGaussJordan.cpp.obj /FdCMakeFiles\matricesTestsGJ.dir\ /FS -c C:\Users\Matt\CLionProjects\MatriceGaussJordan\tests\matriceGJ\testsMatriceGaussJordan.cpp
<<
	cd C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release

tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\testsMatriceGaussJordan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matricesTestsGJ.dir/testsMatriceGaussJordan.cpp.i"
	cd C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release\tests\matriceGJ
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\matricesTestsGJ.dir\testsMatriceGaussJordan.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Matt\CLionProjects\MatriceGaussJordan\tests\matriceGJ\testsMatriceGaussJordan.cpp
<<
	cd C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release

tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\testsMatriceGaussJordan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matricesTestsGJ.dir/testsMatriceGaussJordan.cpp.s"
	cd C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release\tests\matriceGJ
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\matricesTestsGJ.dir\testsMatriceGaussJordan.cpp.s /c C:\Users\Matt\CLionProjects\MatriceGaussJordan\tests\matriceGJ\testsMatriceGaussJordan.cpp
<<
	cd C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release

# Object files for target matricesTestsGJ
matricesTestsGJ_OBJECTS = \
"CMakeFiles\matricesTestsGJ.dir\testsMatriceGaussJordan.cpp.obj"

# External object files for target matricesTestsGJ
matricesTestsGJ_EXTERNAL_OBJECTS =

tests\matriceGJ\matricesTestsGJ.exe: tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\testsMatriceGaussJordan.cpp.obj
tests\matriceGJ\matricesTestsGJ.exe: tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\build.make
tests\matriceGJ\matricesTestsGJ.exe: code\matricesCode.lib
tests\matriceGJ\matricesTestsGJ.exe: tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable matricesTestsGJ.exe"
	cd C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release\tests\matriceGJ
	"C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\matricesTestsGJ.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100171~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100171~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\matricesTestsGJ.dir\objects1.rsp @<<
 /out:matricesTestsGJ.exe /implib:matricesTestsGJ.lib /pdb:C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release\tests\matriceGJ\matricesTestsGJ.pdb /version:0.0  /machine:X86 /INCREMENTAL:NO /subsystem:console ..\..\code\matricesCode.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release

# Rule to build all files generated by this target.
tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\build: tests\matriceGJ\matricesTestsGJ.exe

.PHONY : tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\build

tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\clean:
	cd C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release\tests\matriceGJ
	$(CMAKE_COMMAND) -P CMakeFiles\matricesTestsGJ.dir\cmake_clean.cmake
	cd C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release
.PHONY : tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\clean

tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Matt\CLionProjects\MatriceGaussJordan C:\Users\Matt\CLionProjects\MatriceGaussJordan\tests\matriceGJ C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release\tests\matriceGJ C:\Users\Matt\CLionProjects\MatriceGaussJordan\cmake-build-release\tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests\matriceGJ\CMakeFiles\matricesTestsGJ.dir\depend
