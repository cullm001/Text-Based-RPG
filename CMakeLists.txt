CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

# ADD_EXECUTABLE(player
#  	header/player_test.cpp
# 	src/entity.cpp
# 	src/player.cpp
#  	header/bag.hpp
#     header/combat.hpp
#   	header/Enemies/Boss.cpp
#  	header/Enemies/Minion.cpp
#  	header/Enemies/Enemy.hpp
# 	header/Weapon/weapon.hpp
# 	header/Weapon/weapon.cpp
# )

# ADD_EXECUTABLE(weapon
# 	header/Weapon/test_weapon.cpp
# 	header/Weapon/weapon.hpp
# 	header/Weapon/weapon.cpp
# )

# ADD_EXECUTABLE(archetypes
# 	header/archetypes_test.cpp
# 	header/archetypes.hpp
# 	header/player.hpp
# 	src/entity.cpp
# 	src/player.cpp
# 	header/Weapon/weapon.hpp
# 	header/Weapon/weapon.cpp
# )

ADD_EXECUTABLE(test
	unit_tests/test.cpp
	header/Enemies/Boss.cpp
	header/Enemies/Minion.cpp
	header/Weapon/weapon.cpp
	src/entity.cpp
	src/player.cpp
)

ADD_EXECUTABLE(story
	src/main.cpp
	src/player.cpp
	src/entity.cpp
        header/Enemies/Minion.cpp
        header/Enemies/Boss.cpp
        header/Weapon/weapon.cpp
)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
