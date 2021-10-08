cmake_minimum_required(VERSION 3.5.1)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(${DIR}/cmake_helpers/helpers.cmake)

project(angina)

add_executable(${PROJECT_NAME} ${DIR}/main.cpp)
