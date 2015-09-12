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

	void say(std::string message) const;
	void move_room(Exit exit);
};
}
#endif // MOB_HPP_
