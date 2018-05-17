#include <iostream>
#include "FarmAnimal.h"
#include "DummyAnimal.h"
#include "DoublingAnimal.h"

void printConsumption ( FarmAnimal animal );

int main ( void )
{
	FarmAnimal animalA ( 5 );
	DummyAnimal animalB;
	DoublingAnimal animalC ( 21 );

	std::cout << "animalA consumes " << animalA.getWaterConsumption() << " liters of water." << std::endl;
	std::cout << "What about the others?" << std::endl;

	printConsumption ( animalB );
	animalB.setWaterConsumption ( 100 );
	printConsumption ( animalB );
	printConsumption ( animalC );

	return 0;
}

void printConsumption ( FarmAnimal animal )
{
	std::cout << "This animal consumes " << animal.getWaterConsumption()
	<< " liters of water" << std::endl;
}
