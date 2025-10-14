cmake_minimum_required(VERSION 3.16)

project(Sema VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

#set(CMAKE_PREFIX_PATH C:/Qt/6.10.0/mingw_64)
#find_package(Qt6 REQUIRED COMPONENTS Mqtt)

#qt_standard_project_setup()

#qt_add_executable(${CMAKE_PROJECT_NAME}
#code/main.cpp
#)

FILE(GLOB_RECURSE SOURCES "code/*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt6::Mqtt)
#set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
#    WIN32_EXECUTABLE ON
#)