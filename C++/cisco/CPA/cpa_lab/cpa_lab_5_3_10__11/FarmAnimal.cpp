#include "FarmAnimal.h"

FarmAnimal::FarmAnimal ( double water_consumption )
{
	this -> water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption ( void )
{
	return this -> water_consumption;
}

void FarmAnimal::setWaterConsumption ( double new_water_consumption )
{
	this -> water_consumption = new_water_consumption;
}
