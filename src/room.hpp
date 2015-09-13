#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include "mob.hpp"
#include "exit.hpp"

namespace RoomMove {
// MobPtr exists so I can change to shared_ptr, if desired.
using MobPtr = Mob*;
using MobVec = std::vector<MobPtr>;
using ExitMap = std::unordered_map<Exit, std::weak_ptr<Room>, ExitHash>;

class Room {
	MobVec mobs;
	std::string name;
	std::string desc;
	ExitMap exits;

public:
	Room();
	Room(std::string name) : name(name) {}
	Room(std::string name, std::string desc) : name(name), desc(desc) {}

	Room& add_mob(const MobPtr mob);
	Room& remove_mob(const MobPtr mob);
	MobVec::size_type num_mobs() const;
	// Basic movement and picking things up.
	void parse(const std::string& command);
	ExitMap::const_iterator find(const Exit& exit) const;
	ExitMap::const_iterator end() const;
	std::weak_ptr<Room> exit(Exit exit);
	static void connect(std::shared_ptr<Room>& room,
				   std::shared_ptr<Room>& other,
				   const Exit& exit);
};
}

#endif // ROOM_HPP_
