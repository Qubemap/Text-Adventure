#ifndef SPELL_HPP
#define SPELL_HPP

#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "String.hpp"


class Spell
{
public:
	//Constructors
	Spell();
	Spell(String name);

	//Destructor
	~Spell();

	//Functions
	//void Cast(Player* player);

	//overloaded operators
	bool operator==(const Spell& spell) const;
	bool operator<(const Spell& spell) const;



	//Variables
	String name;


	
};

#endif