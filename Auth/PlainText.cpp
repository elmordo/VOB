#include "stdafx.h"
#include "PlainText.h"

namespace VOB
{
	namespace Auth
	{

		PlainText::PlainText()
		{
		}


		PlainText::~PlainText()
		{
		}

		bool PlainText::CheckPassword(const User &user, const string &password) const
		{
			return user.GetPassword() == password;
		}

		void PlainText::SetPassword(User &user, const string &password) const
		{
			user.SetPassword(password);
		}

	}
}