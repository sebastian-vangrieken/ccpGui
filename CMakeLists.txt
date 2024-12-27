cmake_minimum_required(VERSION 3.10)
project(ccpGui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ccpGui main.cpp)

set_target_properties(ccpGui PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")