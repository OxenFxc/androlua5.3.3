cmake_minimum_required(VERSION 3.10)

# Project name
project(LuaAndroidModule C)

# Default values for module name and source file
if(NOT DEFINED MODULE_NAME)
    set(MODULE_NAME "mylib")
endif()

if(NOT DEFINED MODULE_SOURCE)
    # Default to a file named 'main.c' in the root if not specified
    set(MODULE_SOURCE "main.c")
endif()

message(STATUS "Configuring build for module: ${MODULE_NAME}")
message(STATUS "Source file: ${MODULE_SOURCE}")

# Create the shared library target
add_library(${MODULE_NAME} SHARED ${MODULE_SOURCE})

# Include the current directory to find lua.h, lauxlib.h, etc.
target_include_directories(${MODULE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link options for Android
# We need to allow undefined symbols because the Lua symbols (lua_pushstring, etc.)
# are provided by the host application that loads this module.
# The flag -Wl,--allow-shlib-undefined tells the linker not to fail on undefined symbols.
target_link_options(${MODULE_NAME} PRIVATE "-Wl,--allow-shlib-undefined")

# Find the Android logging library (optional but recommended for debugging)
find_library(log-lib log)

# Link the logging library if found
if(log-lib)
    target_link_libraries(${MODULE_NAME} ${log-lib})
endif()
