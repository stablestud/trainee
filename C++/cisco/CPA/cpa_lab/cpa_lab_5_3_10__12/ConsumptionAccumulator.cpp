#include "FarmAnimal.h"
#include "ConsumptionAccumulator.h"

ConsumptionAccumulator::ConsumptionAccumulator ( void )
{
	this -> total_consumption = 0;
}

double ConsumptionAccumulator::getTotalConsumption ( void )
{
	return this -> total_consumption;
}

void ConsumptionAccumulator::addConsumption ( FarmAnimal animal )
{
	this -> total_consumption += animal.getWaterConsumption();
}
