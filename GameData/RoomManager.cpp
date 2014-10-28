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

		Room *RoomManager::CreateRoom(const string &name, const string &description)
		{
			Room *room = roomAllocator.allocate(1);

			// set name and description
			room->SetDesc(description);
			room->SetName(name);

			// add it into room list
			rooms.push_back(room);

			return room;
		}

		const RoomManager::RoomList &RoomManager::GetRooms() const
		{
			return rooms;
		}

	}
}