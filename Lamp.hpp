#ifndef LAMP_HPP
#define LAMP_HPP

#include "Item.hpp"
#include "Game.hpp"

class Lamp : public Item
{
public:
	//Constructors
	Lamp();

	//Destructor
	~Lamp();

	//Functions
	void Description() const override;
	void Use() override;

	//Variables

	bool isOn;

};

#endif