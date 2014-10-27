#pragma once
#include "GraphBase.h"

#include <Utils\Allocator.h>
#include <vector>

using namespace std;
using namespace VOB::Utils;

namespace VOB
{
	namespace GameData
	{

		class Door;

		VOB_CREATE_EXCEPTION_EXPORTABLE(RoomException, Exception);

		class DllExport Room :
			public GraphBase
		{
		public:

			typedef vector<Door *> DoorList;

		private:

			/*
			door should be created only from rooms
			*/
			Allocator<Door> doorAllocator;

			/*
			list of output doors
			*/
			DoorList outDoors;

			/*
			list if input doors
			*/
			DoorList inDoors;

			/*
			remove door from given list
			if autoDelete is true, door is deleted when it is found
			*/
			void removeDoorFromList(DoorList &list, Door *door, bool autoDelete=true);

			/*
			remove door from given list by door index
			door is deleted when it is found
			exception is thrown when index does not exist
			*/
			void removeDoorFromList(DoorList &list, unsigned int index);

		public:
			Room();
			virtual ~Room();

			/*
			create door from current instance of room to another
			*/
			Door *CreateDoor(Room *to);

			/*
			return constant reference on list of in doors
			*/
			const DoorList GetInDoors() const;

			/*
			return constant reference on list of out doors
			*/
			const DoorList GetOutDoors() const;

			/*
			remove out door on given index
			if index does not exist, exception will be raised
			*/
			void RemoveOutDoor(int index);

			/*
			remove out door by pointer
			if this door is not found, nothing happend
			*/
			void RemoveOutDoor(Door *door);

			/*
			remove in door on given index
			if index does not exist, exception will be raised
			*/
			void RemoveInDoor(int index);

			/*
			remove in door by pointer
			if this door is not found, nothing happend
			*/
			void RemoveInDoor(Door *door);

		};

	}
}