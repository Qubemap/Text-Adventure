#include <iostream>
#include "Lamp.hpp"
#include "Item.hpp"

//Default constructor
Lamp::Lamp()
{
	isOn = false;
	name = "Lamp";
}

//destructor
Lamp::~Lamp()
{

}

//function

void Lamp::Use()
{
	if (isOn)
	{
		std::cout << "The lamp is now off" << std::endl;
		isOn = false;
	}
	else
	{
		std::cout << "The lamp is now on" << std::endl;
		isOn = true;
	}
}

void Lamp::Description() const
{
	if (isOn)
	{
		std::cout << "A lamp emits a soft glow." << std::endl;
	}
	else
	{
		std::cout << "There is a lamp here." << std::endl;
	}
}