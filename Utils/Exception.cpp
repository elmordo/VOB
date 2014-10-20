#include "stdafx.h"
#include "Exception.h"

namespace VOB
{
	namespace Utils
	{

		Exception::Exception()
		{
			code = 0;
			msg = 0x0;
		}

		Exception::Exception(const char *msg, int code) 
		{
			this->code = code;
			copyString(&this->msg, msg);
		}

		Exception::~Exception() 
		{
			// erase string
			freeData();
		}

		void Exception::freeData()
		{
			if (msg != 0x0)
			{
				delete[] msg;
				msg = 0x0;
			}

		}

		void Exception::copyString(char **target, const char *source)
		{
			// get length of source
			int length = strlen(source);

			*target = new char[length + 1];
			char *tChar = *target;

			tChar[length] = 0x0;
			strcpy_s(tChar, length, source);
		}

		const char *Exception::what() const
		{
			return msg;
		}

		int Exception::GetCode() const
		{
			return code;
		}

		Exception &Exception::operator=(const Exception &o) 
		{
			// clear current data
			freeData();

			// copy data
			code = o.code;
			copyString(&msg, o.msg);

			return *this;
		}

	}
}