#include <iostream>
#include "Room.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Item.hpp"
#include "BoxOfDonuts.hpp"

//constructor

Game::Game()
{
	std::cout << "Game constructor" << std::endl;"
}

//destructor

Game::~Game()
{
	std::cout << "Game destructor" << std::endl;
}

//function to start the game

void Game::startGame()
{
	//create the items
	BoxOfDonuts donuts;



