#include "stdafx.h"
#include "RoomManager.h"

namespace VOB
{
	namespace GameData
	{

		RoomManager::RoomManager()
		{
		}


		RoomManager::~RoomManager()
		{
			// iterate over all rooms and delete them
			while (rooms.size())
			{
				Room *r = rooms.back();
				rooms.pop_back();

				roomAllocator.deallocate(r);
			}
		}

		Room *RoomManager::CreateRoom()
		{
			Room *room = roomAllocator.allocate(1);
			rooms.push_back(room);

			return room;
		}

		const RoomManager::RoomList &RoomManager::GetRooms() const
		{
			return rooms;
		}

	}
}