#include "Spell.hpp"
#include "String.hpp"
#include <iostream>

Spell::Spell()
{
	name = "Spell";
}

Spell::Spell(String name)
{
	this->name = name;
}

Spell::~Spell()
{
	
}

bool Spell::operator==(const Spell& spell) const
{
	return this->name == spell.name;
}

bool Spell::operator<(const Spell& spell) const
{
	return this->name < spell.name;
}

