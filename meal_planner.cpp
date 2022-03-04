// meal_planner.cpp : Defines the entry point for the application.
//
// system includes
#include <iostream>
#include <array>
#include <random>

// project includes
#include "meal_planner.h"

// string array for vegatable options
std::array <std::string, 4> vegatable_options = 
{
	"Carrots",
	"Green beans",
	"Snap peas",
	"Asparagus"
};


// string array for meat option
std::array <std::string, 6> meat_options =
{
	"Chicken",
	"Beef",
	"Steak",
	"Pork chops",
	"Fish",
	"Bulgogi"
};

// string array for dessert option
std::array <std::string, 5> dessert_options =
{
	"Cheesecake",
	"Chocolate cake",
	"Ice cream",
	"Blueberry pie",
	"Chocolate chip cookies"
};



std::array <int, vegatable_options.size()> vegatable_options_count =
{
	0
};

std::array <int, meat_options.size()> meat_options_count =
{
	0
};


std::array <int, dessert_options.size()> dessert_options_count =
{
	0
};

// Constants
constexpr int NUMBER_OF_MEALS = 7; // number of meals you want to create

int main()
{
	// Display welcome message
	std::cout << "Welcome to the meal planner!" << std::endl;

	// set up randomizer
	std::random_device dev;
	std::mt19937 rng(dev());

	// create distributions for each food time
	std::uniform_int_distribution<std::mt19937::result_type> meat_randomizer(0, meat_options.size() - 1);
	std::uniform_int_distribution<std::mt19937::result_type> vegatable_randomizer(0, vegatable_options.size() - 1); 	
	std::uniform_int_distribution<std::mt19937::result_type> dessert_randomizer(0, dessert_options.size() - 1); 

	// declare variables to store random items 
	int random_vegatable; 
	int random_meat;
	int random_dessert;

	// read out the random meal to the user
	for (int current_meal = 0; current_meal < NUMBER_OF_MEALS; current_meal++)
	{
		random_vegatable = vegatable_randomizer(rng);
		random_meat = meat_randomizer(rng);
		random_dessert = dessert_randomizer(rng); 
		
		std::cout << "Veggie " << current_meal + 1 << ": " << vegatable_options[random_vegatable] << std::endl;
		std::cout << "Meat " << current_meal + 1 << ": " << meat_options[random_meat] << std::endl;
		std::cout << "Dessert " << current_meal + 1 << ": " << dessert_options[random_dessert] << std::endl;
		std::cout << std::endl;

		// add each item to the shopping list
		vegatable_options_count[random_vegatable] = vegatable_options_count[random_vegatable] + 1; 
		meat_options_count[random_meat] = meat_options_count[random_meat] + 1;
		dessert_options_count[random_dessert] = dessert_options_count[random_dessert] + 1;

	}

	// display shopping list
	std::cout << "Shopping list" << std::endl;
	std::cout << "~~~~~~~~~~~~~" << std::endl;
	std::cout << "Vegatables: " << std::endl;
	
	for (int current_vegatable = 0; current_vegatable < vegatable_options.size(); current_vegatable++)
	{
		if (vegatable_options_count[current_vegatable] > 0)
		{
			std::cout << "-- " << vegatable_options_count[current_vegatable] << " " << vegatable_options[current_vegatable] << std::endl;
		}
	}

	std::cout << std::endl << "Meats: " << std::endl;
	for (int current_meat = 0; current_meat < meat_options.size(); current_meat++)
	{
		if (meat_options_count[current_meat] > 0)
		{
			std::cout << "-- " << meat_options_count[current_meat] << " " << meat_options[current_meat] << std::endl;
		}
	}

	std::cout << std::endl << "Desserts: " << std::endl;
	for (int current_dessert = 0; current_dessert < dessert_options.size(); current_dessert++)
	{
		if (dessert_options_count[current_dessert] > 0)
		{
			std::cout << "-- " << dessert_options_count[current_dessert] << " " << dessert_options[current_dessert] << std::endl;
		}
	}


	return 0;
}
