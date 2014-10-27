#pragma once

namespace VOB
{
	namespace Utils
	{
		template<typename ITEM_TYPE>
		class Allocator
		{
		public:

			Allocator()
			{
			}

			Allocator(const Allocator &o)
			{
				operator=(o);
			}

			virtual ~Allocator()
			{
			}

			/*
			allocate memory for n objects
			*/
			ITEM_TYPE *allocate(int n)
			{
				return new ITEM_TYPE[n];
			}

			/*
			create new object on allocated space (do not allocate new memory)
			*/
			ITEM_TYPE *construct(ITEM_TYPE *place, const ITEM_TYPE &prototype)
			{
				new (place)ITEM_TYPE(prototype);
			}

			/*
			deallocate memory (return memory back to OS)
			*/
			void deallocate(ITEM_TYPE *p)
			{
				delete[] p;
			}

			Allocator<ITEM_TYPE> &operator =(const Allocator<ITEM_TYPE> &o)
			{
			}
		};

	}
}