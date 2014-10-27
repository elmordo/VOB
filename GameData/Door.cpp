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
			locked = false;
		}

		Door::Door(Room *from, Room *to)
		{
			if (from == 0x0 || to == 0x0)
			{
				throw NowhereDoorException("Doors has one end 0x0", 13);
			}

			this->from = from;
			this->to = to;
			locked = false;
		}


		Door::~Door()
		{
		}

		Room *Door::GetFrom()
		{
			return from;
		}

		Room *Door::GetTo()
		{
			return to;
		}

		bool Door::GetLocked() const
		{
			return locked;
		}

		void Door::SetLocked(bool isLocked)
		{
			locked = isLocked;
		}

	}
}
