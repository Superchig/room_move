#include <iostream>
#include <memory>
#include <utility>
#include <typeinfo>
#include "mob.hpp"
#include "room.hpp"
#include "invalid_key.hpp"

void RoomMove::Mob::say(std::string message) const {
	std::cout << name << ": " << message << '\n';
}

void RoomMove::Mob::move_room(Exit exit) {
	if (auto shared_room = room.lock()) {
		if (shared_room->find(exit) == shared_room->end()) {
			throw InvalidKey("Could not find Exit in vector.\n"
				"Mob's room did not have matching exit.");
		}

		// Should refactor to auto& once testing (specification) is completed.
		const std::pair<Exit, std::weak_ptr<Room>>& exit_room_pair = *shared_room->find(exit);
		const std::weak_ptr<Room>& new_room = std::get<1>(exit_room_pair);
		room = new_room;
		return;
	}

	throw std::bad_weak_ptr();
}
