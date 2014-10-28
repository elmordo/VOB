#include "stdafx.h"
#include "Player.h"
#include "Door.h"

namespace VOB
{
	namespace GameData
	{

		Player::Player()
		{
			position = 0x0;
		}

		Player::Player(const string &name, Room *position)
		{
			this->name = name;
			this->position = position;
		}


		Player::~Player()
		{
		}

		const string &Player::GetName() const
		{
			return name;
		}

		void Player::SetName(const string &name)
		{
			this->name = name;
		}

		Room *Player::GetPosition() const
		{
			return position;
		}

		void Player::SetPosition(Room *room)
		{
			position = room;
		}

		void Player::Transit(Door *door)
		{
			// check door from
			if (door->GetFrom() != position)
			{
				throw TransitException("Invalid door was given", 1);
			}

			// transit player to new position
			position = door->GetTo();
		}
	}
}