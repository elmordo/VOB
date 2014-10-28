#pragma once

#include <string>

#include <Utils\Exception.h>

#include "Room.h"

using namespace std;
using namespace VOB::Utils;

namespace VOB
{
	namespace GameData
	{

		VOB_CREATE_EXCEPTION_EXPORTABLE(PlayerException, Exception);
		VOB_CREATE_EXCEPTION_EXPORTABLE(TransitException, PlayerException);

		class DllExport Player
		{

			/* game name of player */
			string name;

			/* where is player in game? */
			Room *position;

		public:
			/*
			create empty instance
			*/
			Player();

			/*
			create instance with name and start position
			*/
			Player(const string &name, Room *position = 0x0);

			virtual ~Player();

			/*
			return current name of player
			*/
			const string &GetName() const;

			/*
			set new name to player
			*/
			void SetName(const string &name);

			/*
			return current position of player
			*/
			Room *GetPosition() const;

			/*
			set new position of player
			*/
			void SetPosition(Room *room);

			/*
			move player through door
			"from" is not current position, throw exception
			*/
			void Transit(Door *door);
		};

		
	}
}
