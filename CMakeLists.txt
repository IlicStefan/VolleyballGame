cmake_minimum_required(VERSION 3.23)
project(VolleyballGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(VolleyballGame main.cpp src/Application.cpp src/Application.h src/Game.cpp src/Game.h src/Pause.cpp src/Pause.h src/MainMenu.cpp src/MainMenu.h src/ApplicationState.h src/ApplicationStatus.h)
target_link_libraries(VolleyballGame -lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system)
