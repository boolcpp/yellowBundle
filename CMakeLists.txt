cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)

#if ( CMAKE_COMPILER_IS_GNUCC )
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra")
#endif()

project(test)
add_executable(${PROJECT_NAME} "main.cpp")
