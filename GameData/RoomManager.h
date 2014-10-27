#pragma once

#include <vector>

#include <Utils\Allocator.h>
#include <Utils\Exception.h>

#include "Room.h"

using namespace std;
using namespace VOB::Utils;

namespace VOB
{
	namespace GameData
	{

		VOB_CREATE_EXCEPTION_EXPORTABLE(RoomManagerException, Exception);

		class DllExport RoomManager
		{
		public:

			/* type for room list */
			typedef vector<Room *> RoomList;

			/* allocator for rooms */
			typedef Allocator<Room> RoomAllocator;

		private:

			/* allocate rooms */
			RoomAllocator roomAllocator;

			/* list of rooms in manager (game) */
			RoomList rooms;

		public:

			/*
			create empty manager (game)
			*/
			RoomManager();

			/* 
			copytor is forbidden
			*/
			RoomManager(const RoomManager &o)
			{
				operator =(o);
			}

			/*
			destroy all existing rooms
			*/
			virtual ~RoomManager();

			/*
			create new instance of room and insert it into manager
			*/
			Room *CreateRoom();

			/*
			return list of rooms
			*/
			const RoomList &GetRooms() const;

			/*
			assign operator is forbidden
			*/
			RoomManager &operator =(const RoomManager &o) 
			{
				throw RoomManagerException("Manager can not be copied", 1);
			}
		};

	}
}
