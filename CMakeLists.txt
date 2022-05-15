CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
        test/test.cpp
        src/item.cpp
        src/entity.cpp
    )

ADD_EXECUTABLE(enemy
	Enemies/test.cpp
	Enemies/Boss.cpp
	Enemies/Minion.cpp
)

ADD_EXECUTABLE(weapon
	Weapon/test_weapon.cpp
        Weapon/weapon.cpp
)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

