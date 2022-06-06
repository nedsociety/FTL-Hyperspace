set(CMAKE_SYSTEM_NAME Windows)

set(CMAKE_C_COMPILER "/usr/bin/clang-10" CACHE PATH "")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-10" CACHE PATH "")
set(CMAKE_C_FLAGS_INIT "-target i686-pc-windows-gnu -m32 -masm=intel")
set(CMAKE_CXX_FLAGS_INIT "-target i686-pc-windows-gnu -m32 -masm=intel")
set(CMAKE_C_FLAGS_DEBUG_INIT "-DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-DDEBUG")
set(CMAKE_C_FLAGS_RELEASE_INIT "-DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-DNDEBUG")

# From mingw-w64-i686-dev package
set(CMAKE_FIND_ROOT_PATH /usr/i686-w64-mingw32)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
