#include "stdafx.h"
#include "Room.h"

namespace VOB
{
	namespace GameData
	{


		Room::Room()
		{
		}


		Room::~Room()
		{
		}

		void Room::removeDoorFromList(DoorList &list, const Door *door) {
			// iterate over all doors in list and search for one to remove
			for (DoorList::iterator pos = list.begin(); pos != list.end(); ++pos)
			{
				// test if door in iterator is one to remove
				if (*pos == door)
				{
					// we want remove this door
					list.erase(pos);
					return;
				}
			}
		}

	}
}