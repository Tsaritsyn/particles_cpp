cmake_minimum_required(VERSION 3.10)
project(particles_cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(particles_cpp main.cpp rendering/App.cpp rendering/App.h rendering.hpp common.hpp physics/Particle.cpp physics/Particle.h common.cpp physics/Object.h physics.hpp physics/ContinuousObject.cpp physics/ContinuousObject.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
