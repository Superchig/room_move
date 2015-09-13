#include <iostream>
#include <memory>
#include <utility>
#include <typeinfo>
#include "mob.hpp"
#include "room.hpp"
#include "invalid_key.hpp"

RoomMove::Mob& RoomMove::Mob::say(std::string message) {
	std::cout << name << ": " << message << '\n';
	return *this;
}

RoomMove::Mob& RoomMove::Mob::move_room(Exit exit) {
	if (auto shared_room = room.lock()) {
		if (shared_room->find(exit) == shared_room->end()) {
			throw InvalidKey("Could not find Exit in vector.\n"
							 "Mob's room did not have matching exit.");
		}

		shared_room->remove_mob(this);
		room = shared_room->exit(exit);
		room.lock()->add_mob(this);

		return *this;
	}

	throw std::bad_weak_ptr();
}

RoomMove::Mob& RoomMove::Mob::set_room(std::weak_ptr<Room> new_room)
{
	room = new_room;
	return *this;
}
