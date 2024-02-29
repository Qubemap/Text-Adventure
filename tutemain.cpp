
#include <iostream>
#include <vector>
#include <algorithm>


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


void otheruse()
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


int binary_search(int array[], int start_index, int end_index, int key)
{
	while (start_index <= end_index)
	{
		int pivot = (start_index + end_index) / 2;
		if (array[pivot] == key)
		{
			return pivot;
		}
		if (key < array[pivot])
		{
			end_index = pivot - 1;
		}
		else
		{
			start_index = pivot + 1;
		}
	}
	return -1;
}

int nouse()
{
	const int array_size = 25;
	int array_to_be_sorted[array_size] = {
		14,65,63,1,54,
		89,84,9,98,57,
		71,18,21,84,69,
		28,11,83,13,42,
		64,58,78,82,13
	};

	std::sort(&array_to_be_sorted[0], &array_to_be_sorted[array_size]);

	while (true)
	{
		std::cout << std::endl << std::endl << "ENter a number to find in the sequence: -1 to end" << std::endl;
		int search_key = -1;
		std::cin >> search_key;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (search_key == -1)
			break;

		int r = binary_search(array_to_be_sorted, 0, array_size - 1, search_key);
		if (r == -1)
			std::cout << "Couldn't find " << search_key << " in the list" << std::endl;
		else
			std::cout << "Found " << search_key << " at position " << r << std::endl;
	}
	return 0;
}