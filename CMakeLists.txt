cmake_minimum_required(VERSION 3.17.0)
project(kafka_cpp_example)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_CXX_STANDARD 14)
include(FetchContent)
SET(FETCHCONTENT_QUIET OFF)
FetchContent_Declare(
  CppKafka
  GIT_REPOSITORY https://github.com/mfontanini/cppkafka
  GIT_TAG        master
)
FetchContent_MakeAvailable(CppKafka)

add_subdirectory(consumer)
add_subdirectory(producer)
