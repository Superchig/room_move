#ifndef MOB_HPP_
#define MOB_HPP_
#include <iostream>
#include <memory>
#include "exit.hpp"

namespace RoomMove {
// Forward declaration for Mob.room
class Room;

class Mob {
	std::string name;
	std::string title;
	// Weak_ptr to stop reference cycles.
	// Its room has a shared_ptr to it.
	std::weak_ptr<Room> room;

public:
	Mob(std::string name) : name(name) {};

	Mob& say(std::string message);
	Mob& move_room(Exit exit);
	Mob& set_room(std::weak_ptr<Room> new_room);
};
}
#endif // MOB_HPP_
