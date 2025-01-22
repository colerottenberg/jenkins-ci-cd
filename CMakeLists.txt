cmake_minimum_required(VERSION 3.10)

project(Testing
  VERSION 1.0
  DESCRIPTION "Testing Unity as a Unit Testing Library"
  LANGUAGES C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG v2.6.1
)

FetchContent_MakeAvailable(unity)

add_executable(Testing src/main.c)
target_include_directories(Testing PRIVATE include)


add_executable(test_runner test/always_pass.c)
target_link_libraries(test_runner PRIVATE unity)
target_include_directories(test_runner PRIVATE include)

enable_testing()
add_test(NAME always_pass COMMAND test_runner)
