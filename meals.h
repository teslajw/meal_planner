
#include <iostream>
#include <string>

// This file contains the meals class
class meals
{
private:
    std::string meal_name; // name of the meal 
    int num_calories; //number of calories in the meal 
    int min_prep_time; // how long the recipe takes to make, start to finish (in minutes)
    int min_cook_time; // how long the recipe takes to cook (in minutes)
public:
    meals(std::string, int, int, int);
    ~meals();
};

meals::meals(std::string name, int number_calories, int prep_time, int cook_time )
{
    
}

meals::~meals()
{
}
