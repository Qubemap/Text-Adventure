
#include <iostream>
#include <vector>


class Entity
{
public:
	Entity() {};
	virtual ~Entity() {};

	virtual void attack() = 0;
};

class Warrior : public Entity
{
public:
	Warrior() {};
	virtual ~Warrior() {};

	virtual void attack() = 0;
};

class Ranger : public Warrior
{
public:
	Ranger() {};
	~Ranger() {};

	void attack() { std::cout << "Back, foul beast" << std::endl; }
};

class Paladin : public Warrior {
public:
	Paladin() {};
	~Paladin() {};

	void attack() { std::cout << "For Honor and Glory!" << std::endl; }
};

class Wizard : public Entity {
public:
	Wizard() {};
	~Wizard() {};

	void attack() { std::cout << "You shall not pass!" << std::endl; }
	void heal() { std::cout << "You are revived" << std::endl; }
};

/*
void main()
{
	std::vector<Entity*> fighters;

	fighters.push_back(new Paladin());
	fighters.push_back(new Ranger());
	fighters.push_back(new Wizard());

	for (Entity* fighter : fighters)
	{
		fighter->attack();

		Wizard* wiz = dynamic_cast<Wizard*>(fighter);
		if (wiz != nullptr)
		{
			wiz->heal();
		}
	}
	std::cin.get();
}
*/