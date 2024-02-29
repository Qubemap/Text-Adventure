#define ENTITY_HPP
#ifndef ENTITY_HPP

#include <iostream>

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

	virtaul void attack() = 0;
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
