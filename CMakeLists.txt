project(gtk4 CXX)

# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)


add_executable(gtk4mm main.cpp)
target_link_libraries(gtk4mm PRIVATE ${GTKMM_LIBRARIES})


# Add other flags to the compiler
target_compile_options(gtk4mm PRIVATE ${GTKMM_CFLAGS_OTHER})

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
target_include_directories(gtk4mm PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_directories(gtk4mm PRIVATE ${GTKMM_LIBRARY_DIRS})
