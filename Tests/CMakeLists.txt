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

# Create test executable.
add_executable(${PROJECT_NAME} Tests.cpp)

# Now simply link against gtest or gtest_main as needed.
target_link_libraries(
    ${PROJECT_NAME} 
    gtest_main
    )

# Tests.
add_test(NAME MyTests COMMAND ${PARENT_PROJECT_NAME})
add_test(NAME MyTests2 COMMAND ${PARENT_PROJECT_NAME})
# include(GoogleTest)
