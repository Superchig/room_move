#include "exit.hpp"

namespace RoomMove {
// Declared in exit.hpp
RoomMove::Exit reverse_exit(RoomMove::Exit exit)
{
	using Exit = RoomMove::Exit;

	switch (exit) {
	case Exit::NORTH:
		return Exit::SOUTH;
	case Exit::SOUTH:
		return Exit::NORTH;
	case Exit::EAST:
		return Exit::WEST;
	case Exit::WEST:
		return Exit::EAST;
	case Exit::UP:
		return Exit::DOWN;
	case Exit::DOWN:
		return Exit::UP;
	case Exit::NORTHWEST:
		return Exit::SOUTHEAST;
	case Exit::SOUTHEAST:
		return Exit::NORTHWEST;
	case Exit::SOUTHWEST:
		return Exit::NORTHEAST;
	case Exit::NORTHEAST:
		return Exit::SOUTHWEST;
	}
}
}
