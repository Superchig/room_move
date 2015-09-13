#include <iostream>
#include <memory>
#include <algorithm>
#include <iterator>
#include "exit.hpp"
#include "room.hpp"

RoomMove::Room& RoomMove::Room::add_mob(const MobPtr mob)
{
	mobs.push_back(mob);
	return *this;
}

RoomMove::Room& RoomMove::Room::remove_mob(const MobPtr mob)
{
	// The comparison of shared_ptrs makes this possible.
	// If mobs were represented as unique_ptrs, these mobs could not be removed, as they cannot
	// point to the same object.
	mobs.erase(std::remove(mobs.begin(), mobs.end(), mob),
			   mobs.end());
	return *this;
}

RoomMove::MobVec::size_type RoomMove::Room::num_mobs() const
{
	return mobs.size();
}

RoomMove::ExitMap::const_iterator RoomMove::Room::find(const Exit& exit) const
{
	return exits.find(exit);
}

RoomMove::ExitMap::const_iterator RoomMove::Room::end() const
{
	return exits.end();
}

void RoomMove::Room::connect(std::shared_ptr<Room>& room,
							 std::shared_ptr<Room>& other,
							 const Exit& exit)
{
	room->exits.insert({exit, std::weak_ptr<Room>(other)});
	other->exits.insert({reverse_exit(exit), std::weak_ptr<Room>(room)});
}

std::weak_ptr<RoomMove::Room> RoomMove::Room::exit(Exit exit)
{
	return exits[exit];
}
