#pragma once

#include ""

namespace VOB {
	namespace Auth {

		class PasswordPolicy
		{
		public:
			PasswordPolicy();
			virtual ~PasswordPolicy();

			virtual bool CheckPassword(const User &user) const = 0;
		};

	}
}
