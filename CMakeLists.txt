cmake_minimum_required(VERSION 3.3.1)
project(RoomMove)

enable_testing()

set(SPEC_FILES spec/spec.cpp
			   spec/room_mob_interaction_spec.cpp)

add_executable(suite ${SPEC_FILES}
					 src/room.cpp
					 src/mob.cpp)

add_executable(room_move src/room_move.cpp)

add_test(NAME suite
			  COMMAND ./suite)

set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

set_property(TARGET suite PROPERTY CXX_STANDARD 14)
set_property(TARGET suite PROPERTY CXX_STANDARD_REQUIRED ON)
