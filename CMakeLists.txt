cmake_minimum_required(VERSION 2.8)

project(acceleratedcpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR})

add_definitions("-Wall -Wextra")

add_subdirectory(chapter8)
add_subdirectory(chapter10)
add_subdirectory(comper)
file(GLOB apps_source "apps/*.cpp")
list(SORT apps_source)

set(exec_dependencies chapter8 comper chapter10)

message(STATUS "\n   Applications: ")
foreach(app_src_file ${apps_source})
    get_filename_component(app_base ${app_src_file} NAME_WE)
    message(STATUS "Adding application ${app_base}")
    add_executable(${app_base} ${app_src_file})
    target_link_libraries(${app_base} ${exec_dependencies})
endforeach(app_src_file)


