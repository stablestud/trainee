#ifndef CONSUMPTIONACCUMULATOR_H
#define CONSUMPTIONACCUMULATOR_H

class ConsumptionAccumulator
{
private:
	double total_consumption;
public:
	ConsumptionAccumulator ( void );
	double getTotalConsumption ( void );
	void addConsumption ( FarmAnimal animal );
};

#endif /* CONSUMPTIONACCUMULATOR_H */
