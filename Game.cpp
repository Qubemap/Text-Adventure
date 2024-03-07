#include <iostream>
#include "Room.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Item.hpp"
#include "BoxOfDonuts.hpp"
#include "String.hpp"

//constructor

Game::Game()
{
	std::cout << "Game constructor" << std::endl;
}

//destructor

Game::~Game()
{
	std::cout << "Game destructor" << std::endl;
}

//function to start the game

void Game::Init()
{
	//create the items
	BoxOfDonuts donuts;

	//create the rooms
	String name("Dungeon Cell");
	String description("You are in a dark, damp cell. There is a door to the north."); // !!!! There has got to be a better way of doing this
	Room room1(name, description);

	String name2("Dungeon Hallway");
	String description2("You are in a long, dark hallway. There are doors to the north and south.");
	Room room2(String str1("Dungeon Hallway"), String str2("You are in a long, dark hallway. There are doors to the north and south."));

	room1.SetNorth(&room2);
	

	room2.SetSouth(&room1);

}



