cmake_minimum_required(VERSION 2.8.4)
project(cg45-proj C CXX)

include_directories(include)

find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)

set(HEADER_FILES
  include/bus.h
  include/camera.h
  include/car.h
  include/dynamic_object.h
  include/entity.h
  include/frog.h
  include/game_manager.h
  include/game_object.h
  include/light_source.h
  include/opengl.h
  include/orthogonal_camera.h
  include/perspective_camera.h
  include/river.h
  include/road.h
  include/static_object.h
  include/timberlog.h
  include/turtle.h
  include/vector3.h
  include/vector4.h
  include/tunnel.h)

set(SOURCE_FILES
  src/bus.cpp
  src/camera.cpp
  src/car.cpp
  src/dynamic_object.cpp
  src/entity.cpp
  src/frog.cpp
  src/frog_leg.cpp
  src/game_manager.cpp
  src/game_object.cpp
  src/light_source.cpp
  src/main.cpp
  src/orthogonal_camera.cpp
  src/perspective_camera.cpp
  src/river.cpp
  src/road.cpp
  src/static_object.cpp
  src/timberlog.cpp
  src/truck.cpp
  src/turtle.cpp
  src/vector3.cpp
  src/vector4.cpp
  src/tunnel.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic -lglut -lGL -lGLU")

add_executable(cg45-proj ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(cg45-proj ${CMAKE_THREAD_LIBS_INIT} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

