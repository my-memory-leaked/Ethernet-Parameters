cmake_minimum_required(VERSION 3.0.0)
project(Ethernet-Parameters VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

# Let compile warn about everything.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include(CTest)
enable_testing()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(SOURCES
    examples.cpp
    IPv4Address/IPv4Address.hpp
    IPv4Address/IPv4Address.cpp
    IPv6Address/IPv6Address.hpp
    IPv6Address/IPv6Address.cpp
)
add_executable(Ethernet-Parameters ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
