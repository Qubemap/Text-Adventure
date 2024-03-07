#define PLAYER_HPP
#ifndef PLAYER_HPP

#include <iostream>
#include "Game.hpp"

class Player
{

	public:

	//Constructors
	Player();
	Player(std::string name, std::string description, Room* currentRoom);

	//Destructor
	~Player();

	//Functions
	void Description() const;

	//Variables
	std::string name;
	std::string description;
	Room* currentRoom;
};


#endif