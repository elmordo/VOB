#pragma once

#include <exception>
#include <cstring>
#include <cstdlib>
#include "common.h"

using namespace std;

#define __VOB_CREATE_EXCEPTION(NEW_CLASS_NAME,BASE_CLASS_NAME,MODIFIER) class MODIFIER NEW_CLASS_NAME : public BASE_CLASS_NAME \
{\
public:\
	NEW_CLASS_NAME(){}\
	NEW_CLASS_NAME(const char *msg, int code) : BASE_CLASS_NAME(msg, code) {}\
	virtual ~NEW_CLASS_NAME() {}\
}

#define VOB_CREATE_EXCEPTION(NEW_CLASS_NAME,BASE_CLASS_NAME) __VOB_CREATE_EXCEPTION(NEW_CLASS_NAME, BASE_CLASS_NAME,)
#define VOB_CREATE_EXCEPTION_EXPORTABLE(NEW_CLASS_NAME,BASE_CLASS_NAME) __VOB_CREATE_EXCEPTION(NEW_CLASS_NAME, BASE_CLASS_NAME,DllExport)

namespace VOB
{
	namespace Utils
	{

		class DllExport Exception : public exception
		{

			/* message */
			char *msg;

			/* error code */
			int code;

			void freeData();

			void copyString(char **target, const char *source);

		public:

			/* 
			create empty instance 
			*/
			Exception();

			/*
			create full defined exception
			*/
			Exception(const char *msg, int code);

			/*
			destructor
			*/
			virtual ~Exception() _NOEXCEPT;

			/*
			return code
			*/
			int GetCode() const;

			/*
			return message
			*/
			virtual const char *what() const;

			/*
			name convention correct access method to message
			*/
			inline const char *What() const {
				return what();
			}

			/*
			assign operator
			*/
			Exception &operator =(const Exception &o);
		};

	}
}