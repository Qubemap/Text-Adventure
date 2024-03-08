#include <iostream>
#include "BoxOfDonuts.hpp"
#include "Item.hpp"

//Default constructor
BoxOfDonuts::BoxOfDonuts()
{
	amountOfDonuts = 6;
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
		std::cout << "An empty box of donuts" << std::endl;
		return;
	}
	else if (amountOfDonuts == 1)
	{
		std::cout << "A box of donuts. There is " << amountOfDonuts << " donut left" << std::endl;
		return;
	}
	std::cout << "A box of donuts. There are " << amountOfDonuts << " donuts left" << std::endl;
}