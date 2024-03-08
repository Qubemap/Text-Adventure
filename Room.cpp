#include <iostream>
#include "Room.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Item.hpp"


//constructor
Room::Room()
{
	name = "Room";
	description = "This is a room";
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
	item = NULL;

}

Room::Room(const char* name, const char* description)
{
	this->name = name;
	this->description = description;
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;
	this->item = NULL;
}
//destructor
Room::~Room()
{

}

//Functions
void Room::SetNorth(Room* room)
{
	this->north = room;
}

void Room::SetSouth(Room* room)
{
	this->south = room;
}

void Room::SetEast(Room* room)
{
	this->east = room;
}

void Room::SetWest(Room* room)
{
	this->west = room;
}

void Room::SetItem(Item* item)
{
	this->item = item;
}

void Room::Description()
{
	std::cout << name.CStr() << std::endl;
	std::cout << description.CStr() << std::endl;
	if (item != NULL)
	{
		std::cout << "There is a " << item->name.CStr() << " here." << std::endl;
	}
	if (north != NULL)
	{
		std::cout << "There is a door to the north." << std::endl;
	}
	if (south != NULL)
	{
		std::cout << "There is a door to the south." << std::endl;
	}
	if (east != NULL)
	{
		std::cout << "There is a door to the east." << std::endl;
	}
	if (west != NULL)
	{
		std::cout << "There is a door to the west." << std::endl;
	}
}

