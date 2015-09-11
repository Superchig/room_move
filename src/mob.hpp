#ifndef MOB_HPP_
#define MOB_HPP_
#include <iostream>

namespace RoomMove {
class Mob {
	std::string name;

public:
	Mob(std::string name) : name(name) {};

	void say(std::string message) const;
};
}
#endif // MOB_HPP_
