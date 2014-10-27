#pragma once
#include "GraphBase.h"

#include <vector>

using namespace std;

namespace VOB
{
	namespace GameData
	{

		class Door;

		class Room :
			public GraphBase
		{
		public:

			typedef vector<Door *> DoorList;

		private:

			/*
			*/
			DoorList outDoors;

			/*
			*/
			DoorList inDoors;

			/*
			only remove door from given list
			*/
			void removeDoorFromList(DoorList &list, const Door *door);

		public:
			Room();
			virtual ~Room();

			friend Door;

		};

	}
}