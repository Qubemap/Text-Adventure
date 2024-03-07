#ifndef BOXOFDONUTS_HPP
#define BOXOFDONUTS_HPP

#include "Item.hpp"

class BoxOfDonuts : public Item
{
public:
	
	//Constructors
	BoxOfDonuts();

	//Destructor
	~BoxOfDonuts();

	//Functions
	void Description() const;
	void Use();

	//Variables

	int amountOfDonuts;


};

#endif