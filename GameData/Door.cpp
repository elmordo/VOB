#include "stdafx.h"
#include "Door.h"
#include "Room.h"

namespace VOB
{
	namespace GameData
	{


		Door::Door()
		{
			from = to = 0x0;
		}

		Door::Door(Room *from, Room *to)
		{
			if (from == 0x0 || to == 0x0)
			{
				throw NowhereDoorException("Doors has one end 0x0", 13);
			}

			this->from = from;
			this->to = to;

			from->outDoors.push_back(this);
			to->inDoors.push_back(this);
		}


		Door::~Door()
		{
			// remove doors from lists of rooms
			from->removeDoorFromList(from->outDoors, this);
			to->removeDoorFromList(to->inDoors, this);
		}

	}
}
