cmake_minimum_required(VERSION 3.14)
project(multi_indexed_sandbox)

add_subdirectory(googletest)


include_directories(. boost  googletest/googletest/include )

set(CMAKE_CXX_STANDARD 14)

add_executable(multi_indexed_sandbox main.cpp MapData_Gen.cpp MultiIndexTests.cpp CompositeKeyIndexTests.cpp)
target_link_libraries(multi_indexed_sandbox gtest)
