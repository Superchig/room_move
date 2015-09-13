#include <iostream>
#include <memory>
#include "catch.hpp"
#include "../src/mob.hpp"
#include "../src/room.hpp"

using RoomMove::Mob;
using RoomMove::Room;
using RoomMove::Exit;
using std::cout;
using std::make_shared;
using std::make_unique;

SCENARIO("Mobs are added and removed from Rooms", "[movement]") {
	GIVEN("A room and a mob.") {
		auto chiggie = Mob("Christopher Chang");
		auto computer = Room("Computer Room");

		WHEN("A mob is added to a room.") {
			computer.add_mob(&chiggie);

			THEN("There is one more mob in the room.") {
				REQUIRE(computer.num_mobs() == 1);
			}
		}
		AND_WHEN("A mob is removed from the room.") {
			computer.remove_mob(&chiggie);

			THEN("There is one less mob in the room.") {
				REQUIRE(computer.num_mobs() == 0);
			}
		}
	}
}

SCENARIO("A mob moves between two rooms.", "[movement]") {
	GIVEN("A mob and two connected rooms, and the mob is in one room.") {
		// Variables
		auto chiggie = Mob("Christopher Chang");

		auto kitchen = make_shared<Room>("Kitchen");
		auto dining = make_shared<Room>("Dining Hall");

		// Room connections and mobs.
		RoomMove::Room::connect(kitchen, dining, Exit::NORTH);
		kitchen->add_mob(&chiggie)
			.add_mob(make_unique<Mob>("Colin Chang").get())
			.add_mob(make_unique<Mob>("Cooper Chang").get())
			.add_mob(make_unique<Mob>("Forrest Chang").get());

		REQUIRE(kitchen->num_mobs() == 4);
		
		chiggie.set_room(std::weak_ptr<Room>(kitchen));

		WHEN("The mob moves to the other room") {
			chiggie.move_room(Exit::NORTH);

			THEN("The original room no longer has the mob.") {
				REQUIRE(kitchen->num_mobs() == 3);
			}
			AND_THEN("The other room has the mob.") {
				REQUIRE(dining->num_mobs() == 1);
			}
		}
	}
}
