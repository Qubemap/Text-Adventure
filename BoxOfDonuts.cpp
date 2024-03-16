#include <iostream>
#include "BoxOfDonuts.hpp"
#include "Item.hpp"

//Default constructor
BoxOfDonuts::BoxOfDonuts()
{
	amountOfDonuts = 6;
	name = "Box of Donuts";
}

//destructor
BoxOfDonuts::~BoxOfDonuts()
{

}

//function

void BoxOfDonuts::Use()
{
	if (amountOfDonuts == 0)
	{
		std::cout << "The box is empty" << std::endl;
		return;
	}
	std::cout << "You eat a donut" << std::endl;
	amountOfDonuts--;
}

void BoxOfDonuts::Description() const 
{
	if (amountOfDonuts == 0)
	{
		std::cout << "There is an empty box of donuts here." << std::endl;
		return;
	}
	else if (amountOfDonuts == 1)
	{
		std::cout << "There is a box of donuts here. There is 1 donut left" << std::endl;
		return;
	}
	std::cout << "There is a box of donuts here. There are " << amountOfDonuts << " donuts left" << std::endl;
}