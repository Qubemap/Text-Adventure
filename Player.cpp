#include <iostream>
#include "Player.hpp"
#include "Room.hpp"
#include "Game.hpp"
//constructor

Player::Player()
{
	currentRoom = NULL;
}

//destructor

Player::~Player()
{
	
}

//function to move the player
void Player::Move(Room* room)
{
	currentRoom = room;
	room->Description();
}
