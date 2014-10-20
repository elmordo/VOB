#pragma once

#include <map>
#include <string>

#include "User.h"
#include "PasswordPolicy.h"

#include <Utils/Exception.h>

using namespace std;

namespace VOB
{
	namespace Auth
	{

		VOB_CREATE_EXCEPTION_EXPORTABLE(UserManagerException, VOB::Utils::Exception);

		class DllExport UserManager
		{

			/* list of users */
			map<string, User> users;

			/* password policy to password hash */
			PasswordPolicy *policy;

			/*
			if user with login does not exists, throw exception
			*/
			inline void strinctLoginCheck(const string &login) const
			{
				if (users.find(login) == users.end())
				{
					// throw exception
					throw UserManagerException("Åogin not found", 1);
				}
			}

		public:
			/*
			create new manager
			*/
			UserManager();

			/*
			destroy manager
			*/
			virtual ~UserManager();

			/*
			create new user and add it to manager
			password is hashed by current password policy
			return reference on new user
			*/
			User &CreateUser(const string &login, const string &password, const string &name = "");

			/*
			return true if user with given login exists
			*/
			bool UserExists(const string &login) const;

			/*
			find user for editation
			if user was not found, throw exception
			*/
			User &FindUser(const string &login);

			/*
			find user by login for read only
			if user was not found, throw exception
			*/
			const User &FindUser(const string &login) const;

			/*
			return password policy
			*/
			PasswordPolicy *GetPolicy() const;

			/*
			set new policy to instance
			policy is destroyed when new policy is set or instance of manager is destroyed
			*/
			void SetPolicy(PasswordPolicy *policy);

		};

	}
}