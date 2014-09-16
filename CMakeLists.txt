cmake_minimum_required(VERSION 2.8)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(l01_t1 lab1/t1.cpp)
target_link_libraries(l01_t1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
