#include <iostream>
#include <memory>
#include "catch.hpp"
#include "../src/mob.hpp"
#include "../src/room.hpp"

using RoomMove::Mob;
using RoomMove::Room;
using std::cout;

SCENARIO("Mobs are added and removed from Rooms", "[movement]") {
	GIVEN("A room and a mob.") {
		const auto chiggie = std::make_shared<Mob>("Christopher Chang");
		auto computer = Room("Computer Room");

		WHEN("A mob is added to a room.") {
			computer.add_mob(chiggie);

			THEN("There is one more mob in the room.") {
				REQUIRE(computer.num_mobs() == 1);
			}
			AND_THEN("The shared_ptr to the mob has another use count.") {
				REQUIRE(chiggie.use_count() == 2);
			}
		}
		AND_WHEN("A mob is removed from the room.") {
			computer.remove_mob(chiggie);

			THEN("There is one less mob in the room.") {
				REQUIRE(computer.num_mobs() == 0);
			}
			AND_THEN("The shared_ptr to the mob has one less use count.") {
				REQUIRE(chiggie.use_count() == 1);
			}
		}
	}
}
