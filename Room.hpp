#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include "Game.hpp"
#include "Item.hpp"

class Item;

class Room
{
public:

	//Constructors
	Room();
	Room(const char* name, const char* description);


	//Destructor
	~Room();

	//Functions
	void Description();
	void SetItem(Item* item);
	void SetNorth(Room* room);
	void SetSouth(Room* room);
	void SetEast(Room* room);
	void SetWest(Room* room);

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