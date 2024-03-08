#ifndef ITEM_HPP
#define ITEM_HPP

#include "Game.hpp"

class Item
{
public:

	//Constructors
	Item();

	Item(const char* name, const char* description);

	//Destructor
	~Item();


	//Functions
	virtual void Description() const;

	virtual void Use();

	//Variables
	String name;
	String description;
};

#endif