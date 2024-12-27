cmake_minimum_required(VERSION 3.10)
project(ccpGui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Test)

add_executable(ccpGui main.cpp)

target_link_libraries(ccpGui PUBLIC Test)

target_include_directories(ccpGui PUBLIC "${PROJECT_SOURCE_DIR}/test")
set_target_properties(ccpGui PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")