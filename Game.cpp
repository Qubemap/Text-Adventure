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

//function to move the player
void Game::Move(Player& player, String args)
{
	/*
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
	*/

}

//function to get the first word of a string
String Game::GetCommand(String input)
{
	String firstWord;
	for (int i = 0; i < input.Length(); i++)
	{
		if (input[i] == ' ')
		{
			break;
		}
		else
		{
			firstWord.Append(input[i]);
		}
	}
	return firstWord;
}

//function to get the arguments of a string
String Game::GetArgs(String input)
{
	String args;
	bool foundSpace = false;
	for (int i = 0; i < input.Length(); i++)
	{
		if (foundSpace)
		{
			args.Append(input[i]);
		}
		if (input[i] == ' ')
		{
			foundSpace = true;
		}
	}
	return args;
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
		//get player input
		std::cout << ">";
		String input;
		input.ReadFromConsole();

		String command = GetCommand(input);
		String args = GetArgs(input);
		
	}
}



