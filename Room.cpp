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

}

Room::Room(String name, String description)
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

