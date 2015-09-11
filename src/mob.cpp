#include <iostream>
#include "mob.hpp"

void RoomMove::Mob::say(std::string message) const {
	std::cout << name << ": " << message << '\n';
}
