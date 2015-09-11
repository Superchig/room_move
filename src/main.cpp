#include <iostream>
#include <memory>
#include "mob.hpp"
#include "room.hpp"

using RoomMove::Mob;
using RoomMove::Room;
using std::cout;

int main(const int, const char**)
{
	const auto chiggie= std::make_shared<Mob>("Christopher Chang");
	chiggie->say("Hello, world!");

	cout << "Adding chiggie to computer room." << '\n';

	Room computer;
	computer.add_mob(chiggie);

	cout << "Size of computer room is: " << computer.num_mobs() << '\n';

	cout << "Removing chiggie from computer room..." << '\n';
	computer.remove_mob(chiggie);
	cout << "Size of computer room is: " << computer.num_mobs() << '\n';

	return 0;
}
