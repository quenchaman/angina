cmake_minimum_required(VERSION 3.5.1)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(${DIR}/cmake_helpers/helpers.cmake)

project(angina)

add_executable(${PROJECT_NAME} ${DIR}/main.cpp)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})
