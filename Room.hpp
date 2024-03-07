#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include "Game.hpp"
#include "Item.hpp"

class Room
{
public:

	//Constructors
	Room();
	Room(String name, String description);


	//Destructor
	~Room();

	//Functions
	void Description() const;

	//Variables
	String name;
	String description;
	Room* north;
	Room* south;
	Room* east;
	Room* west;
	Item* item;

};



#endif