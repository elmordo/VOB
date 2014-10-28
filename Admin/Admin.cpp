// Admin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include <Auth\UserManager.h>
#include <Auth\Encrypted.h>
#include <Auth\PlainText.h>

#include <GameData\RoomManager.h>
#include <GameData\Player.h>

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

typedef Room* RoomPtr;
typedef Door* DoorPtr;

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

	// create room manager and try to create some rooms
	RoomManager rm;
	RoomPtr startRoom = rm.CreateRoom("Start room", "This is the room, where players start"),
		secondRoom = rm.CreateRoom("Second room", "This is the second room where player can go from start room"),
		lastRoom = rm.CreateRoom("Last room", "Final room, what player can reach");

	// link rooms by some doors
	DoorPtr start2Second = startRoom->CreateDoor(secondRoom, "Door to second room"),
		second2last = secondRoom->CreateDoor(lastRoom, "This is the door to last room in this game");

	// create player
	Player player("Kral Ja I.", startRoom);

	// try to go to the last room
	try
	{
		player.Transit(second2last);
	}
	catch (TransitException &e)
	{
		cout << "We can not go to the last room from the first one";
	}

	// try to go to the second room
	player.Transit(start2Second);

	// wait for one character
	cin.get();

	return 0;
}

