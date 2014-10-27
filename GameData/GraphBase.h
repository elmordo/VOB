#pragma once

#include <string>

#include <Utils\Exception.h>

using namespace std;

namespace VOB
{
	namespace GameData
	{

		VOB_CREATE_EXCEPTION_EXPORTABLE(GraphCopyException, VOB::Utils::Exception);

		class DllExport GraphBase
		{

			/* element name */
			string name;

			/* element description */
			string description;

		public:
			GraphBase();

			GraphBase(const GraphBase &o);

			virtual ~GraphBase();

			/*
			return current name of element
			*/
			const string &GetName() const
			{
				return name;
			}

			/*
			set new name of element
			*/
			void SetName(const string &name)
			{
				this->name = name;
			}

			/*
			return current description of element
			*/
			const string &GetDesc() const
			{
				return description;
			}

			/*
			set new description of element
			*/
			void SetDesc(const string &desc)
			{
				this->description = desc;
			}

		};

	}
}