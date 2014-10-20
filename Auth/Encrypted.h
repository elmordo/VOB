#pragma once

#include <string>
#include "PasswordPolicy.h"

using namespace std;

namespace VOB
{
	namespace Auth
	{
		class DllExport Encrypted :
			public PasswordPolicy
		{

			static string hashPassword(const string &password, const string &salt);

		public:
			Encrypted();
			virtual ~Encrypted();

			virtual bool CheckPassword(const User &user, const string &password) const;

			virtual void SetPassword(User &user, const string &password) const;


		};

	}
}
