#pragma once

#include <string>
#include "User.h"

using namespace std;

namespace VOB
{
	namespace Auth
	{
		class DllExport PasswordPolicy
		{
		public:
			PasswordPolicy();
			virtual ~PasswordPolicy();

			/*
			check if password is correct
			*/
			virtual bool CheckPassword(const User &user, const string &password) const = 0;

			/*
			set new password to user
			*/
			virtual void SetPassword(User &user, const string &password) const = 0;

		};

	}
}