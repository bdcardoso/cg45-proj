cmake_minimum_required(VERSION 2.8.4)
project(cg45-proj)

include_directories(include)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(HEADER_FILES
    include/light_source.h
    include/vector3.h)

set(SOURCE_FILES
    src/main.cpp
    src/vector3.cpp)

add_executable(cg45-proj ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(cg45-proj ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
