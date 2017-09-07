cmake_minimum_required(VERSION 3.8)
project(starter)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(starter src/glad.c src/window_helper.cpp src/main.cpp include/window_helper.h src/gl_helper.cpp src/gl_helper.h)
target_link_libraries(starter ${CMAKE_SOURCE_DIR}/lib/libglfw3.a)
