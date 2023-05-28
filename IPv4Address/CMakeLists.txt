cmake_minimum_required(VERSION 3.0.0)
project(IP_V4_LIBRARY VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

# For now it is a static library. I may change it in the future.
add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE
    IPv4Address.cpp
)
