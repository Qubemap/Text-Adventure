#include <iostream>
#include "BoxOfDonuts.hpp"

//Default constructor
BoxOfDonuts::BoxOfDonuts()
{
	std::cout "BoxOfDonuts created" << std::endl;

	amountOfDonuts = 6;
}

//destructor
BoxOfDonuts::~BoxOfDonuts()
{
	std::cout "BoxOfDonuts destroyed" << std::endl;
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

void BoxOfDonuts::Description()
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