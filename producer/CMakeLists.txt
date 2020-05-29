cmake_minimum_required(VERSION 3.7.2)
project(producer_test CXX)

add_executable(producer_test producer.cpp)
target_link_libraries(producer_test cppkafka)


