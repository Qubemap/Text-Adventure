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
}

