# cmake_minimum_required(VERSION 3.10)
# project(dataencrypter)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_executable(${PROJECT_NAME} Main.cpp Crypt.cpp)
# target_link_libraries(${PROJECT_NAME} stdc++)

# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
#                    COMMAND ${CMAKE_COMMAND} -E rename ${PROJECT_NAME} 
#                    ${CMAKE_BINARY_DIR}/testdir/${PROJECT_NAME})

cmake_minimum_required(VERSION 3.10)

project(dataencrypter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -std=c++17")

add_executable(dataencrypter_executable Main.cpp Crypt.cpp Utils.c)