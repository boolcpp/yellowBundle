cmake_minimum_required(VERSION 2.8)

project(test)

set(CMAKE_CXX_STANDARD 11)

##boost

#set (Boost_DETAILED_FAILURE_MSG ON)
#set (Boost_THREADAPI win32)
set (BOOST_ROOT "C:/boost_1_70_0/boost_mingw730_64")
set (Boost_LIBRARY_DIR  "C:/boost_1_70_0/boost_mingw730_64/lib")
#set (Boost_COMPILER "-vc")
#set (Boost_USE_STATIC_RUNTIME ON)
#set (BOOST_DEBUG ON)  #<---------- Real life saver

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    MESSAGE( WARNING "found BOOST!" )
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    #ADD_DEFINITIONS( "-DHAS_BOOST" )
ELSE(Boost_FOUND)
    MESSAGE( WARNING "NO boost!" )
ENDIF()

##endboost

#if ( CMAKE_COMPILER_IS_GNUCC )
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra")
#endif()

add_executable(${PROJECT_NAME} "main.cpp")

if(MINGW)
  MESSAGE( WARNING "MINGW USING!" )
  target_link_libraries(test ws2_32)
endif()
