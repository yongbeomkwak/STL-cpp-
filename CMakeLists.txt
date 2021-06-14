cmake_minimum_required(VERSION 3.0.0)
project(STL VERSION 0.1.0)

SET (HEADER_INCLUDE_PATH "./include")


include(CTest)
enable_testing()
include_directories(${HEADER_INCLUDE_PATH})

add_executable(STL main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
