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
)


add_executable(Ethernet-Parameters ${SOURCES})

# Add folders.
add_subdirectory(IPv4Address)
add_subdirectory(IPv6Address)

# Link libraries into project.
target_link_libraries( ${PROJECT_NAME}
    IP_V4_LIBRARY
    IP_V6_LIBRARY

    )

    

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
