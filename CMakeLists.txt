cmake_minimum_required(VERSION 3.23)
project(VolleyballGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(VolleyballGame main.cpp src/Application.cpp src/Application.h src/Game.cpp src/Game.h src/Pause.cpp src/Pause.h src/MainMenu.cpp src/MainMenu.h src/ApplicationState.h src/ApplicationStatus.h src/Constants.h src/Button.cpp src/Button.h src/ResourceManager.h src/Configuration.cpp src/Configuration.h src/Textures.h src/Fonts.h src/Ball.cpp src/Ball.h src/Net.cpp src/Net.h src/Player.cpp src/Player.h src/LeftPlayer.cpp src/LeftPlayer.h src/RightPlayer.cpp src/RightPlayer.h)
target_link_libraries(VolleyballGame -lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system)
