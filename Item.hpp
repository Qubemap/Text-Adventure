#ifndef ITEM_HPP
#define ITEM_HPP

#include "Game.hpp"

class Item
{
public:
	virtual void Description() const = 0;
	virtual void Use() = 0;
};

#endif