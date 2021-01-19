cmake_minimum_required(VERSION 2.8.7)
project(rotationEvalution)

#set(CMAKE_BUILD_TYPE  Debug)
IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

set(CMAKE_CXX_STANDARD 11)
FIND_PACKAGE( OpenCV )
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )

FIND_PACKAGE( OpenMP )

include_directories(.)
include_directories(/usr/local/include)

add_executable(longestprefix longestprefix.cpp)
add_executable(vecotrcopy vectorcopy.cpp)
# TARGET_LINK_LIBRARIES(rotationEvalution LINK_PUBLIC ${OpenCV_LIBS} pthread)

if(OpenMP_CXX_FOUND)
    target_link_libraries(longestprefix PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(vecotrcopy PUBLIC OpenMP::OpenMP_CXX)
endif()


