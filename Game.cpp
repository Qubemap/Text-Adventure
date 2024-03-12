#include <iostream>
#include <string>
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


//function to run the game

void Game::Run()
{
	//create the player
	Player player;

	//create the rooms
	Room room1("Dungeon Cell", "You are in a damp cold cell. Light trickles in through a barred window.");
	Room room2("Dungeon Hall", "A long hallway.");

	//create directions
	room1.SetNorth(&room2);
	room2.SetSouth(&room1);

	BoxOfDonuts bod;
	room1.SetItem(&bod);

	//set the player's starting room
	player.Move(&room1);

	//game loop
	bool isRunning = true;
	while (isRunning)
	{
		//get player input
		std::cout << ">";
		String input;
		input.ReadFromConsole();

		//move the player
		if (input == "move north")
		{
			if (player.currentRoom->north != NULL)
			{
				player.Move(player.currentRoom->north);
			}
			else
			{
				std::cout << "You can't go that way" << std::endl;
			}
		}
		else if (input == "move south")
		{
			if (player.currentRoom->south != NULL)
			{
				player.Move(player.currentRoom->south);
			}
			else
			{
				std::cout << "You can't go that way" << std::endl;
			}
		}
		else if (input == "move east")
		{
			if (player.currentRoom->east != NULL)
			{
				player.Move(player.currentRoom->east);
			}
			else
			{
				std::cout << "You can't go that way" << std::endl;
			}
		}
		else if (input == "move west")
		{
			if (player.currentRoom->west != NULL)
			{
				player.Move(player.currentRoom->west);
			}
			else
			{
				std::cout << "You can't go that way" << std::endl;
			}
		}
		else if (input == "look")
		{
			player.currentRoom->Description();
		}
		else if (input == "use")
		{
			if (player.currentRoom->item != NULL)
			{
				player.currentRoom->item->Use();
			}
			else
			{
				std::cout << "There is nothing to use" << std::endl;
			}
		}
		else if (input == "quit")
		{
			isRunning = false;
		}
	}
}



