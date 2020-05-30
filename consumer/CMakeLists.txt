cmake_minimum_required(VERSION 3.17.0)
project(consumer_test CXX)

add_executable(consumer_test consumer.cpp)
target_link_libraries(consumer_test cppkafka)
target_include_directories(consumer_test PUBLIC ${CppKafka_SOURCE_DIR}/include)
