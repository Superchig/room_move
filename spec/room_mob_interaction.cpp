#include <iostream>
#include <memory>
#include "catch.hpp"
#include "../src/mob.hpp"
#include "../src/room.hpp"

using RoomMove::Mob;
using RoomMove::Room;
using std::cout;

TEST_CASE("Mobs are added and removed from Rooms") {
	const auto chiggie = std::make_shared<Mob>("Christopher Chang");
	auto computer = Room("Computer Room");

	computer.add_mob(chiggie);
	REQUIRE(computer.num_mobs() == 1);

	SECTION("One more shared_ptr managing chiggie's location") {
		REQUIRE(chiggie.use_count() == 2);
	};

	computer.remove_mob(chiggie);

	SECTION("Back to one shared_ptr managing chiggie's location") {
		REQUIRE(chiggie.use_count() == 1);
	};
	
	REQUIRE(computer.num_mobs() == 0);
}
