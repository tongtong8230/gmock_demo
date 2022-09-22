cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

# set the project name
project(gmock_test)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

# Setup testing
enable_testing()

include_directories(PROJECT_SOURCE_DIR)

# add the executable
add_executable(test_ test.cc sonar.cc)
# target_compile_options(main PRIVATE -D_UNICODE) # for windows
target_link_libraries(test_ gtest gtest_main gmock gmock_main)