cmake_minimum_required(VERSION 3.14)
project(ImageProcessingLib)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Find Kokkos
find_package(Kokkos REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/convolution.cpp
    src/histogram_equalization.cpp
    src/segmentation.cpp
)

# Add the executable
add_executable(image_processing_lib main.cpp ${SOURCES})

# Link Kokkos
target_link_libraries(image_processing_lib Kokkos::kokkos)

