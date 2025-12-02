cmake_minimum_required(VERSION 3.31)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(marcus-the-cube)

add_subdirectory(src)
add_subdirectory(vendor/glad)

find_package(glfw3 REQUIRED)

target_link_libraries(marcus PRIVATE glad glfw)
