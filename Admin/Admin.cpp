// Admin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include <Auth\UserManager.h>
#include <Auth\Encrypted.h>
#include <Auth\PlainText.h>

#include <GameData\RoomManager.h>

using namespace VOB::Auth;
using namespace VOB::GameData;
using namespace std;

void testManager(UserManager &manager)
{
	manager.CreateUser("user1", "psw1", "Ja kral prvni");
	manager.CreateUser("user2", "psw2", "Ja kral prvni");

	// should print number 1 (True)
	cout << manager.UserExists("user1") << endl;

	// should print number 0 (False)
	cout << manager.UserExists("user66") << endl;

	User &user = manager.FindUser("user1");

	cout << "Password stored in instance of user 1 is: " << user.GetPassword() << endl;

	cout << "Test valid password: " << manager.GetPolicy()->CheckPassword(user, "psw1") << endl;
	cout << "Test invalid password: " << manager.GetPolicy()->CheckPassword(user, "ps666661") << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{

	UserManager managerPlain, managerEncrypted;
	
	PlainText *plain = new PlainText();
	Encrypted *enc = new Encrypted();

	managerPlain.SetPolicy(plain);
	managerEncrypted.SetPolicy(enc);

	cout << "Testing plain text " << endl;
	testManager(managerPlain);

	cout << "Testing encrypted test" << endl;
	testManager(managerEncrypted);

	// create room manager and try to create two rooms and connect them by door
	RoomManager rm;
	Room *r1 = rm.CreateRoom(), *r2 = rm.CreateRoom();
	r1->SetName("Room 1");

	Door *d = r1->CreateDoor(r2);


	// wait for one character
	cin.get();

	return 0;
}

