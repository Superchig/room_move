#ifndef EXIT_HPP_
#define EXIT_HPP_

#include <iostream>

namespace RoomMove {
//! Hash function for Exit class Enums.
struct ExitHash {
	template <typename T>
	std::size_t operator()(T t) const
	{
		return static_cast<std::size_t>(t);
	}
};

//! Possible directions to exit a room.
enum class Exit {
	NORTH, SOUTH, EAST, WEST, UP, DOWN, NORTHWEST, NORTHEAST, SOUTHWEST, SOUTHEAST,
		};
}

#endif // EXIT_HPP_
