CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(ProjectName)
SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(player
	header/player_test.cpp
	src/player.cpp
)

ADD_EXECUTABLE(enemy
	header/Enemies/Boss.cpp
	header/Enemies/Minion.cpp
	header/Enemies/Enemy.hpp
	header/Enemies/enemy_test.cpp
)

