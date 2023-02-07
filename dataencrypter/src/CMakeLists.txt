cmake_minimum_required(VERSION 3.10)

project(dataencrypter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add sources and flags
set(SOURCES Utils.cpp Main.cpp Crypt.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -std=c++17")

add_executable(dataencrypter-ex ${SOURCES})