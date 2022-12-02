cmake_minimum_required(VERSION 3.23)
project(VolleyballGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(VolleyballGame main.cpp src/Application.cpp src/Application.h)
target_link_libraries(VolleyballGame -lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system)
