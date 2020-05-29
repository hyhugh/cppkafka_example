cmake_minimum_required(VERSION 3.7.2)
project(kafka_cpp_example)

add_subdirectory(cppkafka)
include_directories(cppkafka/include)
add_subdirectory(consumer)
add_subdirectory(producer)
