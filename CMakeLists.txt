cmake_minimum_required(VERSION 3.5)
project(example_exec VERSION 0.0.1 LANGUAGES CXX)


add_executable(unitTest src/unitTest.cpp src/readTimestamp.cpp src/binarySearch.cpp src/TimeStampCollection.cpp)
target_include_directories(unitTest PRIVATE src/readTimestamp.hpp src/binarySearch.hpp src/TimeStampCollection.hpp)
set_target_properties(unitTest PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_executable(hnStat src/hnStat.cpp src/readTimestamp.cpp src/binarySearch.cpp src/TimeStampCollection.cpp)
target_include_directories(hnStat PRIVATE src/readTimestamp.hpp src/binarySearch.hpp src/TimeStampCollection.hpp)
set_target_properties(hnStat PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)