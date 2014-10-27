#pragma once
#include "GraphBase.h"

namespace VOB
{
	namespace GameData
	{

		class Room;

		VOB_CREATE_EXCEPTION_EXPORTABLE(NowhereDoorException, VOB::Utils::Exception);

		class DllExport Door :
			public GraphBase
		{

			/*
			start room
			*/
			Room *from;

			/*
			if it is true, door is locked
			*/
			bool locked;

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

			/*
			create instance and set it up
			*/
			template<class ALLOCATOR>
			static Door *CreateInstance(Room *from, Room *to, ALLOCATOR alloc)
			{
				Door *retVal = alloc.allocate(1);

				retVal->from = from;
				retVal->to = to;

				return retVal;
			}

			/*
			return source room
			*/
			Room *GetFrom();

			/*
			return target room
			*/
			Room *GetTo();

			/*
			return locked flag status
			*/
			bool GetLocked() const;

			/*
			set new locked flag status
			*/
			void SetLocked(bool isLocked)

		};

	}
}