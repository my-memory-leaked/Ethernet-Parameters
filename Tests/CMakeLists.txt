cmake_minimum_required(VERSION 3.0.0)
project(ETHERNET-PARAMETERS-TESTS VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

enable_testing() 

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_SOURCE_DIR}/../Ethernet-Parameters)

add_subdirectory(IPv4Tests)
add_subdirectory(IPv6Tests)

# Create test executable.
add_executable(
  ${PROJECT_NAME} 
  Tests.cpp 
  )


# Now simply link against gtest or gtest_main as needed.
target_link_libraries(
    ${PROJECT_NAME} 
    gtest_main
    )

# Tests.
add_test(NAME Ip-v4-Address-Tests COMMAND IP_V4_LIBRARY_TESTS)
add_test(NAME Ip-v6-Address-Tests COMMAND IP_V6_LIBRARY_TESTS)