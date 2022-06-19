set(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_C_COMPILER "/usr/bin/clang-10" CACHE PATH "")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-10" CACHE PATH "")
# Note on -fPIC:
# * As the final output of Hyperspace is a shared lib the deps are required to be compiled with -fPIC even when they're
#    static by themselves.
# * Normally the deps are automatically built with -fPIC when VCPKG_LIBRARY_LINKAGE is dynamic
#    but when it's static there's no written law whether it'll be enabled or not.
# * Setting CMAKE_POSITION_INDEPENDENT_CODE here doesn't propagate on building deps.
# * Setting CMAKE_*_FLAGS_INIT will ignore -fPIC under certain circumstances. Setting CMAKE_*_FLAGS directly prevents
#   this (see https://github.com/microsoft/vcpkg/pull/12097 for a similar case).
string(APPEND CMAKE_C_FLAGS " --gcc-toolchain=/usr/gcc-4.8-clang-toolchain/ -D_GLIBCXX_USE_CXX11_ABI=0 -fPIC")
string(APPEND CMAKE_CXX_FLAGS " --gcc-toolchain=/usr/gcc-4.8-clang-toolchain/ -D_GLIBCXX_USE_CXX11_ABI=0 -fPIC")
set(CMAKE_C_FLAGS_DEBUG_INIT "-DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-DDEBUG")
set(CMAKE_C_FLAGS_RELEASE_INIT "-DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-DNDEBUG")
# Workaround for Lua
set(CMAKE_SHARED_LINKER_FLAGS_INIT "-lm")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-lm")

# Workaround for Lua: FindLua module in CMake seems to invoke `find_library(... m)` which doesn't work if anything is
# defined in CMAKE_FIND_ROOT_PATH. In that case the path to libm MUST be specified in both CMAKE_FIND_ROOT_PATH
# and CMAKE_SYSTEM_LIBRARY_PATH.
list(APPEND CMAKE_FIND_ROOT_PATH "/usr/gcc-4.8-clang-toolchain" "/usr/lib/x86_64-linux-gnu")
list(APPEND CMAKE_SYSTEM_LIBRARY_PATH "/usr/lib/x86_64-linux-gnu")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

