#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "String.hpp"
#include "Player.hpp"

class Game
{
public:

	//Constructors
	Game();

	//Destructor
	~Game();

	//Functions
	void Move(Player& player, String direction);
	String GetCommand(String Input);
	String GetArgs(String args);
	void Run();
};

#endif