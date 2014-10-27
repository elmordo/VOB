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
			inline ITEM_TYPE *allocate(int n)
			{
				return new ITEM_TYPE[n];
			}

			/*
			allocate n fields for ITEM_TYPE and initialize them by prototype
			*/
			inline ITEM_TYPE *allocate(int n, const ITEM_TYPE &prototype)
			{
				// allocate memory
				ITEM_TYPE *retVal = allocate(n);

				// construct items
				for (int i = 0; i < n; ++i)
				{
					construct(retVal + i, prototype);
				}

				return retVal;
			}

			/*
			create new object on allocated space (do not allocate new memory)
			*/
			inline ITEM_TYPE *construct(ITEM_TYPE *place, const ITEM_TYPE &prototype)
			{
				new (place)ITEM_TYPE(prototype);

				return place;
			}

			/*
			deallocate memory (return memory back to OS)
			*/
			inline void deallocate(ITEM_TYPE *p)
			{
				delete[] p;
			}

			Allocator<ITEM_TYPE> &operator =(const Allocator<ITEM_TYPE> &o)
			{
				return *this;
			}
		};

	}
}