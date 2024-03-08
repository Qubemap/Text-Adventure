#include "Item.hpp"
#include <iostream>
#include "Game.hpp"
#include "String.hpp"

Item::Item()
{
	name = "Item";
	description = "This is an item";
}

Item::Item(const char* name, const char* description)
{
	this->name = name;
	this->description = description;
}

Item::~Item()
{

}

void Item::Description() const
{
	std::cout << description.CStr() << std::endl;
}

void Item::Use()
{
	std::cout << "You use the " << name.CStr() << std::endl;
}

