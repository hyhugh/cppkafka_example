cmake_minimum_required(VERSION 3.17.0)
project(producer_test CXX)

add_executable(producer_test producer.cpp)
target_link_libraries(producer_test cppkafka)
target_include_directories(producer_test PUBLIC ${CppKafka_SOURCE_DIR}/include)


