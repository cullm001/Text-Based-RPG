CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)


ADD_EXECUTABLE(test
        src/main.cpp
        src/item.cpp
    )

ADD_EXECUTABLE(enemy
	Enemies/test.cpp
	Enemies/Boss.cpp
	Enemies/Minion.cpp
)
