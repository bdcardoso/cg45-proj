cmake_minimum_required(VERSION 2.8)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(l01_t1 lab1/t1.cpp)
add_executable(l01_t2 lab1/t2.cpp)
add_executable(l01_t3 lab1/t3.cpp)

target_link_libraries(l01_t1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(l01_t2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(l01_t3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

