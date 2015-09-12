#include <iostream>
#include <memory>
#include <algorithm>
#include <iterator>
#include "exit.hpp"
#include "room.hpp"

void RoomMove::Room::add_mob(const std::shared_ptr<Mob>& mob)
{
	mobs.push_back(mob);
}

void RoomMove::Room::remove_mob(const std::shared_ptr<Mob>& mob)
{
	// The comparison of shared_ptrs makes this possible.
	// If mobs were represented as unique_ptrs, these mobs could not be removed, as they cannot
	// point to the same object.
	mobs.erase(std::remove(mobs.begin(), mobs.end(), mob),
			   mobs.end());
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
