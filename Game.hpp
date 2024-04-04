#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "String.hpp"
#include "Player.hpp"
#include "Spell.hpp"
#include <vector>

class Player;
class Spell;

class Game
{
public:

	//Variables
	std::vector<Spell> spells;

	//Constructors
	Game();

	//Destructor
	~Game();

	//Functions
	void Move(Player& player, String direction);
	void Run();
	std::vector<Spell>::iterator binarySearch(const String& name);
	static bool compareSpells(const Spell& a, const Spell& b);


};

#endif