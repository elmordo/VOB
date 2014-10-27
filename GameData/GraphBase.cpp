#include "stdafx.h"
#include "GraphBase.h"


namespace VOB
{
	namespace GameData
	{

		GraphBase::GraphBase()
		{
		}

		GraphBase::GraphBase(const GraphBase &o)
		{
			throw GraphCopyException("Graph elements can not be copied", 13);
		}

		GraphBase::~GraphBase()
		{
		}

	}
}