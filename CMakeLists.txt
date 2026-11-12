cmake_minimum_required(VERSION 3.22)

project(corner-cam)

# Camer calibration script
add_executable(cam-calib calibration/main.cpp)
target_include_directories(cam-calib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Main corner camera algorithm
add_executable(corner-cam)
target_sources(corner-cam PRIVATE main.cpp)