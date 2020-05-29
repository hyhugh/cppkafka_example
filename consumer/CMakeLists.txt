cmake_minimum_required(VERSION 3.7.2)
project(consumer_test CXX)

add_executable(consumer_test consumer.cpp)
target_link_libraries(consumer_test cppkafka)
