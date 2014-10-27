#pragma once
#include "GraphBase.h"

namespace VOB
{
	namespace GameData
	{

		class Room;

		VOB_CREATE_EXCEPTION_EXPORTABLE(NowhereDoorException, VOB::Utils::Exception);

		class Door :
			public GraphBase
		{

			/*
			start room
			*/
			Room *from;

			/*
			destination
			*/
			Room *to;

		public:
			/*
			create emptz instance
			*/
			Door();

			/*
			create full initialised instace
			*/
			Door(Room *from, Room *to);

			/*
			copytor
			*/
			Door(const Door &o) : GraphBase(o)
			{
			}

			/*
			destructor
			*/
			virtual ~Door();

			friend Room;

		};

	}
}