#ifndef BOXOFDONUTS_HPP
#define BOXOFDONUTS_HPP

#include "Item.hpp"

class BoxOfDonuts : public Item
{
public:
	
	//Constructors
	BoxOfDonuts();

	//Functions
	void Description() const;
	void Use();


};

#endif