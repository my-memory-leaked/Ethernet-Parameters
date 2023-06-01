cmake_minimum_required(VERSION 3.0.0)
project(IP_V4_LIBRARY_TESTS VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)


# Make executable to add to ctest.
add_executable(
  ${PROJECT_NAME} 
  IPv4Tests.cpp 
  )

# Link google test and IPv4 library.
target_link_libraries(
    ${PROJECT_NAME} 
    gtest_main
    IP_V4_LIBRARY
)
