#ifndef FARMANIMAL_H
#define FARMANIMAL_H

class FarmAnimal
{
private:
	double water_consumption;
public:
	FarmAnimal ( double water_consumption );
	double getWaterConsumption ( void );
	void setWaterConsumption ( double new_water_consumption );
};

#endif /* FARMANIMAL_H */
