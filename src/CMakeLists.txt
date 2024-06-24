cmake_minimum_required(VERSION 3.10)
project(KokkosExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Find and include Kokkos
find_package(Kokkos REQUIRED)

add_executable(main main.cpp)

# Link Kokkos to the executable
target_link_libraries(main Kokkos::kokkos)

