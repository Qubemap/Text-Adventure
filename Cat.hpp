#ifndef CAT_HPP
#define CAT_HPP

#include "Item.hpp"
#include "Game.hpp"

class Cat : public Item
{
public:

	Cat();
	~Cat();

	void Description() const override;
	void Use() override;

	bool ispurring;
};


#endif