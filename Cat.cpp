#include "Cat.hpp"
#include "Game.hpp"
#include "Item.hpp"

Cat::Cat()
{
	name = "Cat";
	ispurring = false;
}

Cat::~Cat()
{

}

void Cat::Use()
{
	if (ispurring == false)
	{
		std::cout << "The cat rolls over for belly rubs :3" << std::endl;
		ispurring = true;
	}

}

void Cat::Description() const
{
	if (ispurring == true)
	{
		std::cout << "There is a cat here. The cat is purring." << std::endl;
	}
	else
	{
		std::cout << "There is a cat here." << std::endl;
	}
}