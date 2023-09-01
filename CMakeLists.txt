cmake_minimum_required(VERSION 3.26)
project(ElementalPlusx2)

set(CMAKE_CXX_STANDARD 11)

add_executable(ElementalPlusx2 main.cpp
        src/Particle.cpp
        include/Particle.h
        src/Simulation.cpp
        include/Simulation.h
        src/Render.cpp
        include/Render.h)

# Find GLUT and OpenGL
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(ElementalPlusx2 ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})