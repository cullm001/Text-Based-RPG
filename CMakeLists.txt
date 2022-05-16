CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(player
	      src/entity.cpp
        src/player.cpp
        src/main.cpp
)

