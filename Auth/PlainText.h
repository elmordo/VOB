#pragma once
#include "PasswordPolicy.h"

namespace VOB
{
	namespace Auth
	{

		class DllExport PlainText :
			public PasswordPolicy
		{
		public:
			PlainText();
			virtual ~PlainText();

			virtual bool CheckPassword(const User &user, const string &password) const;

			virtual void SetPassword(User &user, const string &password) const;

		};

	}
}
