#ifndef ITEM_HPP
#define ITEM_HPP

#include "Game.hpp"

class Item
{
public:

	//Functions
	virtual void Description() const;

	virtual void Use();
};

#endif