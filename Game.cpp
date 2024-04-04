#include <iostream>
#include <string>
#include "Room.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Item.hpp"
#include "BoxOfDonuts.hpp"
#include "Lamp.hpp"
#include "String.hpp"
#include "Cat.hpp"
#include <vector>
#include <algorithm>
#include "Spell.hpp"

//constructor

Game::Game()
{
	
}

//destructor

Game::~Game()
{
	
}

//binary search function to find a spell
std::vector<Spell>::iterator Game::binarySearch(const String& name)
{
	int start_index = 0;
	int end_index = spells.size() - 1;

	while (start_index <= end_index)
	{
		int pivot = (start_index + end_index) / 2; 
		if (spells[pivot].name == name) // found it!
		{
			return spells.begin() + pivot;
		}
		else if (name < spells[pivot].name) // search left
		{
			end_index = pivot - 1;
		}
		else // search right
		{
			start_index = pivot + 1;
		}
	}
	return spells.end(); // Not found. returns one position past the end of the vector.
}

bool Game::compareSpells(const Spell& a, const Spell& b)
{
	return a.name < b.name; //sorts the spells alphabetically, by comparing the names of the spells using the overloaded < operator.
}

//function to run the game
void Game::Run()
{
	//create the player
	Player player;

	//create the rooms
	Room room1("Dungeon Cell", "You are in a damp cold cell. Light trickles in through a barred window.");
	Room room2("Dungeon Hall", "A long hallway.");
	Room room3("Castle Courtyard", "A large open area with a fountain in the center.");
	Room room4("Crypt", "A dark room with a stone sarcophagus in the center.");

	//create directions
	room1.SetNorth(&room2);
	room2.SetSouth(&room1);
	room2.SetEast(&room3);
	room3.SetWest(&room2);
	room2.SetWest(&room4);
	room4.SetEast(&room2);

	//create spell book
	spells.push_back(Spell("eclipse")); //fun fact, for a while some of my test cases started with a capital letter
	spells.push_back(Spell("eruption")); //issue is, i made the search tolowered
	spells.push_back(Spell("levitate")); //making it fucking impossible to find these
	spells.push_back(Spell("mirage")); //Took an unreasonable amount of time to figure out
	spells.push_back(Spell("petrify"));
	spells.push_back(Spell("frostbite"));
	spells.push_back(Spell("polymorph"));
	spells.push_back(Spell("teleport"));
	spells.push_back(Spell("thunderwave"));
	spells.push_back(Spell("vortex"));

	std::sort(spells.begin(), spells.end(), Game::compareSpells); //I had to make compareSpells static

	//set items in rooms
	Item* item = new BoxOfDonuts();
	BoxOfDonuts* bod = dynamic_cast<BoxOfDonuts*>(item);
	room1.SetItem(bod);

	Item* item2 = new Lamp();
	Lamp* lamp = dynamic_cast<Lamp*>(item2);
	room2.SetItem(lamp);

	Item* item3 = new Cat();
	Cat* cat = dynamic_cast<Cat*>(item3);
	room3.SetItem(cat);

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
		else if (input.Find("cast") != -1)
		{
			std::cout << "what spell would you like to cast?" << std::endl;
			String spellName;
			spellName.ReadFromConsole();
			spellName.ToLower();
			std::vector<Spell>::iterator it = binarySearch(spellName.CStr());
			if (it != spells.end())
			{
				std::cout << "You cast " << it->name.CStr() << std::endl;
			}
			else
			{
				std::cout << "Klaatu... Barada... Necktie. You don't know that spell" << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid input. Try 'Move (direction)', 'use', 'look', 'cast' or 'quit'." << std::endl;
		}

		std::cout << std::endl;
		
	}

	delete item;
	delete item2;
	delete item3;
}



