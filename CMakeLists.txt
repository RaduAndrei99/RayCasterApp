cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
PROJECT(ray_caster_application)

add_library(rayCaster STATIC RayCaster/rayCaster.cpp)


add_executable(mainApp main.cpp)

target_link_libraries(mainApp rayCaster)


target_link_libraries(mainApp X11)
target_link_libraries(mainApp GL)
target_link_libraries(mainApp pthread)
target_link_libraries(mainApp png)