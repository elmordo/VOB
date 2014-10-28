#include "stdafx.h"
#include "Room.h"
#include "Door.h"

namespace VOB
{
	namespace GameData
	{


		Room::Room()
		{
		}


		Room::~Room()
		{
			// copy lists of doors
			DoorList inCopy(inDoors), outCopy(outDoors);

			// clear original lists (optimalisation reasons)
			inDoors.clear();
			outDoors.clear();

			// deallocate doors
			while (size_t i = inDoors.size())
				RemoveInDoor(i);

			while (size_t i = outDoors.size())
				RemoveOutDoor(i);
		}

		void Room::removeDoorFromList(DoorList &list, Door *door, bool autoDelete) {
			// iterate over all doors in list and search for one to remove
			for (DoorList::iterator pos = list.begin(); pos != list.end(); ++pos)
			{
				// test if door in iterator is one to remove
				if (*pos == door)
				{
					// we want remove this door
					list.erase(pos);

					// remove other side of door
					if (door->GetFrom() == this)
					{
						door->GetTo()->removeDoorFromList(door->GetTo()->inDoors, door, false);
					}
					else
					{
						door->GetFrom()->removeDoorFromList(door->GetFrom()->inDoors, door, false);
					}

					if (autoDelete)
						doorAllocator.deallocate(door);

					return;
				}
			}
		}

		Door *Room::CreateDoor(Room *to, const string &name, const string &description)
		{
			// create new instance
			Door *door = Door::CreateInstance(this, to, doorAllocator);
			door->SetName(name);
			door->SetDesc(description);

			// insert it into out door list
			outDoors.push_back(door);

			// insert it into in door list of other instance (we can do this because it is same class)
			to->inDoors.push_back(door);

			return door;
		}

		void Room::RemoveOutDoor(int index)
		{
			removeDoorFromList(outDoors, index);
		}

		void Room::RemoveOutDoor(Door *door)
		{
			removeDoorFromList(outDoors, door);
		}

		void Room::RemoveInDoor(int index) 
		{
			removeDoorFromList(inDoors, index);
		}

		void Room::RemoveInDoor(Door *door)
		{
			removeDoorFromList(inDoors, door);
		}

		void Room::removeDoorFromList(DoorList &list, unsigned int index) 
		{
			// check if index exist
			if (index < 0 || index >= list.size())
			{
				throw RoomException("Door not found", 1);
			}

			// call remove logic
			removeDoorFromList(list, list[index]);
		}

		const Room::DoorList Room::GetInDoors() const
		{
			return inDoors;
		}

		/*
		return constant reference on list of out doors
		*/
		const Room::DoorList Room::GetOutDoors() const
		{
			return outDoors;
		}

	}
}