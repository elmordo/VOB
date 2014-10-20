#include "stdafx.h"
#include "UserManager.h"

namespace VOB
{
	namespace Auth
	{

		UserManager::UserManager()
		{
			policy = 0x0;
		}


		UserManager::~UserManager()
		{
			// delete password policy
			SetPolicy(0x0);
		}

		User &UserManager::CreateUser(const string &login, const string &password, const string &name)
		{
			// if user not exists, it is ok
			if (UserExists(login)) throw UserManagerException("Login exists", 2);

			// password policy has to be set
			if (policy == 0x0) throw UserManagerException("Password policy is not set", 3);

			// create new user
			User user(login, name);

			policy->SetPassword(user, password);
			users[login] = user;

			return users[login];
		}

		bool UserManager::UserExists(const string &login) const
		{
			// see documentation if std::map
			return users.find(login) != users.end();
		}

		User &UserManager::FindUser(const string &login)
		{
			strinctLoginCheck(login);
			return users[login];
		}

		const User &UserManager::FindUser(const string &login) const
		{
			strinctLoginCheck(login);
			return users.find(login)->second;
		}

		PasswordPolicy *UserManager::GetPolicy() const
		{
			return policy;
		}

		void UserManager::SetPolicy(PasswordPolicy *policy)
		{
			// destroy policy if it is not 0x0
			if (this->policy != 0x0) delete this->policy;

			this->policy = policy;
		}

	}
}
