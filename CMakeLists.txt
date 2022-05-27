CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(ProjectName)
SET(CMAKE_CXX_STANDARD 11)

 ADD_EXECUTABLE(player
 	header/player_test.cpp
	src/entity.cpp
	src/player.cpp
 	header/bag.hpp
    header/combat.hpp
  	header/Enemies/Boss.cpp
 	header/Enemies/Minion.cpp
 	header/Enemies/Enemy.hpp
	header/Weapon/weapon.hpp
	header/Weapon/weapon.cpp
 )

ADD_EXECUTABLE(weapon
	header/Weapon/test_weapon.cpp
	header/Weapon/weapon.hpp
	header/Weapon/weapon.cpp
)

ADD_EXECUTABLE(archetypes
	header/archetypes_test.cpp
	header/archetypes.hpp
	header/player.hpp
	src/entity.cpp
	src/player.cpp
	header/Weapon/weapon.hpp
	header/Weapon/weapon.cpp
)
