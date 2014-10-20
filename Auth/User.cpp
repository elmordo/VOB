#include "stdafx.h"
#include "User.h"

namespace VOB
{
	namespace Auth {

		const string User::ALNUMS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

		const int User::SALT_LENGTH = 40;

		User::User()
		{
			createSalt();
		}

		User::User(string login, string name) 
		{
			this->login = login;
			this->name = name;
			createSalt();
		}

		User::User(const User &other)
		{
			// call assign operator with same functionality (DRY)
			operator=(other);
		}


		User::~User()
		{
		}

		const string &User::GetLogin() const
		{
			return login;
		}

		const string &User::GetName() const
		{
			return name;
		}

		void User::SetName(const string &name)
		{
			this->name = name;
		}

		const string &User::GetPassword() const
		{
			return password;
		}

		void User::SetPassword(const string &password)
		{
			this->password = password;
		}

		const string &User::GetSalt() const 
		{
			return salt;
		}

		void User::createSalt()
		{
			// initiate random generator by current time
			time_t currTime;
			time(&currTime);

			srand(currTime);

			// generate salt
			salt.clear();

			for (int i = 0; i < SALT_LENGTH; ++i)
			{
				size_t charPosition = rand() % ALNUMS.size();
				char c = ALNUMS[charPosition];
				salt += c;
			}
		}

		User &User::operator =(const User &other)
		{
			name = other.name;
			login = other.login;
			password = other.password;
			salt = other.salt;

			return *this;
		}

	}
}
