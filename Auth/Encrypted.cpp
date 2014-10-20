#include "stdafx.h"
#include "Encrypted.h"

namespace VOB
{
	namespace Auth
	{

		Encrypted::Encrypted()
		{
		}


		Encrypted::~Encrypted()
		{
		}

		string Encrypted::hashPassword(const string &password, const string &salt)
		{
			int saltPos = 0;
			string encrypted;

			for (int i = 0; i < password.size(); ++i, ++saltPos)
			{
				if (saltPos == salt.size()) saltPos = 0;

				int pswChar = password[i],
					saltChar = salt[saltPos];

				encrypted += (char)((pswChar + saltChar) % 256);
			}

			return encrypted;
		}

		bool Encrypted::CheckPassword(const User &user, const string &password) const 
		{
			// hash password and compare it with string in instance
			return user.GetPassword() == hashPassword(password, user.GetSalt());
		}

		void Encrypted::SetPassword(User &user, const string &password) const
		{
			// hash password
			string encrypted = hashPassword(password, user.GetSalt());

			// set it into instance
			user.SetPassword(encrypted);
		}

	}
}