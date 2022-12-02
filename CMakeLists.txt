cmake_minimum_required(VERSION 3.23)
project(VolleyballGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(VolleyballGame main.cpp)
target_link_libraries(VolleyballGame -lsfml-graphics -lsfml-window -lsfml-system)
