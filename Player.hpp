#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "Game.hpp"
#include "Room.hpp"

class Room;

class Player
{

	public:

	//Constructors
	Player();

	//Destructor
	~Player();

	//Functions
	void Move(Room* room);
	
	//spells stuff here 

	//Variables
	Room* currentRoom;


};


#endif