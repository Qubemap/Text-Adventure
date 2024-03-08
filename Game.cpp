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
	
	Room room1("Dungeon Cell", "You are in a damp cold cell. Light trickles in through a barred window.");
	Room room2("Dungeon Hall", "A long hallway.");

	

	room1.SetNorth(&room2);
	

	room2.SetSouth(&room1);

}



