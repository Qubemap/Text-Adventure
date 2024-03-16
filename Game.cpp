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
	
}

//destructor

Game::~Game()
{
	
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

	Item* item = new BoxOfDonuts();
	BoxOfDonuts* bod = dynamic_cast<BoxOfDonuts*>(item);
	room1.SetItem(bod);

	//set the player's starting room
	player.Move(&room1);

	//game loop
	bool isRunning = true;
	while (isRunning)
	{
		std::cout << std::endl;
		//get player input
		std::cout << ">";
		String input;
		input.ReadFromConsole();
		input.ToLower();

		//String command = GetCommand(input);
		//String args = GetArgs(input);

		if (input == "quit")
		{
			isRunning = false;
		}
		else if (input.Find("move") != -1)
		{
			if (input.Find("north") != -1)
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
			else if (input.Find("south") != -1)
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
			else if (input.Find("east") != -1)
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
			else if (input.Find("west") != -1)
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
			else
			{
				std::cout << "I don't understand" << std::endl;
			}
		}
		else if (input == "look")
		{
			std::cout << std::endl;
			player.currentRoom->Description();
		}
		else if (input.Find("use") != -1)
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
		else
		{
			std::cout << "I don't understand" << std::endl;
		}

		std::cout << std::endl;
		
	}
}



