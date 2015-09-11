#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include "mob.hpp"

namespace RoomMove {

//! Hash function for Exit class Enums.
struct ExitHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

//! Possible directions to exit a room.
enum class Exit {
	NORTH, SOUTH, EAST, WEST, UP, DOWN, NORTHWEST, NORTHEAST, SOUTHWEST, SOUTHEAST
};

// Mobs are stored as shared_ptrs because unique_ptrs makes removal impossible.
using MobVec = std::vector<std::shared_ptr<Mob>>;
using ExitMap = std::unordered_map<Exit, std::weak_ptr<Mob>, ExitHash>;

class Room {
	MobVec mobs;
	std::string name;
	std::string desc;
	ExitMap exits;

public:
	Room();
	Room(std::string name) : name(name) {}
	Room(std::string name, std::string desc) : name(name), desc(desc) {}

	void add_mob(const std::shared_ptr<Mob>& mob);
	void remove_mob(const std::shared_ptr<Mob>& mob);
	std::vector<std::shared_ptr<Mob>>::size_type num_mobs() const;
	// Basic movement and picking things up.
	void parse(const std::string command);
};
}

#endif // ROOM_HPP_
